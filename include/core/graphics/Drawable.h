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
    ~Drawable() override = default;

    using Transformable::Transformable;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void handleEvent(const sf::Event& event, const sf::RenderWindow& window) {}
};

#endif //DRAWABLE_H
