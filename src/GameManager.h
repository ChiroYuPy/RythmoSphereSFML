//
// Created by adrian on 26/02/25.
//
#pragma once

#include "HitObject.h"
#include <SFML/Audio.hpp>
#include "Playground.h"

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H


class GameManager {
public:
	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;

	static GameManager& getInstance() {
		static GameManager instance;
		return instance;
	}

	void calculateHitWindow(const Beatmap &beatmap);
	void calculateHitObjectSize(const Beatmap &beatmap);

	float GetHitWindow() { return hitWindowOffset; };
	float GetHitObjectSize() { return hitObjectSize; };

	void loadGame(std::string filename);

	void update(float deltaTime);

	void render(sf::RenderWindow *window);

	void destroyHitObject();

	void destroyDeadHitObject();

	Playground& getPlayground() { return playground; };
	Beatmap getCurrentBeatmap() { return currentBeatmap; };

private:
	GameManager();
	~GameManager() = default;

	Playground playground;

	sf::Music music;

	void init();

	void loadBeatmap(const std::string &beatmapPath, const std::string &musicPath);

	void setBeatmapTime(int beatmapTime);

	void skipIntroduction();

	void spawnHitObject(HitObjectData data);

	int combo;
	int score;

	bool beatmapPlaying;
	bool musicPlaying;

	Beatmap currentBeatmap;

	std::vector<Beatmap *> beatmaps;
	std::vector<HitObjectData> hitObjectsData;

	float currentTimeMiliseconds;
	int skipStartReactionOffset;

	int hitWindowOffset;
	float hitObjectSize;
};


#endif //GAMEMANAGER_H
