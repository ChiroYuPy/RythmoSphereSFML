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
    HitCircle(float time, int x, int y);

protected:
    int x, y;
};

#endif //HITCIRCLE_H
