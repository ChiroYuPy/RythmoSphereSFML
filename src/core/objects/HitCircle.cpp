//
// Created by adrian on 05/03/25.
//

#include "../../../include/core/objects/HitCircle.h"

HitCircle::HitCircle(float x, float y, float time, float radius)
    : HitObject(time), x(x), y(y), radius(radius) {}

float HitCircle::getX() const { return x; }
float HitCircle::getY() const { return y; }
float HitCircle::getRadius() const { return radius; }

bool HitCircle::checkHit(float currentTime) {
    return (currentTime >= hitTime - 50 && currentTime <= hitTime + 50);
}
