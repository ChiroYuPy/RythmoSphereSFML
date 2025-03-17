//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "../../core/scenes/Scene.h"
#include <SFML/Graphics.hpp>

#include "../../../include/core/graphics/drawables/Label.h"
#include "../../../include/rythmosphere/scenes/menu/RythmoSphereLogo.h"

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

    std::shared_ptr<RythmoSphereLogo> logo;
};

#endif //MAINSCENE_H
