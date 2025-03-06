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

void GameScene::update(float deltaTime) {
    for (const auto& drawable : drawables) {
        drawable->update(deltaTime);
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

    float startValue = 0.0f;
    float maxValue = 100.0f;
    std::function function = [](const float t) { return t; };
    float startTime = 0.0f;
    float durationTime = 5.0f;
    int loopCount = 5;
    bool rewinded = false;

    const auto transform = std::make_shared<Transform>(startValue, maxValue, function, startTime, durationTime, loopCount, rewinded);
    boxButton->addTransform("x", transform);

    drawables.emplace_back(label);
    drawables.emplace_back(boxButton);

    game.getGraphicsManager()->addDrawable(label);
    game.getGraphicsManager()->addDrawable(boxButton);
}

void GameScene::onExit() {
    for (const auto& drawable : drawables) game.getGraphicsManager()->removeDrawable(drawable);
    drawables.clear();
    hitObjects.clear();
}
