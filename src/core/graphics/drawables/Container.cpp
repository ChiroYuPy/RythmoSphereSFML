//
// Created by adrian on 06/03/25.
//

#include "../../../../include/core/graphics/drawables/Container.h"

void Container::draw(sf::RenderWindow& window) {
    if (!visible) return;

    for (const auto& child : children) child->draw(window);
}

void Container::update(const sf::Time deltaTime) {
    Drawable::update(deltaTime);
    if (!visible) return;

    for (const auto& child : children) child->update(deltaTime);
}