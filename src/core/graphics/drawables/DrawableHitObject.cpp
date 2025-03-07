//
// Created by adrian on 05/03/25.
//

#include <iostream>

#include "../../../../include/core/graphics/drawables/DrawableHitObject.h"

DrawableHitObject::DrawableHitObject(HitObject* hitObject)
    : hitObject(hitObject), hit(false) {}

void DrawableHitObject::draw(sf::RenderWindow& window) {

}

void DrawableHitObject::update(sf::Time globalTime, sf::Time deltaTime) {
    if (!hit) {
        if (constexpr float currentTime = 0; hitObject->checkHit(currentTime)) {
            onHit();
        }
    }
}

bool DrawableHitObject::isHit() const {
    return hit;
}

void DrawableHitObject::onHit() {
    hit = true;
    std::cout << "Hit object frappé !\n";
}
