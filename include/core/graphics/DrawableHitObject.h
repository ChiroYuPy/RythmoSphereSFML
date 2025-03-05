//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef DRAWABLEHITOBJECT_H
#define DRAWABLEHITOBJECT_H

#include "Drawable.h"
#include "../objects/HitObject.h"

class DrawableHitObject : public Drawable {
public:
    explicit DrawableHitObject(HitObject* hitObject);

    void draw() const override = 0;
    void update(float deltaTime) override;

    bool isHit() const;
    void onHit();

protected:
    HitObject* hitObject;
    bool hit;
};
#endif //DRAWABLEHITOBJECT_H
