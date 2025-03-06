//
// Created by adrian on 05/03/25.
//

#include <iostream>

#include "../../../include/core/graphics/DrawableHitCircle.h"

DrawableHitCircle::DrawableHitCircle(HitCircle* hitCircle) : DrawableHitObject(hitCircle) {}

void DrawableHitCircle::draw(sf::RenderWindow& window) {
    auto* circle = static_cast<HitCircle*>(hitObject);
    std::cout << "Dessine un cercle à (" << circle->getX()
              << ", " << circle->getY()
              << ") avec un rayon de " << circle->getRadius() << "\n";
}

void DrawableHitCircle::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {

}

void DrawableHitCircle::update(const float deltaTime) {
    DrawableHitObject::update(deltaTime);
}