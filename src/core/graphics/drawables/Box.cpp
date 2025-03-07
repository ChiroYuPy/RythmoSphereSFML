//
// Created by adrian on 06/03/25.
//

#include "../../../../include/core/graphics/drawables/Box.h"

Box::Box(const float width, const float height, const sf::Color color)
    : width(width), height(height), color(color) {}

void Box::draw(sf::RenderWindow& window) {
    sf::RectangleShape rect(sf::Vector2f(width, height));
    rect.setOrigin(width / 2.f, height / 2.f);
    rect.setPosition(getPosition());
    rect.setRotation(getRotation());
    rect.setFillColor(color);
    window.draw(rect);
}