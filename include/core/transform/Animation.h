//
// Created by adrian on 11/03/25.
//

#ifndef ANIMATION_H
#define ANIMATION_H

#include <functional>
#include <SFML/System/Time.hpp>
#include "../math/Easing.h"
#include "../math/Lerp.h"

class IAnimation {
public:
    virtual ~IAnimation() noexcept = default;
    virtual void update(sf::Time deltaTime) noexcept = 0;
    [[nodiscard]] virtual bool isFinished() const noexcept = 0;
};

template <typename T>
class Animation final : public IAnimation {
    T* attribute;
    T startValue;
    T endValue;
    float startTime;
    float duration;
    float elapsedTime;
    int loops;
    bool rewind;

    bool reversed = false;
    int loopCount = 0;

    std::function<float(float)> easingFunction;

public:
    Animation(T* attribute, T start, T end, float startTime, float duration, int loops, bool rewind, std::function<float(float)> easingFunc = Easing::EaseLinear);
    Animation(T* attribute, T start, T end, float startTime, float duration, std::function<float(float)> easingFunc = Easing::EaseLinear);
    void update(sf::Time deltaTime) noexcept override;
    [[nodiscard]] bool isFinished() const noexcept override;
};

extern template class Animation<float>;
extern template class Animation<int>;
extern template class Animation<sf::Vector2i>;
extern template class Animation<sf::Vector2f>;
extern template class Animation<sf::Color>;


#endif // ANIMATION_H

