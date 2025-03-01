#include "GameManager.h"
#include <iostream>
#include <vector>
#include <memory>
#include <random>

#include "HitObject.h"
#include "Parser.h"

GameManager::GameManager() : currentTimeMiliseconds(0), combo(0), score(0), hitObjectSize(0), hitWindowOffset(0),
musicPlaying(false), beatmapPlaying(false), skipStartReactionOffset(1000) {
    init();
}

void GameManager::calculateHitWindow(const Beatmap &beatmap) {
    float approachRate = beatmap.getApproachRate();

    if (approachRate < 5) {
        hitWindowOffset = static_cast<int>(1200 + 600 * (5 - approachRate) / 5);
    } else if (approachRate > 5) {
        hitWindowOffset = static_cast<int>(1200 - 750 * (approachRate - 5) / 5);
    } else {
        hitWindowOffset = 1200;
    }
}

void GameManager::calculateHitObjectSize(const Beatmap &beatmap) {
    float circleSize = beatmap.getCircleSize();

    hitObjectSize = 54.4f - 4.48f * circleSize;
}

void GameManager::init() {
    loadBeatmap("../beatmaps/Jashin/Imperial Circus Dead Decadence - Jashin no Konrei, Gi wa Ai to Shiru. (ItsWinter) [Zetsubou no Hana].osu", "../beatmaps/Jashin/audio.mp3");

    std::cout << "Game initialized!" << std::endl;

    calculateHitWindow(currentBeatmap);
    calculateHitObjectSize(currentBeatmap);
}

void GameManager::loadBeatmap(const std::string& beatmapPath, const std::string& musicPath) {
    Beatmap beatmap = Parser::parse(beatmapPath);
    currentBeatmap = beatmap;

    std::cout << "Beatmap created: " << beatmap.getTitle() << " by " << beatmap.getArtist() << std::endl;

    hitObjectsData.clear();  // Clear previous hit objects data

    for (const HitObjectData& data : beatmap.getHitObjects()) {
        std::cout << data.x << ", " << data.y << std::endl;
        hitObjectsData.push_back(data);
    }

    if (!music.openFromFile(musicPath)) { // Remplacer par le chemin du fichier audio
        std::cerr << "Erreur lors du chargement de la musique" << std::endl;
        return;
    }

    music.setLoop(true);
    musicPlaying = false;
    beatmapPlaying = false;
}

void GameManager::skipIntroduction() {
    int skipTime = currentBeatmap.getBeatmapStartTime() - (hitWindowOffset + skipStartReactionOffset);
    std::cout << "Introduction started!" << std::endl;
    if (skipTime > 0.0) {
        music.setPlayingOffset(music.getPlayingOffset() + sf::milliseconds(skipTime));
        currentTimeMiliseconds = static_cast<float>(skipTime);
    }
}

void GameManager::update(float deltaTime) {
    if (beatmapPlaying) {
        currentTimeMiliseconds += deltaTime * 1000;
    }

    // Démarrer la musique lorsque le temps audio dépasse l'offset
    if (currentBeatmap.getAudioOffset() < 0) {
        if (!beatmapPlaying) {
            beatmapPlaying = true;
        }
        if (currentTimeMiliseconds >= static_cast<float>(currentBeatmap.getAudioOffset()) && !musicPlaying) {
            music.play();
            musicPlaying = true;
            std::cout << currentTimeMiliseconds << std::endl;
            skipIntroduction();
        }
    } else {
        if (!musicPlaying) {
            music.play();
            musicPlaying = true;
        }
        if (currentTimeMiliseconds <= static_cast<float>(currentBeatmap.getAudioOffset()) && !beatmapPlaying) {
            beatmapPlaying = true;
            std::cout << currentTimeMiliseconds << std::endl;
            skipIntroduction();
        }
    }

    //std::cout << currentTimeMiliseconds << " " << music.getPlayingOffset().asMilliseconds() << std::endl;

    unsigned int size = currentBeatmap.getHitObjects().size();
    int i = 0;
    for (auto hitObjectData = hitObjectsData.begin(); hitObjectData != hitObjectsData.end(); ++hitObjectData, ++i) {
        if (hitObjectData->time - hitWindowOffset <= currentTimeMiliseconds and hitObjectData->time >= currentTimeMiliseconds and i < size) {
            playground.spawnHitObject(*hitObjectData);
            hitObjectsData.erase(hitObjectData);
        } else {
            break;
        }
    }

    for (auto it = playground.getObjects().begin(); it != playground.getObjects().end(); /* Pas d'incrémentation ici */) {
        HitObject *obj = *it;
        if (obj->data.time <= currentTimeMiliseconds) {
            delete obj;
            it = playground.getObjects().erase(it);
        } else {
            ++it;
        }
    }

    for (HitObject *obj : playground.getObjects()) {
        obj->update(deltaTime, currentTimeMiliseconds, hitWindowOffset, hitObjectSize);
    }
}

void GameManager::render(sf::RenderWindow *window) {
    playground.draw(window);
}
