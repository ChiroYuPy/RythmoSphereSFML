//
// Created by adrian on 17/03/25.
//

#ifndef COMPOSITEDRAWABLE_H
#define COMPOSITEDRAWABLE_H

#include "../../Drawable.h"



class CompositeDrawable : public Drawable {
protected:
    std::vector<std::shared_ptr<Drawable>> children;

public:
    void addInternal(std::shared_ptr<Drawable> drawable) {
        children.push_back(drawable);
        drawable->setParent(this);
    }

    void draw(sf::RenderWindow& window) override {
        for (auto& child : children) {
            child->draw(window);  // Dessiner chaque élément contenu
        }
    }

    void update(sf::Time deltaTime) override {
        for (auto& child : children) {
            child->update(deltaTime);  // Mettre à jour chaque élément
        }
    }
};




#endif //COMPOSITEDRAWABLE_H
