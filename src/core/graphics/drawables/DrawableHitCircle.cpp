//
// Created by adrian on 05/03/25.
//

#include <iostream>

#include "../../../../include/core/graphics/drawables/DrawableHitCircle.h"

DrawableHitCircle::DrawableHitCircle(HitCircle& hitCircle) : hitCircle(hitCircle) {}

void DrawableHitCircle::draw(sf::RenderWindow& window) {
    const auto* circle = &hitCircle;

    circleShape.setRadius(circle->getRadius());
    circleShape.setOrigin(circle->getRadius(), circle->getRadius());
    if (parent) {
        circleShape.setPosition(parent->getAbsolutePosition(getPosition()));
        circleShape.setRotation(parent->getRotation() + getRotation());
        circleShape.setScale({parent->getScale().x * getScale().x, parent->getScale().y * getScale().y});
    } else {
        circleShape.setPosition(getPosition());
        circleShape.setRotation(getRotation());
        circleShape.setScale(getScale());
    }
    circleShape.setFillColor(color);
    window.draw(circleShape);
}



void DrawableHitCircle::update(const sf::Time globalTime, const sf::Time deltaTime) {
    DrawableHitObject::update(globalTime, deltaTime);
}