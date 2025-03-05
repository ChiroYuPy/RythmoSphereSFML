//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef DRAWABLEHITOBJECT_H
#define DRAWABLEHITOBJECT_H

#include "Drawable.h"

class DrawableHitObject final : public Drawable {
public:
    DrawableHitObject();

    void draw() const override;
    void update(float deltaTime) override;

    bool isHit() const;
    void onHit();

private:
    float positionX, positionY;
    float hitTime;
};

#endif //DRAWABLEHITOBJECT_H
