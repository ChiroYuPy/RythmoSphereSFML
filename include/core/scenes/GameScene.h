//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Scene.h"
#include "../graphics/drawables/DrawableHitObject.h"

class GameScene final : public Scene {
public:
    explicit GameScene(Game& game);

    void initialize() override;
    void onUpdate(sf::Time globalTime, sf::Time deltaTime) override;
    void onRender(sf::RenderWindow& window) override;
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window) override;
    void onClickButton() const;
    void onEnter() override;
    void onExit() override;

private:
    Game& game;
    sf::Font font;
    std::vector<std::shared_ptr<DrawableHitObject>> hitObjects;
    float songPosition;
};

#endif //GAMESCENE_H
