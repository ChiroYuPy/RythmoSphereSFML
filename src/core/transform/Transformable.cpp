//
// Created by adrian on 06/03/25.
//

#include <utility>

#include "../../../include/core/transform/Transformable.h"

Transformable::Transformable() : position(0, 0), rotation(0) {

}

void Transformable::update(const sf::Time globalTime, const sf::Time deltaTime) {
    for (const auto& transform : transforms) {
        transform->update(globalTime, deltaTime);
    }
}

template <typename T>
void Transformable::TransformTo(std::function<void(const T&)> setter, T startValue, T endValue, double startTime, double duration, int loopCount, bool rewinded, std::function<T(double)> easing) {
    auto transform = std::make_shared<Transform<T>>();

    transform->setValue = std::move(setter);
    transform->easing = std::move(easing);

    transform->startTime = startTime;
    transform->duration = duration;

    transform->startValue = startValue;
    transform->endValue = endValue;

    transform->loopCount = loopCount;
    transform->rewind = rewinded;

    transforms.push_back(transform);
}

template void Transformable::TransformTo<double>(std::function<void(const double&)>, double, double, double, double, int, bool, std::function<double(double)>);
template void Transformable::TransformTo<float>(std::function<void(const float&)>, float, float, double, double, int, bool, std::function<float(double)>);
template void Transformable::TransformTo<int>(std::function<void(const int&)>, int, int, double, double, int, bool, std::function<int(double)>);