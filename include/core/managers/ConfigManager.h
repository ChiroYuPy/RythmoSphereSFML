//
// Created by adrian on 06/03/25.
//

#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

class Game;

#include <string>

class ConfigManager {
public:
    explicit ConfigManager(Game& game);

    float volume = 1.0f;
    std::string selectedSkin = "default";
    bool enableShaders = true;

private:
    Game& game;
};

#endif //CONFIGMANAGER_H
