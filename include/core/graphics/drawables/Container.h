//
// Created by adrian on 11/03/25.
//

#ifndef CONTAINER_H
#define CONTAINER_H

#include "../Drawable.h"
#include <vector>
#include <memory>

class Container : public Drawable {
protected:
    std::vector<std::shared_ptr<Drawable>> children;

public:
    using Drawable::Drawable;

    void addChild(const std::shared_ptr<Drawable>& child) {
        child->setParent(this);
        children.push_back(child);
    }

    void clearChild() {
        children.clear();
    };

    void draw(sf::RenderWindow& window) override;

    void update(sf::Time deltaTime) override;
};

#endif //CONTAINER_H
