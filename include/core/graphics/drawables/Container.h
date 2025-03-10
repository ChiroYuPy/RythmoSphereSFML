//
// Created by adrian on 06/03/25.
//

#ifndef CONTAINER_H
#define CONTAINER_H

#include "../Drawable.h"
#include <vector>
#include <memory>

class Container : public Drawable {
private:
    std::vector<std::shared_ptr<Drawable>> elements;

public:
    void addDrawable(std::shared_ptr<Drawable> drawable);

    void draw(sf::RenderWindow& window) override;
    void update(sf::Time globalTime, sf::Time deltaTime) override;
};

#endif //CONTAINER_H
