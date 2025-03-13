//
// Created by adrian on 11/03/25.
//

#include "../../../include/core/transform/Animation.h"

template <typename T>
Animation<T>::Animation(T* attribute, T start, T end, const float startTime, const float duration, std::function<float(float)> easingFunc)
    : attribute(attribute), startValue(start), endValue(end), startTime(startTime), duration(duration), elapsedTime(0.f), loops(0), rewind(false), easingFunction(std::move(easingFunc)) {
}

template <typename T>
Animation<T>::Animation(T* attribute, T start, T end, const float startTime, const float duration, const int loops, const bool rewind, std::function<float(float)> easingFunc)
    : attribute(attribute), startValue(start), endValue(end), startTime(startTime), duration(duration), elapsedTime(0.f), loops(loops), rewind(rewind), easingFunction(std::move(easingFunc)) {
}

template <typename T>
void Animation<T>::update(const sf::Time deltaTime) noexcept {
    if (isFinished()) return;

    elapsedTime += static_cast<float>(deltaTime.asMilliseconds());

    if (elapsedTime < startTime) return;

    float animationElapsedTime = elapsedTime - startTime;

    if (animationElapsedTime >= duration) {
        if (loops > 0) {
            animationElapsedTime -= duration;
            loopCount++;

            if (rewind) {
                reversed = !reversed;
                std::swap(startValue, endValue);
            }

            if (loopCount >= loops) {
                animationElapsedTime = duration;
                return;
            }
        } else if (loops == -1) {
            animationElapsedTime -= duration;
            if (rewind) {
                reversed = !reversed;
                std::swap(startValue, endValue);
            }
        } else {
            animationElapsedTime = duration;
            return;
        }
    }

    float t = (duration > 0.f) ? animationElapsedTime / duration : 1.f;
    t = easingFunction(t);

    *attribute = Lerp<T>::lerp(startValue, endValue, t);
}

template <typename T>
bool Animation<T>::isFinished() const noexcept {
    return elapsedTime >= (startTime + duration);
}

template class Animation<float>;
template class Animation<int>;
template class Animation<sf::Vector2f>;
template class Animation<sf::Vector2i>;
template class Animation<sf::Color>;
