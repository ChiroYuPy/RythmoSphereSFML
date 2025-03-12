//
// Created by adrian on 05/03/25.
//

#include "../../../include/core/objects/HitObject.h"

HitObject::HitObject(const float time, const int x, const int y) : hitTime(time), x(x), y(y) {

}

float HitObject::getHitTime() const {
    return hitTime;
}
