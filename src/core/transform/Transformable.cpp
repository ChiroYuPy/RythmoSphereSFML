//
// Created by adrian on 06/03/25.
//

#include <cmath>

#include "../../../include/core/transform/Transformable.h"

Transformable::Transformable() noexcept
    : position(0.f, 0.f), rotation(0.f), scale(1.f, 1.f) {}

void Transformable::update(const sf::Time deltaTime) {
    animator.update(deltaTime);
}

void Transformable::setParent(Transformable* newParent) {
    parent = newParent;
}

sf::Transform Transformable::getGlobalTransform() const {
    sf::Transform transform;
    transform.translate(position);
    transform.rotate(rotation);
    transform.scale(scale);

    if (parent) return parent->getGlobalTransform() * transform;
    return transform;
}

sf::Vector2f Transformable::getAbsolutePosition(const sf::Vector2f& localPosition) const {
    const double theta = getRotation() * (M_PI / 180.0f);

    const float x_local = localPosition.x;
    const float y_local = localPosition.y;

    const auto sin_theta = static_cast<float>(sin(theta));
    const auto cos_theta = static_cast<float>(cos(theta));

    float x_global = getPosition().x + x_local * cos_theta - y_local * sin_theta;
    float y_global = getPosition().y + x_local * sin_theta + y_local * cos_theta;

    return {x_global, y_global};
}

void Transformable::moveTo(const sf::Vector2f& target, float duration, const std::function<float(float)>& easingFunc) noexcept {
    animator.addAnimation(std::make_unique<Animation<sf::Vector2f>>(&position, position, target, duration, easingFunc));
}

void Transformable::rotateTo(float targetRotation, float duration, const std::function<float(float)>& easingFunc) noexcept {
    animator.addAnimation(std::make_unique<Animation<float>>(&rotation, rotation, targetRotation, duration, easingFunc));
}

void Transformable::scaleTo(const sf::Vector2f& targetScale, float duration, const std::function<float(float)>& easingFunc) noexcept {
    animator.addAnimation(std::make_unique<Animation<sf::Vector2f>>(&scale, scale, targetScale, duration, easingFunc));
}

const sf::Vector2f& Transformable::getPosition() const noexcept {
    return position;
}

void Transformable::setPosition(const sf::Vector2f& newPosition) noexcept {
    position = newPosition;
}

float Transformable::getRotation() const noexcept {
    return rotation;
}

void Transformable::setRotation(float newRotation) noexcept {
    rotation = newRotation;
}

const sf::Vector2f& Transformable::getScale() const noexcept {
    return scale;
}

void Transformable::setScale(const sf::Vector2f& newScale) noexcept {
    scale = newScale;
}
