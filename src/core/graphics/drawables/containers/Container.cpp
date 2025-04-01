//
// Created by adrian on 06/03/25.
//

#include "../../../../../include/core/graphics/drawables/containers/Container.h"

#include <iostream>

void Container::draw(sf::RenderWindow& window) {
    if (!visible) return;
    CompositeDrawable::draw(window);
}

void Container::update(const sf::Time deltaTime) {
    if (!visible) return;
    CompositeDrawable::update(deltaTime);
    updateLayout(deltaTime);
}

void Container::updateLayout(const sf::Time deltaTime) {
    if (!visible) return;
    for (const auto child : children) {
        const sf::Vector2f relative = anchorToRelative(anchor);
        child->setPosition({relative.x * size.x, relative.y * size.y});
    }
}