//
// Created by adrian on 27/02/25.
//

#pragma once

#include <vector>
#include <string>

#ifndef BEATMAP_H
#define BEATMAP_H

struct HitObjectData {
    int x, y;
    int time;
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
            const std::vector<HitObjectData> &hitObjectData, const std::vector<TimingPoint> &timingPoints,
            float approachRate, float overallDifficulty, float circleSize);

    const std::string& getTitle() const;
    const std::string& getArtist() const;
    const std::string& getMapper() const;
    float getApproachRate() const;
    float getOverallDifficulty() const;
    float getCircleSize() const;

    int getAudioOffset() const;

    int getBeatmapStartTime() const;

    const std::vector<HitObjectData>& getHitObjects() const { return hitObjectData; }
    const std::vector<TimingPoint>& getTimingPoints() const { return timingPoints; };

private:
    std::string title;
    std::string artist;
    std::string mapper;

    float approachRate;
    float overallDifficulty;
    float circleSize;

    std::vector<HitObjectData> hitObjectData;
    std::vector<TimingPoint> timingPoints;
};

#endif //BEATMAP_H