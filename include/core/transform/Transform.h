//
// Created by adrian on 06/03/25.
//

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <functional>

class Transform {
public:
    Transform(float startValue, float maxValue, std::function<float(float)> function, float startTime, float durationTime, int loopCount, bool rewinded = false);

    void update(float currentTime);

    float getValue() const;

private:
    float startValue, maxValue, currentValue;
    std::function<float(float)> function;
    float startTime, durationTime;
    int loopCount, looped;
    bool rewinded, finished;
};

#endif //TRANSFORM_H
