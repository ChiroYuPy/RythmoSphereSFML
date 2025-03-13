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
    void onUpdate(sf::Time globalTime, sf::Time deltaTime) override;
    void onRender(sf::RenderWindow& window) override;

    void onClickButton() const;

    void handleEvent(const sf::Event& event, const sf::RenderWindow& window) override;
    void onEnter() override;
    void onExit() override;

private:
    Game& game;
    sf::Font font;
};

#endif //MAINSCENE_H
