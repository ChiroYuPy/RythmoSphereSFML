//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H

#include "../graphics/Drawable.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class Game;

class GraphicsManager {
public:
    explicit GraphicsManager(Game& game);

    void render() const;

    void addDrawable(const std::shared_ptr<Drawable>& drawable);
    void removeDrawable(const std::shared_ptr<Drawable>& drawable);
    void removeAllDrawables();

    sf::RenderWindow& getWindow() const;

private:
    Game& game;
    std::unique_ptr<sf::RenderWindow> window;
    std::vector<std::shared_ptr<Drawable>> drawables;
};

#endif //GRAPHICSMANAGER_H
