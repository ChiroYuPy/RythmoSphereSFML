//
// Created by adrian on 05/03/25.
//

#ifndef DRAWABLEHITCIRCLE_H
#define DRAWABLEHITCIRCLE_H

#include "DrawableHitObject.h"
#include "../../objects/HitCircle.h"

class DrawableHitCircle : public DrawableHitObject {
public:
    explicit DrawableHitCircle(HitCircle* circleHitObject);

    void draw(sf::RenderWindow& window) override;
    void update(sf::Time globalTime, sf::Time deltaTime) override;
};

#endif //DRAWABLEHITCIRCLE_H
