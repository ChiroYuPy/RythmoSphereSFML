//
// Created by adrian on 27/02/25.
//


#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include <map>
#include "Beatmap.h"

class Parser {
public:
    static Beatmap parse(const std::string& filePath);

private:
    static void parseFile(std::ifstream& file, std::map<std::string, std::string>& metadata,
                          std::vector<HitObjectData>& hitObjects, std::vector<TimingPoint>& timingPoints,
                          float& approachRate, float& overallDifficulty, float& circleSize);

    static void processLine(const std::string& line, std::ifstream& file, std::map<std::string, std::string>& metadata,
                            std::vector<HitObjectData>& hitObjects, std::vector<TimingPoint>& timingPoints,
                            float& approachRate, float& overallDifficulty, float& circleSize);

    static void parseHitObjects(std::ifstream& file, std::vector<HitObjectData>& hitObjects);
    static void parseTimingPoint(std::ifstream& file, std::vector<TimingPoint>& timingPoints);

    static std::string getValue(const std::string& line);
};

#endif // PARSER_H