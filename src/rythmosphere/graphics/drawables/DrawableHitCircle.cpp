//
// Created by adrian on 05/03/25.
//

#include "rythmosphere/graphics/drawables/DrawableHitCircle.h"

DrawableHitCircle::DrawableHitCircle(HitCircle& hitCircle) : hitCircle(hitCircle) {
    setColor(sf::Color::Red);
}

void DrawableHitCircle::draw(sf::RenderWindow& window) {
    constexpr int radius = 32;
    circleShape.setRadius(radius);
    circleShape.setOrigin(radius, radius);
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