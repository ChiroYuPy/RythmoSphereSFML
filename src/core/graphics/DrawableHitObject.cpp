//
// Created by adrian on 05/03/25.
//

#include <iostream>

#include "../../../include/core/graphics/DrawableHitObject.h"

DrawableHitObject::DrawableHitObject(HitObject* hitObject)
    : hitObject(hitObject), hit(false) {}

void DrawableHitObject::draw(sf::RenderWindow& window) {

}

void DrawableHitObject::update(float deltaTime) {
    if (!hit) {
        float currentTime = 0; // getCurrentGameTime();
        if (hitObject->checkHit(currentTime)) {
            onHit();
        }
    }
}

void DrawableHitObject::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {

}

bool DrawableHitObject::isHit() const {
    return hit;
}

void DrawableHitObject::onHit() {
    hit = true;
    std::cout << "Hit object frappé !\n";
}
