//
// Created by adrian on 01/04/25.
//

#include "SFML/Graphics.hpp"

#ifndef ANCHOR_H
#define ANCHOR_H

enum class Anchor {
    y0 = 1,
    y1 = 1 << 1,
    y2 = 1 << 2,

    x0 = 1 << 3,
    x1 = 1 << 4,
    x2 = 1 << 5,

    TopLeft = y0 | x0,
    TopCenter = y0 | x1,
    TopRight = y0 | x2,

    CenterLeft = y1 | x0,
    Center = y1 | x1,
    CenterRight = y1 | x2,

    BottomLeft = y2 | x0,
    BottomCenter = y2 | x1,
    BottomRight = y2 | x2,

    Custom = 1 << 6
};

inline sf::Vector2f anchorToRelative(const Anchor anchor) {
    float x = (static_cast<int>(anchor) & static_cast<int>(Anchor::x2)) ? 1.0f : (static_cast<int>(anchor) & static_cast<int>(Anchor::x1)) ? 0.5f : 0.0f;
    float y = (static_cast<int>(anchor) & static_cast<int>(Anchor::y2)) ? 1.0f : (static_cast<int>(anchor) & static_cast<int>(Anchor::y1)) ? 0.5f : 0.0f;
    return {x, y};
}

#endif //ANCHOR_H
