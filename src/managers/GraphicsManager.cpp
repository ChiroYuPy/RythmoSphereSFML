//
// Created by adrian on 05/03/25.
//

#include "../../include/managers/GraphicsManager.h"

GraphicsManager::GraphicsManager(Game& game) : game(game) {
    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 600), "SFML Game");
}

void GraphicsManager::clear() const {
    window->clear(sf::Color::Black);
}

void GraphicsManager::render() const {
    window->display();
}

sf::RenderWindow& GraphicsManager::getWindow() const {
    return *window;
}
