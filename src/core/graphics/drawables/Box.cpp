//
// Created by adrian on 06/03/25.
//

#include "../../../../include/core/graphics/drawables/Box.h"

Box::Box(const float x, const float y, const float width, const float height)
    : Drawable(x, y), width(width), height(height) {}

void Box::draw(sf::RenderWindow& window) {
    sf::RectangleShape rect(sf::Vector2f(width, height));
    rect.setPosition(position);
    rect.setFillColor(sf::Color::Green);
    window.draw(rect);
}