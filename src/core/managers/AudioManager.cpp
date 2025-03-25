//
// Created by adrian on 05/03/25.
//

#include "../../../include/core/managers/AudioManager.h"

#include <iostream>

AudioManager::AudioManager(Game& game) : game(game), latency(sf::Time::Zero) {}

AudioManager::~AudioManager() {
    stop();
}

bool AudioManager::loadMusic(const std::string& filepath) {
    if (!music.openFromFile(filepath)) {
        std::cerr << "Erreur chargement musique : " << filepath << std::endl;
        return false;
    }
    return true;
}

void AudioManager::play() {
    music.play();
}

void AudioManager::pause() {
    music.pause();
}

void AudioManager::stop() {
    music.stop();
}

void AudioManager::setTime(const sf::Time time) {
    music.setPlayingOffset(time + latency);
}

sf::Time AudioManager::getTime() const {
    return music.getPlayingOffset() - latency;
}

void AudioManager::setLatency(sf::Time newLatency) {
    latency = newLatency;
}

void AudioManager::setVolume(float volume) {
    if (volume < 0.0f) volume = 0.0f;
    if (volume > 100.0f) volume = 100.0f;
    music.setVolume(volume);
}