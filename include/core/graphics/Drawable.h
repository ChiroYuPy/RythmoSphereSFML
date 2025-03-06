//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SFML/Graphics.hpp>

#include "../transform/Transformable.h"

class Drawable : public Transformable {
public:
    Drawable(const float x, const float y) : position(x, y) {}
    ~Drawable() override = default;

    using Transformable::Transformable;
    virtual void draw(sf::RenderWindow& window) = 0;

    sf::Vector2f getPosition() const { return position; }
    float getX() const { return position.x; }
    float getY() const { return position.y; }

    void setPosition(const sf::Vector2f newPos) { position = newPos; }
    void setX(const float newX) { position.x = newX; }
    void setY(const float newY) { position.y = newY; }

protected:
    sf::Vector2f position;
};

#endif //DRAWABLE_H
