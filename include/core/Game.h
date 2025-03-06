//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef GAME_H
#define GAME_H

#include <memory>

#include "managers/AudioManager.h"
#include "managers/ConfigManager.h"
#include "managers/TimeManager.h"
#include "managers/SceneManager.h"
#include "managers/GraphicsManager.h"

class Game {
public:
    Game();
    ~Game() = default;

    void run() const;

    GraphicsManager* getGraphicsManager() const;
    ConfigManager* getConfigManager() const;
    AudioManager* getAudioManager() const;
    TimeManager* getTimeManager() const;
    SceneManager* getSceneManager() const;

private:
    std::unique_ptr<GraphicsManager> graphicsManager;
    std::unique_ptr<ConfigManager> configManager;
    std::unique_ptr<AudioManager> audioManager;
    std::unique_ptr<TimeManager> timeManager;
    std::unique_ptr<SceneManager> sceneManager;
};

#endif //GAME_H
