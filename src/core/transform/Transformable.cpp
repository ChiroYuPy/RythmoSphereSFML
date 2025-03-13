//
// Created by adrian on 06/03/25.
//

#include <cmath>

#include "../../../include/core/transform/Transformable.h"

Transformable::Transformable() noexcept
    : rotation(0.f), scale(1.f, 1.f), anchor(Anchor::Center) {}

void Transformable::update(const sf::Time deltaTime) {
    animator.update(deltaTime);
}

void Transformable::setParent(Transformable* newParent) {
    parent = newParent;
}

sf::Vector2f Transformable::getAbsolutePosition(const sf::Vector2f& localPosition) const {
    const double theta = getRotation() * (M_PI / 180.0f);

    const float x_local = localPosition.x;
    const float y_local = localPosition.y;

    const sf::Vector2f scale = getScale();

    const float x_scaled = x_local * scale.x;
    const float y_scaled = y_local * scale.y;

    const auto sin_theta = static_cast<float>(sin(theta));
    const auto cos_theta = static_cast<float>(cos(theta));

    float x_global = getPosition().x + x_scaled * cos_theta - y_scaled * sin_theta;
    float y_global = getPosition().y + x_scaled * sin_theta + y_scaled * cos_theta;

    return {x_global, y_global};
}

sf::Vector2f Transformable::computeAnchor() const {
    float x = 0, y = 0;
    switch (origin) {
        case Anchor::TopLeft:      x = 0;   y = 0;   break;
        case Anchor::TopCenter:    x = 0.5; y = 0;   break;
        case Anchor::TopRight:     x = 1;   y = 0;   break;
        case Anchor::CenterLeft:   x = 0;   y = 0.5; break;
        case Anchor::Center:       x = 0.5; y = 0.5; break;
        case Anchor::CenterRight:  x = 1;   y = 0.5; break;
        case Anchor::BottomLeft:   x = 0;   y = 1;   break;
        case Anchor::BottomCenter: x = 0.5; y = 1;   break;
        case Anchor::BottomRight:  x = 1;   y = 1;   break;
        default:                   x = 0.5; y = 0.5; break;
    }
    return {x, y};
}

void Transformable::moveTo(const sf::Vector2f& startPosition, const sf::Vector2f& endPosition, float startTime, float duration, const std::function<float(float)>& easingFunc) noexcept {
    animator.addAnimation(std::make_unique<Animation<sf::Vector2f>>(&position, startPosition, endPosition, startTime, duration, easingFunc));
}

void Transformable::rotateTo(float startRotation, float endRotation, float startTime, float duration, const std::function<float(float)>& easingFunc) noexcept {
    animator.addAnimation(std::make_unique<Animation<float>>(&rotation, startRotation, endRotation, startTime, duration, easingFunc));
}

void Transformable::scaleTo(const sf::Vector2f& startScale, const sf::Vector2f& endScale, float startTime, float duration, const std::function<float(float)>& easingFunc) noexcept {
    animator.addAnimation(std::make_unique<Animation<sf::Vector2f>>(&scale, startScale, endScale, startTime, duration, easingFunc));
}

const sf::Vector2f& Transformable::getPosition() const noexcept { return position; }
void Transformable::setPosition(const sf::Vector2f& newPosition) noexcept { position = newPosition; }

float Transformable::getRotation() const noexcept { return rotation; }
void Transformable::setRotation(const float newRotation) noexcept { rotation = newRotation; }

const sf::Vector2f& Transformable::getScale() const noexcept { return scale; }
void Transformable::setScale(const sf::Vector2f& newScale) noexcept { scale = newScale; }

Anchor Transformable::getAnchor() const noexcept { return anchor; }
void Transformable::setAnchor(const Anchor newAnchor) noexcept { anchor = newAnchor; }

sf::Vector2f Transformable::getAnchorOffset() const noexcept { return anchorOffset; }
void Transformable::setAnchorOffset(const sf::Vector2f newAnchorOffset) noexcept { anchorOffset = newAnchorOffset; }

Anchor Transformable::getOrigin() const noexcept { return origin; }
void Transformable::setOrigin(const Anchor newOrigin) noexcept { origin = newOrigin; }