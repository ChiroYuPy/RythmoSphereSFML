//
// Created by adrian on 07/03/25.
//

#include "../../../../include/core/graphics/drawables/Circle.h"

#include <iostream>

Circle::Circle(const float radius) : radius(radius) {
    setSize({radius * 2, radius * 2});
}

void Circle::draw(sf::RenderWindow& window) {
    circle.setRadius(radius);
    const sf::Vector2f originPosition = computeAnchor(origin);
    circle.setOrigin({originPosition.x * size.x, originPosition.y * size.y});
    if (parent) {
        circle.setPosition(parent->getAbsolutePosition(getPosition()));
        circle.setRotation(parent->getRotation() + getRotation());
        circle.setScale({parent->getScale().x * getScale().x, parent->getScale().y * getScale().y});
    } else {
        circle.setPosition(getPosition());
        circle.setRotation(getRotation());
        circle.setScale(getScale());
    }
    circle.setFillColor(color);
    window.draw(circle);
}