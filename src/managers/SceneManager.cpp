//
// Created by adrian on 05/03/25.
//

#include <iostream>

#include "../../include/managers/SceneManager.h"
#include "../../include/scenes/SceneType.h"
#include "../../include/scenes/MainScene.h"
#include "../../include/scenes/GameScene.h"

SceneManager::SceneManager(Game& game) : game(game) {
    sceneCache[SceneType::Main] = std::make_shared<MainScene>();
    sceneCache[SceneType::Game] = std::make_shared<GameScene>();
}

void SceneManager::changeScene(SceneType sceneType) {
    if (sceneCache.find(sceneType) != sceneCache.end()) {
        currentScene = sceneCache[sceneType];
        currentScene->onEnter();
    } else {
        std::cerr << "Scene not found!" << std::endl;
    }
}

std::shared_ptr<Scene> SceneManager::getCurrentScene() {
    if (currentScene == nullptr) {
        std::cerr << "Error: Scene not found! Terminating program." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return currentScene;
}
