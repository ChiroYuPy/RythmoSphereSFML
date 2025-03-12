//
// Created by adrian on 05/03/25.
//

#include "../../../include/core/objects/HitCircle.h"

HitCircle::HitCircle(const float time, const int x, const int y, const float radius) : HitObject(time, x, y), radius(radius) {

}

float HitCircle::getRadius() const {
    return radius;
}

bool HitCircle::checkHit(const float currentTime) {
    return (currentTime >= hitTime - 50 && currentTime <= hitTime + 50);
}
