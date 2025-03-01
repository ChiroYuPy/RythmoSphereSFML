//
// Created by adrian on 01/03/25.
//

#include "TextureManager.h"
#include <iostream>

std::unordered_map<std::string, sf::Texture> TextureManager::textures;

const std::string TextureManager::DEFAULT_TEXTURES_DIR = "../skin/";

bool TextureManager::loadTexture(const std::string& key, const std::string& filePath) {
    if (textures.find(key) != textures.end()) {
        return true;
    }

    std::string completeFilePath = DEFAULT_TEXTURES_DIR + filePath;

    sf::Texture texture;
    if (!texture.loadFromFile(completeFilePath)) {
        std::cerr << "Erreur de chargement de la texture : " << completeFilePath << std::endl;
        return false;
    }

    textures[key] = texture;
    return true;
}

sf::Texture& TextureManager::getTexture(const std::string& key) {
    if (textures.find(key) != textures.end()) {
        return textures[key];
    }

    throw std::runtime_error("Texture non trouvée : " + key);
}

bool TextureManager::isTextureLoaded(const std::string& key) {
    return textures.find(key) != textures.end();
}
