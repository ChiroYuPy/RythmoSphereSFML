//
// Created by adrian on 05/03/25.
//

#include "../../../include/core/scenes/GameScene.h"
#include "../../../include/core/Game.h"

GameScene::GameScene(Game &game) : game(game){
    songPosition = 0.f;

    if (!font.loadFromFile("/home/adrian/CLionProjects/RythmoSphere/assets/fonts/Rubik-Bold.ttf")) {
        std::cerr << "Erreur de chargement de la police!" << std::endl;
    }
}

void GameScene::initialize() {
    songPosition = 0.0f;
}

void GameScene::update(float deltaTime) {

}

void handleEvent(const sf::Event& event) {

}

void GameScene::onEnter() {

    auto const label = std::make_shared<Label>("GameScene", 100, 100, font, 24);
    drawables.emplace_back(label);
    game.getGraphicsManager()->addDrawable(label);
}

void GameScene::onExit() {
    game.getGraphicsManager()->removeAllDrawables();
    drawables.clear();
    hitObjects.clear();
}
