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

#include "core/transform/Anchor.h"

enum class RotationMode {
    Clockwise,
    CounterClockwise
};

enum class DirectionMode {
    Horizontal,
    Vertical
};

class Transformable {
protected:
    Animator animator;

    sf::Vector2f position;
    sf::Vector2f size;
    sf::Vector2f scale;
    float rotation;
    Anchor origin;

    Transformable* parent = nullptr;
    Anchor anchor;
    sf::Vector2f anchorOffset;

public:
    Transformable() noexcept;

    virtual ~Transformable() noexcept = default;

    virtual void update(sf::Time deltaTime);

    void setParent(Transformable* newParent);

    [[nodiscard]] sf::Vector2f getAbsolutePosition(const sf::Vector2f &localPosition) const;

    [[nodiscard]] sf::Transform getTransform() const;

    [[nodiscard]] static sf::Vector2f computeAnchor(Anchor anchor) ;

    void moveTo(const sf::Vector2f &startPosition, const sf::Vector2f &endPosition, float startTime, float duration, const std::
                function<float(float)> &easingFunc = Easing::EaseLinear) noexcept;
    void rotateTo(float startRotation, float endRotation, float startTime, float duration, const std::function<float(float)> &easingFunc
                          = Easing::EaseLinear) noexcept;
    void scaleTo(const sf::Vector2f &startScale, const sf::Vector2f &endScale, float startTime, float duration, const std::function<
                 float(float)> &easingFunc = Easing::EaseLinear) noexcept;

    [[nodiscard]] const sf::Vector2f& getPosition() const noexcept;
    void setPosition(const sf::Vector2f& newPosition) noexcept;

    [[nodiscard]] float getRotation() const noexcept;
    void setRotation(float newRotation) noexcept;

    [[nodiscard]] const sf::Vector2f &getSize() const noexcept;
    void setSize(const sf::Vector2f &newSize) noexcept;

    [[nodiscard]] const sf::Vector2f& getScale() const noexcept;
    void setScale(const sf::Vector2f& newScale) noexcept;

    [[nodiscard]] Anchor getAnchor() const noexcept;
    void setAnchor(Anchor newAnchor) noexcept;

    [[nodiscard]] sf::Vector2f getAnchorOffset() const noexcept;
    void setAnchorOffset(sf::Vector2f newAnchorOffset) noexcept;

    [[nodiscard]] Anchor getOrigin() const noexcept;
    void setOrigin(Anchor newOrigin) noexcept;
};

#endif // TRANSFORMABLE_H
