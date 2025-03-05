//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "Scene.h"
#include "../graphics/Drawable.h"
#include "../graphics/DrawableHitObject.h"
#include "../graphics/Label.h"

class GameScene final : public Scene {
public:
    explicit GameScene(Game& game);

    void initialize() override;
    void update(float deltaTime) override;
    void handleEvent(const sf::Event& event) override;
    void onEnter() override;
    void onExit() override;

private:
    Game& game;
    sf::Font font;

    std::vector<std::shared_ptr<Drawable>> drawables;
    std::vector<std::shared_ptr<DrawableHitObject>> hitObjects;
    float songPosition;
};

#endif //GAMESCENE_H
