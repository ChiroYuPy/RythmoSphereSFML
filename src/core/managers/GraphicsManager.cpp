//
// Created by adrian on 05/03/25.
//

#include "../../../include/core/managers/GraphicsManager.h"

GraphicsManager::GraphicsManager(Game& game) : game(game) {
    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 600), "RythmoSphere");
}

void GraphicsManager::render() const {
    window->clear();
    for (const auto& drawable : drawables) {
        drawable->draw();
    }
    window->display();
}

sf::RenderWindow& GraphicsManager::getWindow() const { return *window; }

void GraphicsManager::addDrawable(const std::shared_ptr<Drawable>& drawable) { drawables.push_back(drawable); }