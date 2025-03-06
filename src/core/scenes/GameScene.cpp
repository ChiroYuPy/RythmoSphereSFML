//
// Created by adrian on 05/03/25.
//

#include "../../../include/core/scenes/GameScene.h"
#include "../../../include/core/Game.h"

#include "../../../include/core/graphics/Button.h"
#include "../../../include/core/graphics/Label.h"

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

void GameScene::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
    for (const auto& drawable : drawables) {
        auto button = std::dynamic_pointer_cast<Button>(drawable);
        if (button) {
            button->handleEvent(event, window);
        }
    }
}

void GameScene::onClickButton() const {
    std::cout << "Change Scene" << std::endl;
    game.getSceneManager()->changeScene(SceneType::Main);
}

void GameScene::onEnter() {
    auto label = std::make_shared<Label>("GameScene", 100, 100, font, 24);

    auto button = std::make_shared<Button>(50, 50, 100, 200, font, 24, [this]() { GameScene::onClickButton(); });

    drawables.emplace_back(label);
    drawables.emplace_back(button);

    game.getGraphicsManager()->addDrawable(label);
    game.getGraphicsManager()->addDrawable(button);
}

void GameScene::onExit() {
    for (const auto& drawable : drawables) game.getGraphicsManager()->removeDrawable(drawable);
    drawables.clear();
    hitObjects.clear();
}
