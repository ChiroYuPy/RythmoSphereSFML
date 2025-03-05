//
// Created by adrian on 05/03/25.
//

#include "../../../include/core/scenes/GameScene.h"

void GameScene::initialize() {
    songPosition = 0.0f;
}

void GameScene::update(float deltaTime) {
}

void GameScene::render() {

}

void GameScene::onEnter() {
}

void GameScene::onExit() {
    drawables.clear();
    hitObjects.clear();
}
