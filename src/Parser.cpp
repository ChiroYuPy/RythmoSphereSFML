#include "Parser.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

Section SECTION = Section::NONE;
std::map<Section, int> Parser::sectionLineCount;

std::string sectionToString(Section section) {
    switch (section) {
        case Section::NONE: return "NONE";
        case Section::GENERAL: return "GENERAL";
        case Section::EDITOR: return "EDITOR";
        case Section::METADATA: return "METADATA";
        case Section::DIFFICULTY: return "DIFFICULTY";
        case Section::EVENTS: return "EVENTS";
        case Section::TIMING_POINTS: return "TIMING_POINTS";
        case Section::COLOURS: return "COLOURS";
        case Section::HIT_OBJECTS: return "HIT_OBJECTS";
        default: return "UNKNOWN";
    }
}

Beatmap Parser::parse(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier osu");
    }

    std::map<std::string, std::string> metadata;
    std::vector<HitObjectData> hitObjectDatas;
    std::vector<sf::Color> comboColors;
    std::vector<TimingPoint> timingPoints;
    float approachRate = 0, overallDifficulty = 0, circleSize = 0;

    parseFile(file, metadata, hitObjectDatas, comboColors, timingPoints, approachRate, overallDifficulty, circleSize);

    return Beatmap(metadata["Title"], metadata["Artist"], metadata["Creator"],
                   hitObjectDatas, comboColors, timingPoints, approachRate, overallDifficulty, circleSize);
}

void Parser::parseFile(std::ifstream& file, std::map<std::string, std::string>& metadata,
                       std::vector<HitObjectData>& hitObjects, std::vector<sf::Color>& comboColors,
                       std::vector<TimingPoint>& timingPoints, float& approachRate,
                       float& overallDifficulty, float& circleSize) {
    std::string line;
    while (std::getline(file, line)) {
        if (line[0] == '[') {
            if (line.find("General") != std::string::npos) SECTION = Section::GENERAL;
            else if (line.find("Editor") != std::string::npos) SECTION = Section::EDITOR;
            else if (line.find("Metadata") != std::string::npos) SECTION = Section::METADATA;
            else if (line.find("Difficulty") != std::string::npos) SECTION = Section::DIFFICULTY;
            else if (line.find("Events") != std::string::npos) SECTION = Section::EVENTS;
            else if (line.find("TimingPoints") != std::string::npos) SECTION = Section::TIMING_POINTS;
            else if (line.find("Colours") != std::string::npos) SECTION = Section::COLOURS;
            else if (line.find("HitObjects") != std::string::npos) SECTION = Section::HIT_OBJECTS;
        } else processLine(line, file, metadata, hitObjects, comboColors, timingPoints, approachRate, overallDifficulty, circleSize);
    }

    std::cout << "\nStatistiques des lignes chargées :\n";
    for (const auto& [section, count] : sectionLineCount) {
        std::cout << "- " << sectionToString(section) << " : " << count << " lignes\n";
    }
    std::cout << std::endl;
}

void Parser::processLine(std::string &line, std::ifstream &file, std::map<std::string, std::string> &metadata,
                         std::vector<HitObjectData> &hitObjects, std::vector<sf::Color> &comboColors,
                         std::vector<TimingPoint> &timingPoints, float &approachRate,
                         float &overallDifficulty, float &circleSize) {

    sectionLineCount[SECTION]++;

    switch (SECTION) {
        case Section::GENERAL:
            parseGeneral(line);
            break;
        case Section::EDITOR:
            parseEditor(line);
            break;
        case Section::METADATA:
            parseMetadata(line);
            break;
        case Section::DIFFICULTY:
            parseDifficulty(line, approachRate, overallDifficulty, circleSize);
            break;
        case Section::EVENTS:
            parseEvents(line);
            break;
        case Section::TIMING_POINTS:
            parseTimingPoints(line, timingPoints);
            break;
        case Section::COLOURS:
            parseComboColours(line, comboColors);
            break;
        case Section::HIT_OBJECTS:
            parseHitObjects(line, hitObjects);
            break;
        default:
            break;
    }
}

void Parser::parseGeneral(std::string& line) {

}

void Parser::parseEditor(std::string& line) {

}

void Parser::parseMetadata(std::string& line) {

}

void Parser::parseDifficulty(std::string& line, float& approachRate, float& overallDifficulty, float& circleSize) {
    if (line.find("ApproachRate") == 0) {
        approachRate = std::stof(getValue(line));
    } else if (line.find("OverallDifficulty") == 0) {
        overallDifficulty = std::stof(getValue(line));
    } else if (line.find("CircleSize") == 0) {
        circleSize = std::stof(getValue(line));
    }
}


void Parser::parseEvents(std::string& line) {

}

void Parser::parseHitObjects(std::string& line, std::vector<HitObjectData>& hitObjects) {

    std::stringstream ss(line);

    char delimiter;
    int x, y, time, type, hitSound;
    ss >> x >> delimiter >> y >> delimiter >> time >> delimiter >> type >> delimiter >> hitSound;

    std::string sliderData;
    int repeat = 0;
    float length = 0.0f;
    std::string extras;

    static int comboNumber = 0;
    comboNumber++;
    if (type & NEWCOMBO) comboNumber = 0;

    hitObjects.push_back({x, y, time, type, hitSound, sliderData, repeat, length, extras, comboNumber});

}

void Parser::parseComboColours(std::string& line, std::vector<sf::Color>& comboColors) {


    if (line.find("Combo") == 0) {
        std::stringstream ss(line);
        std::string comboName;
        char delimiter;
        int r, g, b;

        ss >> comboName >> delimiter >> r >> delimiter >> g >> delimiter >> b;

        comboColors.emplace_back(r, g, b);
    }

}

void Parser::parseTimingPoints(std::string& line, std::vector<TimingPoint>& timingPoints) {
    std::stringstream ss(line);

    char delimiter;
    int time, sbpm, meter, sampleSet, sampleIndex, volume;
    bool uninherited, kiaiMode;

    ss >> time >> delimiter >> sbpm >> delimiter >> meter >> delimiter >> sampleSet >> delimiter
       >> sampleIndex >> delimiter >> volume >> delimiter >> uninherited >> delimiter >> kiaiMode;

    float bpm = sbpm / 60000.0f;
    timingPoints.push_back({time, bpm, meter, sampleSet, sampleIndex, volume, uninherited, kiaiMode});

}

std::string Parser::getValue(const std::string& line) {
    return line.substr(line.find(":") + 1);
}
