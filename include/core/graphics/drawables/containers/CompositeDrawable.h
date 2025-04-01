//
// Created by adrian on 17/03/25.
//

#ifndef COMPOSITEDRAWABLE_H
#define COMPOSITEDRAWABLE_H

#include <iostream>

#include "../../Drawable.h"



class CompositeDrawable : public Drawable {
protected:
    std::vector<std::shared_ptr<Drawable>> children;

public:
    void addChild(const std::shared_ptr<Drawable>& drawable) {
        children.push_back(drawable);
        drawable->setParent(this);
    }

    void clearChild() { children.clear(); }

    std::vector<std::shared_ptr<Drawable>>& getChildren() { return children; }

    void draw(sf::RenderWindow& window) override {
        for (const auto& child : children) {
            child->draw(window);
        }
    }

    void update(const sf::Time deltaTime) override {
        Drawable::update(deltaTime);
        for (const auto& child : children) {
            child->update(deltaTime);
        }
    }
};

#endif //COMPOSITEDRAWABLE_H
