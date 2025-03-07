//
// Created by adrian on 06/03/25.
//

#ifndef BOX_H
#define BOX_H

#include "../Drawable.h"

class Box : public Drawable {
public:
    Box(float width, float height, sf::Color color);

    void draw(sf::RenderWindow& window) override;

protected:
    float width, height;
    sf::Color color;
};

#endif //BOX_H
