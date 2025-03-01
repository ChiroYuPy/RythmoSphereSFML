//
// Created by adrian on 27/02/25.
//

#include "Parser.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

Beatmap Parser::parse(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier osu");
    }

    std::map<std::string, std::string> metadata;
    std::vector<HitObjectData> hitObjectDatas;
    std::vector<TimingPoint> timingPoints;
    float approachRate = 0, overallDifficulty = 0, circleSize = 0;

    parseFile(file, metadata, hitObjectDatas, timingPoints, approachRate, overallDifficulty, circleSize);

    return Beatmap(metadata["Title"], metadata["Artist"], metadata["Creator"],
                   hitObjectDatas, timingPoints, approachRate, overallDifficulty, circleSize);
}

void Parser::parseFile(std::ifstream& file, std::map<std::string, std::string>& metadata,
                       std::vector<HitObjectData>& hitObjects, std::vector<TimingPoint>& timingPoints,
                       float& approachRate, float& overallDifficulty, float& circleSize) {
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        processLine(line, file, metadata, hitObjects, timingPoints, approachRate, overallDifficulty, circleSize);
    }
}

void Parser::processLine(const std::string& line, std::ifstream& file, std::map<std::string, std::string>& metadata,
                        std::vector<HitObjectData>& hitObjects, std::vector<TimingPoint>& timingPoints,
                         float& approachRate, float& overallDifficulty, float& circleSize) {
    if (line.find("Title:") == 0) metadata["Title"] = getValue(line);
    else if (line.find("Artist:") == 0) metadata["Artist"] = getValue(line);
    else if (line.find("Creator:") == 0) metadata["Creator"] = getValue(line);
    else if (line.find("ApproachRate:") == 0) approachRate = std::stof(getValue(line));
    else if (line.find("OverallDifficulty:") == 0) overallDifficulty = std::stof(getValue(line));
    else if (line.find("CircleSize:") == 0) circleSize = std::stof(getValue(line));
    else if (line.find("TimingPoints") != std::string::npos) parseTimingPoint(file, timingPoints);
    else if (line.find("HitObjects") != std::string::npos) parseHitObjects(file, hitObjects);

}

void Parser::parseHitObjects(std::ifstream& file, std::vector<HitObjectData>& hitObjects) {
    std::cout << "Parsing hitObjects" << std::endl;
    int counter = 0;
    std::string line;
    while (std::getline(file, line) && !line.empty()) {
        if (line[0] == '[' or line[0] == ' ') break;
        counter++;
        std::stringstream ss(line);

        char delimiter;

        int x, y, time;

        ss >> x >> delimiter >> y >> delimiter >> time;

        hitObjects.push_back({x, y, time});
    }
    std::cout << "Finished parsing hitObjects with " << counter << std::endl;
}

void Parser::parseTimingPoint(std::ifstream& file, std::vector<TimingPoint>& timingPoints) {
    std::cout << "Parsing timing points" << std::endl;
    int counter = 0;
    std::string line;
    while (std::getline(file, line) && !line.empty()) {
        if (line[0] == '[' or line[0] == ' ') break;
        counter++;
        std::stringstream ss(line);

        char delimiter;

        int time;
        int sbpm;
        int meter;
        int sampleSet;
        int sampleIndex;
        int volume;
        bool uninherited;
        bool kiaiMode;

        ss >> time >> delimiter >> sbpm >> delimiter >> meter >> delimiter >> sampleSet >> delimiter >> sampleIndex >> delimiter >> volume >> delimiter >> uninherited >> delimiter >> kiaiMode;

        if (sbpm < 0) continue;

        float bpm = sbpm / 60000.0f;

        timingPoints.push_back({time, bpm, meter, sampleSet, sampleIndex, volume, uninherited, kiaiMode});
    }
    std::cout << "Finished parsing timing points with " << counter << std::endl;
}

std::string Parser::getValue(const std::string& line) {
    return line.substr(line.find(":") + 1);
}
