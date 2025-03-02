//
// Created by adrian on 27/02/25.
//


#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include <map>
#include "Beatmap.h"

enum class Section {
    NONE,
    GENERAL,
    EDITOR,
    METADATA,
    DIFFICULTY,
    EVENTS,
    TIMING_POINTS,
    COLOURS,
    HIT_OBJECTS
};

class Parser {
public:
    static Beatmap parse(const std::string& filePath);

private:
    static std::map<Section, int> sectionLineCount;

    static void parseFile(std::ifstream &file, std::map<std::string, std::string> &metadata,
                          std::vector<HitObjectData> &hitObjects, std::vector<sf::Color> &comboColors,
                          std::vector<TimingPoint> &timingPoints, float &approachRate, float &overallDifficulty, float &circleSize);

    static void processLine(std::string &line, std::ifstream &file, std::map<std::string, std::string> &metadata,
                            std::vector<HitObjectData> &hitObjects, std::vector<sf::Color> &comboColors,
                            std::vector<TimingPoint> &timingPoints, float &approachRate, float &overallDifficulty, float &circleSize);

    static void parseGeneral(std::string& line);

    static void parseEditor(std::string& line);

    static void parseMetadata(std::string& line);

    static void parseDifficulty(std::string &line, float &approachRate, float &overallDifficulty, float &circleSize);

    static void parseEvents(std::string& line);

    static void parseHitObjects(std::string& line, std::vector<HitObjectData> &hitObjects);

    static void parseComboColours(std::string& line, std::vector<sf::Color> &comboColors);

    static void parseTimingPoints(std::string& line, std::vector<TimingPoint> &timingPoints);

    static std::string getValue(const std::string& line);
};

#endif // PARSER_H