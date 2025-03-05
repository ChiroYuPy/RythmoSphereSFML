//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H

class Game;

#include <SFML/Graphics.hpp>
#include <memory>

class GraphicsManager {
public:
    explicit GraphicsManager(Game& game);

    void render() const;
    void clear() const;

    sf::RenderWindow& getWindow() const;

private:
    Game& game;
    std::unique_ptr<sf::RenderWindow> window;
};

#endif //GRAPHICSMANAGER_H
