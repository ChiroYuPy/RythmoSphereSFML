//
// Created by adrian on 05/03/25.
//

#include "../../../include/core/scenes/MainScene.h"
#include "../../../include/core/Game.h"

#include "../../../include/core/graphics/Button.h"
#include "../../../include/core/graphics/drawables/Label.h"

MainScene::MainScene(Game &game) : game(game){
    if (!font.loadFromFile("/home/adrian/CLionProjects/RythmoSphere/assets/fonts/Rubik-Bold.ttf")) {
        std::cerr << "Erreur de chargement de la police!" << std::endl;
    }
}

void MainScene::initialize() {

}

void MainScene::onUpdate(sf::Time globalTime, sf::Time deltaTime) {

}

void MainScene::onRender(sf::RenderWindow& window) {

}

void MainScene::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {

}

void MainScene::onEnter() {
    auto const label = std::make_shared<Label>("MainScene", font, 24);
}

void MainScene::onExit() {

}
