//
// Created by adrian on 05/03/25.
//

#include <iostream>

#include "rythmosphere/graphics/drawables/DrawableHitObject.h"

DrawableHitObject::DrawableHitObject()
    : hit(false) {}

void DrawableHitObject::draw(sf::RenderWindow& window) {

}

void DrawableHitObject::update(sf::Time globalTime, sf::Time deltaTime) {

}

bool DrawableHitObject::isHit() const {
    return hit;
}

void DrawableHitObject::onHit() {
    hit = true;
    std::cout << "Hit object frappé !\n";
}
