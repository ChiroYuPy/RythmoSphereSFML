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
    BoxButton(float x, float y, float width, float height);

    bool contains(float x, float y) override;
};

#endif //BOXBUTTON_H
