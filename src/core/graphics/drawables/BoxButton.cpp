//
// Created by adrian on 06/03/25.
//

#include "../../../../include/core/graphics/drawables/BoxButton.h"

BoxButton::BoxButton(const float width, const float height)
    : Box(width, height) {}

bool BoxButton::contains(const float x, const float y) {
    return rect.getGlobalBounds().contains(x, y);
}

