//
// Created by adrian on 11/03/25.
//

#include "../../../include/core/transform/Animation.h"

template <typename T>
Animation<T>::Animation(T* attribute, T start, T end, float duration, std::function<float(float)> easingFunc)
    : attribute(attribute), startValue(start), endValue(end), duration(duration),
      elapsedTime(0.f), easingFunction(std::move(easingFunc)) {}

template <typename T>
void Animation<T>::update(const sf::Time deltaTime) noexcept {
    if (isFinished()) return;

    elapsedTime += static_cast<float>(deltaTime.asMilliseconds());
    if (elapsedTime > duration) elapsedTime = duration;

    float t = (duration > 0.f) ? elapsedTime / duration : 1.f;
    t = easingFunction(t);

    *attribute = Lerp<T>::lerp(startValue, endValue, t);
}

template <typename T>
bool Animation<T>::isFinished() const noexcept {
    return elapsedTime >= duration;
}

template class Animation<float>;
template class Animation<int>;
template class Animation<sf::Vector2f>;
template class Animation<sf::Vector2i>;