//
// Created by adrian on 06/03/25.
//

#include "../../../../include/core/graphics/drawables/CircleButton.h"

CircleButton::CircleButton(const float radius) : Circle(radius) {}

bool CircleButton::contains(const float x, const float y) { return circle.getGlobalBounds().contains(x, y); }

