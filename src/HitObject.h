//
// Created by adrian on 26/02/25.
//

#pragma once

#include "Beatmap.h"
#include <SFML/Graphics/RenderWindow.hpp>

#ifndef HITOBJECT_H
#define HITOBJECT_H


class HitObject {
public:
    virtual ~HitObject() = default;

    virtual void init() = 0;

    virtual void update(float deltaTime, float beatmapTime, float hitWindowOffset, float hitObjectSize) = 0;

    HitObjectData data;
    float x, y;

    float getAdvance() const { return advance; }
    void setAdvance(float newAdvance) { advance = newAdvance; }

private:
    float advance = 0;
};

class Circle : public HitObject {
public:
    explicit Circle(HitObjectData data);

    void init() override;

    void update(float deltaTime, float beatmapTime, float hitWindowOffset, float hitObjectSize) override;
};


#endif //HITOBJECT_H
