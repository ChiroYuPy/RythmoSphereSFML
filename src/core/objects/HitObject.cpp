//
// Created by adrian on 05/03/25.
//

#include "../../../include/core/objects/HitObject.h"

HitObject::HitObject(float time) : hitTime(time) {}

float HitObject::getHitTime() const { return hitTime; }
