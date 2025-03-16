//
// Created by adrian on 06/03/25.
//

#include "../../../../include/core/graphics/drawables/Box.h"

Box::Box(const float width, const float height) {
    setSize({width, height});
}

void Box::draw(sf::RenderWindow& window) {
    rect.setSize(size);
    rect.setOrigin(size.x / 2.f, size.y / 2.f);
    if (parent) {
        rect.setPosition(parent->getAbsolutePosition(getPosition()));
        rect.setRotation(parent->getRotation() + getRotation());
        rect.setScale({parent->getScale().x * getScale().x, parent->getScale().y * getScale().y});
    } else {
        rect.setPosition(getPosition());
        rect.setRotation(getRotation());
        rect.setScale(getScale());
    }
    rect.setFillColor(color);
    window.draw(rect);
}