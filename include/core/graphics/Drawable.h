//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML/Graphics.hpp>

#include "../transform/Transformable.h"

class Drawable : public Transformable {
protected:
    sf::Color color;
    bool visible = true;

public:
    Drawable() noexcept : color(sf::Color::Green) {}

    void colorTo(const sf::Color& targetColor, float duration, const std::function<float(float)>& easingFunc = Easing::EaseLinear) noexcept {
        animator.addAnimation(std::make_unique<Animation<sf::Color>>(&color, color, targetColor, duration, easingFunc));
    }

    virtual void draw(sf::RenderWindow& window) = 0;

    [[nodiscard]] sf::Color getColor() const { return this->color; }
    void setColor(const sf::Color& color) { this->color = color; }

    void show() { visible = true; }
    void hide() { visible = false; }
    [[nodiscard]] bool isVisible() const { return visible; }
};

#endif //DRAWABLE_H
