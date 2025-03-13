//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

class Game;

#include <memory>
#include <map>

#include "../scenes/Scene.h"
#include "../scenes/SceneType.h"

class SceneManager {
private:
    Game& game;
    std::shared_ptr<Scene> currentScene;
    std::map<SceneType, std::shared_ptr<Scene>> sceneCache;

public:
    explicit SceneManager(Game& game);

    void addScene(SceneType sceneType, const std::shared_ptr<Scene> &scene);

    void changeScene(SceneType sceneType);
    void update(sf::Time globalTime, sf::Time deltaTime) const;
    std::shared_ptr<Scene> getCurrentScene();

    void render(sf::RenderWindow& window) const;
};

#endif //SCENEMANAGER_H
