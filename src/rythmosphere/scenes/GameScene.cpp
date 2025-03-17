//
// Created by adrian on 05/03/25.
//

#include "../../../include/rythmosphere/scenes/GameScene.h"
#include "../../../include/rythmosphere/Game.h"

#include "../../../include/core/graphics/drawables/Circle.h"
#include "../../../include/core/graphics/drawables/BoxButton.h"
#include "../../../include/core/graphics/drawables/Label.h"
#include "../../../include/core/graphics/drawables/containers/Container.h"
#include "../../../include/core/graphics/drawables/DrawableHitCircle.h"

GameScene::GameScene(Game &game) : game(game){
    songPosition = 0.f;

    if (!font.loadFromFile("/home/adrian/CLionProjects/RythmoSphere/assets/fonts/Rubik-Bold.ttf")) {
        std::cerr << "Erreur de chargement de la police!" << std::endl;
    }

    const auto playField = std::make_shared<Container>();
    playField->setPosition({
        (static_cast<float>(game.getRenderWindow()->getSize().x)) / 2,
        (static_cast<float>(game.getRenderWindow()->getSize().y)) / 2
    });
    //playField->moveTo({0, 0}, {256, 256}, 0.f, 1024.f, Easing::EaseInOutQuad);
    playField->rotateTo(0, 40, 1024.f, 1024.f, Easing::EaseInOutQuad);
    playField->rotateTo(40, 80, 2048.f, 1024.f, Easing::EaseInOutQuad);
    playField->rotateTo(80, 120, 3072.f, 1024.f, Easing::EaseInOutQuad);
    playField->rotateTo(120, 360, 4096.f, 1024.f, Easing::EaseInOutQuad);
    playField->scaleTo({1, 1}, {2, 2}, 0.f, 1024.f, Easing::EaseInOutQuad);
    playField->scaleTo({2, 2}, {1, 1}, 4096.f, 1024.f, Easing::EaseInOutQuad);

    const auto playFieldGround = std::make_shared<Box>(512, 384);
    playFieldGround->setColor(sf::Color(32, 32, 32, 127));
    playField->addChild(playFieldGround);

    const auto label = std::make_shared<Label>("GameScene", font, 32);
    label->setColor(sf::Color::Blue);
    label->rotateTo(0, 360, 4096.f, 1024.f, Easing::EaseInOutQuad);
    playField->addChild(label);

    const auto labelTest = std::make_shared<Label>("Test", font, 128);
    labelTest->setColor(sf::Color::White);
    labelTest->setAnchor(Anchor::TopCenter);
    labelTest->setOrigin(Anchor::TopCenter);
    playField->addChild(labelTest);

    const auto boxButton = std::make_shared<BoxButton>(64, 64);
    boxButton->setColor(sf::Color::Green);
    boxButton->setOnClick([this] { onClickButton(); });
    boxButton->moveTo({0, 0}, {0, 128}, 1024.f, 512.f, Easing::EaseInOutQuad);
    boxButton->scaleTo({1, 1}, {0.5, 1.5}, 1024.f, 512.f, Easing::EaseInOutQuad);
    playField->addChild(boxButton);
    interactives.push_back(boxButton);

    HitCircle hitObject1(0, 0, 0);
    HitCircle hitObject2(0, 0, 0);

    const auto drawableHitObject1 = std::make_shared<DrawableHitCircle>(hitObject1);
    const auto drawableHitObject2 = std::make_shared<DrawableHitCircle>(hitObject2);

    drawableHitObject1->moveTo({-100, -100}, {100, 100}, 0.f, 1024.f, Easing::EaseInOutQuad);
    drawableHitObject2->moveTo({100, 100}, {-100, -100}, 0.f, 1024.f, Easing::EaseInOutQuad);

    playField->addChild(drawableHitObject1);
    playField->addChild(drawableHitObject2);

    addInternal(playField);
}

void GameScene::initialize() {
    songPosition = 0.0f;
}

void GameScene::onUpdate(const sf::Time globalTime, const sf::Time deltaTime) {

}

void GameScene::onRender(sf::RenderWindow& window) {

}

void GameScene::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
    for (const auto & button : interactives) {
        button->handleEvent(event);
    }
}

void GameScene::onClickButton() const {
    std::cout << "Change Scene" << std::endl;
    game.getSceneManager()->changeScene(SceneType::Main);
}

void GameScene::onEnter() {

}


void GameScene::onExit() {
    hitObjects.clear();
}
