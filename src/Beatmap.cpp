//
// Created by adrian on 27/02/25.
//

#include "Beatmap.h"

const std::string& Beatmap::getTitle() const { return title; }
const std::string& Beatmap::getArtist() const { return artist; }
const std::string& Beatmap::getMapper() const { return mapper; }
float Beatmap::getApproachRate() const { return approachRate; }
float Beatmap::getOverallDifficulty() const { return overallDifficulty; }
float Beatmap::getCircleSize() const { return circleSize; }

int Beatmap::getAudioOffset() const {
    if (timingPoints.empty()) return 0.0f;
    return timingPoints.front().time;
}

int Beatmap::getBeatmapStartTime() const {
    if (hitObjectData.empty()) return 0.0f;
    return hitObjectData.front().time;
}

Beatmap::Beatmap(const std::string& title, const std::string& artist, const std::string& mapper,
        const std::vector<HitObjectData>& hitObjectData,
        const std::vector<sf::Color>& comboColors,
        const std::vector<TimingPoint>& timingPoints,
        float approachRate, float overallDifficulty, float circleSize) {
    this->title = title;
    this->artist = artist;
    this->mapper = mapper;
    this->hitObjectData = hitObjectData;
    this->comboColors = comboColors;
    this->timingPoints = timingPoints;
    this->approachRate = approachRate;
    this->overallDifficulty = overallDifficulty;
    this->circleSize = circleSize;
}
