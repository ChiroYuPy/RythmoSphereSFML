//
// Created by adrian on 01/03/25.
//

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H



#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

class TextureManager {
public:
    static bool loadTexture(const std::string& key, const std::string& filePath);

    static sf::Texture& getTexture(const std::string& key);

    static bool isTextureLoaded(const std::string& key);

private:
    static const std::string DEFAULT_TEXTURES_DIR;

    static std::unordered_map<std::string, sf::Texture> textures;
};



#endif //TEXTUREMANAGER_H
