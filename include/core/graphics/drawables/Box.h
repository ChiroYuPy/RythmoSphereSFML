//
// Created by adrian on 06/03/25.
//

#ifndef BOX_H
#define BOX_H

#include "../Drawable.h"

class Box : public Drawable {
public:
    Box(const float x, const float y, const float width, const float height)
        : position(x, y), width(width), height(height) {}

    void draw(sf::RenderWindow& window) override {
        sf::RectangleShape rect(sf::Vector2f(width, height));
        rect.setPosition(position);
        rect.setFillColor(sf::Color::Green);
        window.draw(rect);
    }

protected:
    sf::Vector2f position;
    float width, height;
};

#endif //BOX_H
