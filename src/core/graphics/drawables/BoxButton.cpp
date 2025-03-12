//
// Created by adrian on 06/03/25.
//

#include "../../../../include/core/graphics/drawables/BoxButton.h"

BoxButton::BoxButton(const float width, const float height, const sf::Color color)
    : Box(width, height, color) {}

bool BoxButton::contains(const float x, const float y) {
    return rect.getGlobalBounds().contains(x, y);
}

