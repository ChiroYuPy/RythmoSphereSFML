//
// Created by adrian on 06/03/25.
//

#include <utility>

#include "../../../include/core/transform/Transform.h"

Transform::Transform(const float startValue, const float maxValue, std::function<float(float)> function, const float startTime, const float durationTime, const int loopCount, bool rewinded)
        : startValue(startValue), maxValue(maxValue), currentValue(startValue), function(std::move(function)), startTime(startTime), durationTime(durationTime), loopCount(loopCount), looped(0), rewinded(false), finished(false) {}

void Transform::update(const float currentTime) {
    if (finished) return;

    float elapsedTime = currentTime - startTime;
    if (elapsedTime < 0) return;

    if (elapsedTime >= durationTime) {
        looped++;
        if (loopCount != -1 && looped >= loopCount) {
            finished = true;
        } else {
            startTime = currentTime;
            elapsedTime = 0;
            if (rewinded) std::swap(startValue, maxValue);
        }
    }

    const float timeProgress = std::clamp(elapsedTime / durationTime, 0.0f, 1.0f);
    const float deltaValue = function(timeProgress) * (maxValue - startValue);
    currentValue = startValue + deltaValue;
}

float Transform::getValue() const {
  return currentValue;
}