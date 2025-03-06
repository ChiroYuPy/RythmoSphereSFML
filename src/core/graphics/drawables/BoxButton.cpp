//
// Created by adrian on 06/03/25.
//

#include "../../../../include/core/graphics/drawables/BoxButton.h"

BoxButton::BoxButton(const float x, const float y, const float width, const float height)
    : Box(x, y, width, height) {}

bool BoxButton::contains(const float x, const float y) {
    return x >= position.x && x <= position.x + width &&
        y >= position.y && y <= position.y + height;
}