//
// Created by adrian on 05/03/25.
//

#include "../../../include/core/scenes/MainScene.h"
#include "../../../include/core/Game.h"

#include "../../../include/core/graphics/drawables/Label.h"

#include "../../../include/core/graphics/drawables/BoxButton.h"
#include "../../../include/core/graphics/drawables/Circle.h"

MainScene::MainScene(Game &game) : game(game){
    if (!font.loadFromFile("/home/adrian/CLionProjects/RythmoSphere/assets/fonts/Rubik-Bold.ttf")) {
        std::cerr << "Erreur de chargement de la police!" << std::endl;
    }

    const auto boxButton = std::make_shared<BoxButton>(64, 64);
    boxButton->setPosition({
        static_cast<float>(game.getRenderWindow()->getSize().x) / 2,
        static_cast<float>(game.getRenderWindow()->getSize().y) / 2
    });
    boxButton->setColor(sf::Color::Green);
    boxButton->setOnClick([this] { onClickButton(); });
    boxButton->scaleTo({1, 1}, {1.5, 3}, 1024.f, 512.f, Easing::EaseInOutQuad);
    boxButton->rotateTo(0, 360, 1024.f, 512.f, Easing::EaseInOutQuad);
    boxButton->colorTo(sf::Color(0, 0, 0, 0), sf::Color(255, 255, 255, 127), 1024.f, 512.f, Easing::EaseInOutQuad);
    interactives.push_back(boxButton);

    const auto circle = std::make_shared<Circle>(32);
    circle->setPosition({
        static_cast<float>(game.getRenderWindow()->getSize().x) / 2,
        static_cast<float>(game.getRenderWindow()->getSize().y) / 2
    });
    circle->setColor(sf::Color::Red);
    circle->scaleTo({1, 1}, {2, 2}, 1024.f, 512.f, Easing::EaseInOutQuad);

    addObject(circle);
    addObject(boxButton);
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
}

void MainScene::onEnter() {
    auto const label = std::make_shared<Label>("MainScene", font, 24);
}

void MainScene::onExit() {

}
