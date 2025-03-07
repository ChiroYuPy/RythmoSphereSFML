//
// Created by adrian on 06/03/25.
//

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <functional>
#include <iostream>
#include <SFML/System/Time.hpp>

template<typename T>
double Lerp(double t) {
    t = std::clamp(t, 0.0, 1.0);
    return t;
}

template<typename T>
double EaseInOut(double t) {
    t = std::clamp(t, 0.0, 1.0);
    if (t < 0.5) return 2 * t * t;
    return 1 - ( - 2 * t + 2) * ( - 2 * t + 2) / 2;
}

struct TransformBase {
    virtual ~TransformBase() = default;
    virtual void update(sf::Time globalTime, sf::Time deltaTime) = 0;
};

template<typename T>
struct Transform final : TransformBase {
    std::function<void(const T&)> setValue;

    T startValue;
    T endValue;
    bool finished{};
    int looped{};
    int loopCount{};
    bool rewind{};
    double startTime{};
    double duration{};

    std::function<T(double)> easing = Lerp<T>;

    void update(const sf::Time globalTime, sf::Time deltaTime) override {
        if (finished) return;

        double elapsedTime = globalTime.asMilliseconds() - startTime;
        if (elapsedTime < 0) return;

        if (elapsedTime >= duration) {
            looped++;

            if (loopCount != -1 && looped >= loopCount) {
                finished = true;
                setValue(endValue);
                return;
            }

            startTime = globalTime.asMilliseconds();
            if (rewind) std::swap(startValue, endValue);
            elapsedTime = 0;
        }

        double timeProgress = std::clamp(elapsedTime / duration, 0.0, 1.0);
        setValue(startValue + (endValue - startValue) * easing(timeProgress));
    }
};

#endif //TRANSFORM_H
