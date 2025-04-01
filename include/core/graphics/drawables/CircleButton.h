//
// Created by adrian on 06/03/25.
//

#ifndef BOXBUTTON_H
#define BOXBUTTON_H

#pragma once

#include "Circle.h"
#include "../interactive/Button.h"

class CircleButton final : public Circle, public Button {
public:
    explicit CircleButton(float radius);

    bool contains(float x, float y) override;
};

#endif //BOXBUTTON_H
