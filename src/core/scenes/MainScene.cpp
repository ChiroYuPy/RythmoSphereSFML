//
// Created by adrian on 05/03/25.
//

#include "../../../include/core/scenes/MainScene.h"
#include "../../../include/core/Game.h"

MainScene::MainScene(Game &game) : game(game){
    if (!font.loadFromFile("/home/adrian/CLionProjects/RythmoSphere/assets/fonts/Rubik-Bold.ttf")) {
        std::cerr << "Erreur de chargement de la police!" << std::endl;
    }
}

void MainScene::initialize() {

}

void MainScene::update(float deltaTime) {

}

void handleEvent(const sf::Event& event) {

}

void MainScene::onEnter() {

    auto const label = std::make_shared<Label>("MainScene", 400, 300, font, 24);
    game.getGraphicsManager()->addDrawable(label);
}

void MainScene::onExit() {
    game.getGraphicsManager()->removeAllDrawables();
}
