//
// Created by adrian on 05/03/25.
//

#include "../../../include/core/scenes/GameScene.h"
#include "../../../include/core/Game.h"

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
        drawable->setX(drawable->getValue("x", 100));
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

    auto boxButton = std::make_shared<BoxButton>(400-128, 300-128, 256, 256);
    boxButton->setOnClick([this] { onClickButton(); });

    std::function function = [](const float t) {
        if (t < 0.5) return 2 * t * t;
        return 1 - ( - 2 * t + 2) * ( - 2 * t + 2) / 2;
    };

    const auto transform = std::make_shared<Transform>(400-320, 400+64, function, 0, 2, -1, true);
    boxButton->addTransform("x", transform);

    drawables.emplace_back(label);
    game.getGraphicsManager()->addDrawable(label);

    drawables.emplace_back(boxButton);
    game.getGraphicsManager()->addDrawable(boxButton);
}

void GameScene::onExit() {
    for (const auto& drawable : drawables) game.getGraphicsManager()->removeDrawable(drawable);
    drawables.clear();
    hitObjects.clear();
}
