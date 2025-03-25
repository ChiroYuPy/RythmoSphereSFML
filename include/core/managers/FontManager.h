//
// Created by adrian on 17/03/25.
//

#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <iostream>

class FontManager {
public:
    static FontManager& getInstance() {
        static FontManager instance;
        return instance;
    }

    bool loadFont(const std::string& fontName, const std::string& filePath) {
        if (!fonts[fontName].loadFromFile(filePath)) {
            std::cerr << "Erreur de chargement de la police : " << fontName << std::endl;
            return false;
        }
        std::cout << "Loaded font : " << fontName << std::endl;
        return true;
    }

    sf::Font& getFont(const std::string& fontName) {
        if (fonts.contains(fontName)) {
            return fonts[fontName];
        }
        std::cerr << "Erreur : La police '" << fontName << "' n'a pas été trouvée!" << std::endl;
        throw std::out_of_range("Police non trouvée : " + fontName);
    }

    FontManager(const FontManager&) = delete;
    FontManager& operator=(const FontManager&) = delete;

private:
    FontManager() = default;

    std::unordered_map<std::string, sf::Font> fonts;
};

#endif //FONTMANAGER_H
