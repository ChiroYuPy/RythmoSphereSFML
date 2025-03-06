//
// Created by adrian on 05/03/25.
//

#include <iostream>

#include "../../../include/core/managers/SceneManager.h"
#include "../../../include/core/scenes/SceneType.h"
#include "../../../include/core/scenes/MainScene.h"
#include "../../../include/core/scenes/GameScene.h"

SceneManager::SceneManager(Game& game) : game(game) {
    sceneCache[SceneType::Main] = std::make_shared<MainScene>(game);
    sceneCache[SceneType::Game] = std::make_shared<GameScene>(game);
}

void SceneManager::changeScene(SceneType sceneType) {
    if (sceneCache.contains(sceneType)) {
        if (currentScene) currentScene->onExit();
        currentScene = sceneCache[sceneType];
        if (currentScene) currentScene->onEnter();
    } else {
        std::cerr << "Scene not found!" << std::endl;
    }
}

void SceneManager::update(const sf::Time globalTime, const sf::Time deltaTime) const {
    if (currentScene) currentScene->update(globalTime, deltaTime);
}

std::shared_ptr<Scene> SceneManager::getCurrentScene() {
    if (currentScene == nullptr) {
        std::cerr << "Error: Scene not selected ! Terminating program." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return currentScene;
}
