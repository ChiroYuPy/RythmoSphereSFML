//
// Created by adrian on 05/03/25.
//

#ifndef HITCIRCLE_H
#define HITCIRCLE_H

#include "HitObject.h"

class HitCircle : public HitObject {
public:
    HitCircle(float x, float y, float time, float radius);

    float getX() const;
    float getY() const;
    float getRadius() const;

    bool checkHit(float currentTime) override;

private:
    float x, y;
    float radius;
};

#endif //HITCIRCLE_H
