//
// Created by adrian on 05/03/25.
//

#include "../../../include/core/managers/GraphicsManager.h"

GraphicsManager::GraphicsManager(Game& game) : game(game) {
    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 600), "RythmoSphere");
    window->setFramerateLimit(330);
}

void GraphicsManager::render() const {
    window->clear();
    for (const auto& drawable : drawables) {
        drawable->draw(*window);
    }
    window->display();
}

void GraphicsManager::addDrawable(const std::shared_ptr<Drawable>& drawable) { drawables.push_back(drawable); }

void GraphicsManager::removeDrawable(const std::shared_ptr<Drawable>& drawable) {
    if (const auto it = std::ranges::find(drawables, drawable); it != drawables.end()) {
        drawables.erase(it);
    }

    // auto it = std::find(drawables.begin(), drawables.end(), drawable);
    // if (it != drawables.end()) {
    //     drawables.erase(it);
    // }
}

void GraphicsManager::removeAllDrawables() { drawables.clear(); }

sf::RenderWindow &GraphicsManager::getWindow() const { return *window; }
