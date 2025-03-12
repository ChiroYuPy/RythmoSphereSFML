//
// Created by adrian on 07/03/25.
//

#ifndef CIRCLE_H
#define CIRCLE_H

#include "../Drawable.h"

class Circle : public Drawable {
public:
    Circle(float radius, sf::Color color);

    void draw(sf::RenderWindow& window) override;

protected:
    float radius;
    sf::Color color;
    sf::CircleShape circle;
};

#endif //CIRCLE_H
