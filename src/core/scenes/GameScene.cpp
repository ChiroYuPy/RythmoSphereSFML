//
// Created by adrian on 05/03/25.
//

#include "../../../include/core/scenes/GameScene.h"
#include "../../../include/core/Game.h"

#include "../../../include/core/graphics/drawables/Circle.h"
#include "../../../include/core/graphics/drawables/BoxButton.h"
#include "../../../include/core/graphics/drawables/Label.h"

GameScene::GameScene(Game &game) : game(game){
    songPosition = 0.f;

    if (!font.loadFromFile("/home/adrian/CLionProjects/RythmoSphere/assets/fonts/Rubik-Bold.ttf")) {
        std::cerr << "Erreur de chargement de la police!" << std::endl;
    }
}

void GameScene::initialize() {
    songPosition = 0.0f;
}

void GameScene::update(const sf::Time globalTime, const sf::Time deltaTime) {
    for (const auto& drawable : drawables) {
        drawable->update(globalTime, deltaTime);
    }
}

void GameScene::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
    for (const auto& drawable : drawables) {
        if (const auto button = std::dynamic_pointer_cast<Button>(drawable)) {
            button->handleEvent(event);
        }
    }
}

void GameScene::onClickButton() const {
    std::cout << "Change Scene" << std::endl;
    game.getSceneManager()->changeScene(SceneType::Main);
}

void GameScene::onEnter() {
    auto label = std::make_shared<Label>("GameScene", 100, 100, font, 24);
    drawables.emplace_back(label);
    game.getGraphicsManager()->addDrawable(label);

    auto boxButton = std::make_shared<BoxButton>(256, 256, sf::Color::Green);
    boxButton->setPosition(sf::Vector2f(400, 300));
    boxButton->setOnClick([this] { onClickButton(); });

    boxButton->TransformTo<float>(
    [boxButton](const float pos) { boxButton->setX(pos); },
    boxButton->getX()-128, boxButton->getX()+128, 200.f, 1000.f, -1, true, EaseInOut<float>
    );

    boxButton->TransformTo<float>(
    [boxButton](const float angle) { boxButton->setRotation(angle); },
    boxButton->getRotation(), boxButton->getRotation()+90, 200.f, 1000.f, -1, false, EaseInOut<float>
    );

    drawables.emplace_back(boxButton);
    game.getGraphicsManager()->addDrawable(boxButton);

    auto ball = std::make_shared<Circle>(12, sf::Color::Red);
    ball->setPosition(sf::Vector2f(400, 300));

    drawables.emplace_back(ball);
    game.getGraphicsManager()->addDrawable(ball);
}

void GameScene::onExit() {
    for (const auto& drawable : drawables) game.getGraphicsManager()->removeDrawable(drawable);
    drawables.clear();
    hitObjects.clear();
}
