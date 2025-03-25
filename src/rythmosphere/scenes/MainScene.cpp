//
// Created by adrian on 05/03/25.
//

#include "rythmosphere/scenes/MainScene.h"
#include "rythmosphere/Game.h"

MainScene::MainScene(Game &game) : game(game) {
    logo = std::make_shared<RythmoSphereLogo>();
    logo->setPosition({
        (static_cast<float>(game.getRenderWindow()->getSize().x)) / 2,
        (static_cast<float>(game.getRenderWindow()->getSize().y)) / 2
    });
    addInternal(logo);
}

void MainScene::initialize() {

}

void MainScene::onUpdate(sf::Time globalTime, sf::Time deltaTime) {

}

void MainScene::onRender(sf::RenderWindow& window) {

}

void MainScene::onClickButton() const {
    std::cout << "Change Scene" << std::endl;
    game.getSceneManager()->changeScene(SceneType::Game);
}


void MainScene::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
    for (const auto & button : interactives) {
        button->handleEvent(event);
    }

    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            // On clique sur le logo pour le montrer ou le cacher
            if (logo->isLogoVisible()) {
                logo->hide();  // Cache le logo si il est déjà visible
            } else {
                logo->show();  // Affiche le logo si il est caché
            }
        } else if (event.mouseButton.button == sf::Mouse::Right) {
            onClickButton();
        }
    }
}

void MainScene::onEnter() {
    auto const label = std::make_shared<Label>("MainScene", font, 24);
}

void MainScene::onExit() {

}
