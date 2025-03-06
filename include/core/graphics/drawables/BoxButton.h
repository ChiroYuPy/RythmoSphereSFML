//
// Created by adrian on 06/03/25.
//

#ifndef BOXBUTTON_H
#define BOXBUTTON_H

#pragma once

#include "Box.h"
#include "../Button.h"

class BoxButton final : public Box, public Button {
public:
    BoxButton(const float x, const float y, const float width, const float height)
        : Box(x, y, width, height) {}

    bool contains(const float x, const float y) override {
        return x >= position.x && x <= position.x + width &&
               y >= position.y && y <= position.y + height;
    }
};

#endif //BOXBUTTON_H
