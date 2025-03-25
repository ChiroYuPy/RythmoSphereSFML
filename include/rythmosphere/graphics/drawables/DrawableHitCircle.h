//
// Created by adrian on 05/03/25.
//

#ifndef DRAWABLEHITCIRCLE_H
#define DRAWABLEHITCIRCLE_H

#include "DrawableHitObject.h"
#include "../../objects/HitCircle.h"

class DrawableHitCircle final : public DrawableHitObject {
public:
    explicit DrawableHitCircle(HitCircle& hitCircle);

    void draw(sf::RenderWindow& window) override;
    void update(sf::Time globalTime, sf::Time deltaTime) override;

protected:
    sf::CircleShape circleShape;
    HitCircle& hitCircle;
};

#endif //DRAWABLEHITCIRCLE_H
