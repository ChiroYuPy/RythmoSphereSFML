//
// Created by adrian on 06/03/25.
//

#ifndef TRANSFORMABLE_H
#define TRANSFORMABLE_H

#include <SFML/Graphics/Transform.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>
#include <functional>

#include "Animator.h"
#include "Animation.h"

class Transformable {
protected:
    Animator animator;
    Transformable* parent = nullptr;

    sf::Vector2f position;
    float rotation;
    sf::Vector2f scale;

public:
    Transformable() noexcept;

    virtual ~Transformable() noexcept = default;

    virtual void update(sf::Time deltaTime);

    void setParent(Transformable* newParent);

    [[nodiscard]] sf::Transform getGlobalTransform() const;

    sf::Vector2f getAbsolutePosition(const sf::Vector2f &localPosition) const;

    void moveTo(const sf::Vector2f& target, float duration, const std::function<float(float)>& easingFunc = Easing::EaseLinear) noexcept;
    void rotateTo(float targetRotation, float duration, const std::function<float(float)>& easingFunc = Easing::EaseLinear) noexcept;
    void scaleTo(const sf::Vector2f& targetScale, float duration, const std::function<float(float)>& easingFunc = Easing::EaseLinear) noexcept;

    [[nodiscard]] const sf::Vector2f& getPosition() const noexcept;
    void setPosition(const sf::Vector2f& newPosition) noexcept;

    [[nodiscard]] float getRotation() const noexcept;
    void setRotation(float newRotation) noexcept;

    [[nodiscard]] const sf::Vector2f& getScale() const noexcept;
    void setScale(const sf::Vector2f& newScale) noexcept;
};

#endif // TRANSFORMABLE_H
