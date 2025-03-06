//
// Created by adrian on 06/03/25.
//

#include "../../../include/core/transform/Transform.h"

Transform::Transform(float startValue, float maxValue, std::function<float(float)> function, float startTime, float durationTime, int loopCount, bool rewinded)
        : startValue(startValue), maxValue(maxValue), function(function), startTime(startTime), durationTime(durationTime), loopCount(loopCount), rewinded(false), currentValue(startValue), finished(false), looped(0) {}

void Transform::update(float currentTime) {
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

    float timeProgress = std::clamp(elapsedTime / durationTime, 0.0f, 1.0f);
    float deltaValue = function(timeProgress) * (maxValue - startValue);
    currentValue = startValue + deltaValue;
}