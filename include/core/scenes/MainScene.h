//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "Scene.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

class MainScene final : public Scene {
public:
    explicit MainScene(Game& game);

    void initialize() override;
    void update(float deltaTime) override;
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window) override;
    void onEnter() override;
    void onExit() override;

private:
    Game& game;
    sf::Font font;
};

#endif //MAINSCENE_H
