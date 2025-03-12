//
// Created by adrian on 07/03/25.
//

#include "../../../../include/core/graphics/drawables/Circle.h"

#include <iostream>

Circle::Circle(const float radius, const sf::Color color)
    : radius(radius), color(color) {}

void Circle::draw(sf::RenderWindow& window) {
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    if (parent) {
        std::cout << parent->getPosition().x << " " << parent->getPosition().y << std::endl;
        circle.setPosition(parent->getPosition() + getPosition());
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