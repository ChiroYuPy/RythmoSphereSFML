//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H

#include <SFML/Graphics.hpp>
#include <memory>

class GraphicsManager {
public:
    GraphicsManager();

    void render() const;
    void clear() const;

    sf::RenderWindow& getWindow() const;

private:
    std::unique_ptr<sf::RenderWindow> window;
};

#endif //GRAPHICSMANAGER_H
