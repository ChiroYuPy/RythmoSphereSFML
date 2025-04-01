//
// Created by adrian on 06/03/25.
//

#include "core/graphics/drawables/containers/Container.h"

#include "core/transform/Anchor.h"

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
    if (!layout) return;
    layout->arrange(children, position.x, position.y, size.x, size.y);
}