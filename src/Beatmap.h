//
// Created by adrian on 27/02/25.
//

#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#ifndef BEATMAP_H
#define BEATMAP_H

#define HITCIRCLE  0x01  // 00000001
#define SLIDER     0x02  // 00000010
#define NEWCOMBO   0x04  // 00000100
#define SPINNER    0x08  // 00001000

struct HitObjectData {
    int x, y;
    int time;
    int type;
    int hitSound;
    std::string sliderData;
    int repeat = 0;
    float length = 0.0f;
    std::string extras;

    int comboNumber;

};


struct TimingPoint {
    int time;
    float bpm;
    int meter;
    int sampleSet;
    int sampleIndex;
    int volume;
    bool uninherited;
    bool kiaiMode;
};

class Beatmap {
public:
    Beatmap() = default;

    Beatmap(const std::string &title, const std::string &artist, const std::string &mapper,
            const std::vector<HitObjectData> &hitObjectData,
            const std::vector<sf::Color> &comboColors,
            const std::vector<TimingPoint> &timingPoints,
            float approachRate, float overallDifficulty, float circleSize);

    const std::string& getTitle() const;
    const std::string& getArtist() const;
    const std::string& getMapper() const;
    float getApproachRate() const;
    float getOverallDifficulty() const;
    float getCircleSize() const;

    int getAudioOffset() const;

    int getBeatmapStartTime() const;

    const std::vector<TimingPoint>& getTimingPoints() const { return timingPoints; };
    const std::vector<sf::Color>& getComboColors() const { return comboColors; };
    const std::vector<HitObjectData>& getHitObjects() const { return hitObjectData; }

private:
    std::string title;
    std::string artist;
    std::string mapper;

    float approachRate;
    float overallDifficulty;
    float circleSize;

    std::vector<TimingPoint> timingPoints;
    std::vector<sf::Color> comboColors;
    std::vector<HitObjectData> hitObjectData;
};

#endif //BEATMAP_H