//
// Created by adrian on 05/03/25.
//

#ifndef HITCIRCLE_H
#define HITCIRCLE_H

#include <SFML/Graphics/CircleShape.hpp>

#include "HitObject.h"
#include "../graphics/Drawable.h"

class HitCircle final : public HitObject {
public:
    HitCircle(float time, int x, int y, float radius);

    [[nodiscard]] float getRadius() const;

    bool checkHit(float currentTime) override;

private:
    float radius;
};

#endif //HITCIRCLE_H
