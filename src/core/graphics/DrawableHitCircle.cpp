//
// Created by adrian on 05/03/25.
//

#include <iostream>

#include "../../../include/core/graphics/DrawableHitCircle.h"

DrawableHitCircle::DrawableHitCircle(HitCircle* hitCircle) : DrawableHitObject(hitCircle) {}

void DrawableHitCircle::draw(sf::RenderWindow& window) const {
    auto* circle = static_cast<HitCircle*>(hitObject);
    std::cout << "Dessine un cercle à (" << circle->getX()
              << ", " << circle->getY()
              << ") avec un rayon de " << circle->getRadius() << "\n";
}

void DrawableHitCircle::update(float deltaTime) {
    DrawableHitObject::update(deltaTime);
}
