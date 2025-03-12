//
// Created by adrian on 05/03/25.
//

#include "../../../include/core/scenes/GameScene.h"
#include "../../../include/core/Game.h"

#include "../../../include/core/graphics/drawables/Circle.h"
#include "../../../include/core/graphics/drawables/BoxButton.h"
#include "../../../include/core/graphics/drawables/Label.h"
#include "../../../include/core/graphics/drawables/Container.h"
#include "../../../include/core/graphics/drawables/DrawableHitCircle.h"

GameScene::GameScene(Game &game) : game(game){
    songPosition = 0.f;

    if (!font.loadFromFile("/home/adrian/CLionProjects/RythmoSphere/assets/fonts/Rubik-Bold.ttf")) {
        std::cerr << "Erreur de chargement de la police!" << std::endl;
    }
}

void GameScene::initialize() {
    songPosition = 0.0f;
}

void GameScene::onUpdate(const sf::Time globalTime, const sf::Time deltaTime) {

}

void GameScene::onRender(sf::RenderWindow& window) {

}

void GameScene::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {

}

void GameScene::onClickButton() const {
    std::cout << "Change Scene" << std::endl;
    game.getSceneManager()->changeScene(SceneType::Main);
}

void GameScene::onEnter() {
    const auto playField = std::make_shared<Container>();
    playField->setPosition({
        (static_cast<float>(game.getRenderWindow()->getSize().x) - 512) / 2,
        (static_cast<float>(game.getRenderWindow()->getSize().y) - 384) / 2
    });
    playField->moveTo({0, 0}, {256, 256}, 0.f, 1024.f, Easing::EaseInOutQuad);
    playField->rotateTo(0, 40, 1024.f, 1024.f, Easing::EaseInOutQuad);
    playField->rotateTo(40, 80, 2048.f, 1024.f, Easing::EaseInOutQuad);
    playField->rotateTo(80, 120, 3072.f, 1024.f, Easing::EaseInOutQuad);
    playField->scaleTo({1, 1}, {2, 2}, 0.f, 1024.f, Easing::EaseInOutQuad);
    playField->scaleTo({2, 2}, {1, 1}, 4096.f, 1024.f, Easing::EaseInOutQuad);

    const auto label = std::make_shared<Label>("GameScene", 0, 0, font, 32);
    // label->moveTo({100, 200}, 0.f, 1024.f, Easing::EaseInOutQuad);
    // label->scaleTo({1, 4}, 0.f, 2048.f, Easing::EaseInOutQuad);
    // label->rotateTo(label->getRotation() + 45, 0.f, 2048.f, Easing::EaseInOutQuad);
    playField->addChild(label);

    const auto boxButton = std::make_shared<BoxButton>(64, 64, sf::Color::Green);
    boxButton->setOnClick([this] { onClickButton(); });
    boxButton->moveTo({0, 0}, {0, 128}, 1024.f, 64.f, Easing::EaseInOutQuad);
    // boxButton->rotateTo(boxButton->getRotation() + 90, 2048.f, Easing::EaseInOutQuad);
    // boxButton->scaleTo({2, 0.5}, 2048.f, Easing::EaseInOutQuad);
    playField->addChild(boxButton);

    const auto ball = std::make_shared<Circle>(12, sf::Color::Red);
    ball->moveTo({0, 0}, {128, -128}, 0.f, 4096.f, Easing::EaseInOutQuad);
    ball->scaleTo({1, 1}, {3, 3}, 1024.f, 2048.f, Easing::EaseInOutQuad);
    playField->addChild(ball);

    HitCircle hitObject1(0, 0, 0, 32);
    HitCircle hitObject2(0, 0, 0, 32);

    const auto drawableHitObject1 = std::make_shared<DrawableHitCircle>(hitObject1);
    const auto drawableHitObject2 = std::make_shared<DrawableHitCircle>(hitObject2);

    playField->addChild(drawableHitObject1);
    playField->addChild(drawableHitObject2);

    addObject(playField);
}

void GameScene::onExit() {
    clearObjects();
    hitObjects.clear();
}
