//
// Created by adrian on 11/03/25.
//

#ifndef EASING_H
#define EASING_H

namespace Easing {
    inline float EaseLinear(float t) {
        return t;
    }

    inline float EaseInQuad(float t) {
        return t * t;
    }

    inline float EaseOutQuad(float t) {
        return t * (2 - t);
    }

    inline float EaseInOutQuad(float t) {
        return t < 0.5f ? 2 * t * t : -1 + (4 - 2 * t) * t;
    }
}

#endif //EASING_H
