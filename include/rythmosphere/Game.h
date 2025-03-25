//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef GAME_H
#define GAME_H

#include <memory>

#include "../core/managers/AudioManager.h"
#include "../core/managers/ConfigManager.h"
#include "../core/managers/TimeManager.h"
#include "../core/managers/SceneManager.h"
#include "../core/managers/FontManager.h"

class Game {
public:
    Game();
    ~Game() = default;

    void run() const;

    [[nodiscard]] sf::RenderWindow *getRenderWindow() const;

    [[nodiscard]] ConfigManager* getConfigManager() const;
    [[nodiscard]] AudioManager* getAudioManager() const;
    [[nodiscard]] TimeManager* getTimeManager() const;
    [[nodiscard]] SceneManager* getSceneManager() const;

private:
    std::unique_ptr<sf::RenderWindow> window;

    std::unique_ptr<ConfigManager> configManager;
    std::unique_ptr<AudioManager> audioManager;
    std::unique_ptr<TimeManager> timeManager;
    std::unique_ptr<SceneManager> sceneManager;
};

#endif //GAME_H
