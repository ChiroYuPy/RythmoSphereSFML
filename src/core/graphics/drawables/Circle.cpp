//
// Created by adrian on 07/03/25.
//

#include "../../../../include/core/graphics/drawables/Circle.h"

Circle::Circle(const float radius, const sf::Color color)
    : radius(radius), color(color) {}

void Circle::draw(sf::RenderWindow& window) {
    sf::CircleShape circle(radius);
    circle.setOrigin(radius, radius);
    circle.setPosition(getPosition());
    circle.setRotation(getRotation());
    circle.setFillColor(color);
    window.draw(circle);
}