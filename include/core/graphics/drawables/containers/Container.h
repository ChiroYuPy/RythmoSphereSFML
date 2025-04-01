//
// Created by adrian on 11/03/25.
//

#ifndef CONTAINER_H
#define CONTAINER_H

#include "../../Drawable.h"
#include <vector>
#include <memory>

#include "CompositeDrawable.h"

class Container : public CompositeDrawable {
protected:
    std::vector<std::shared_ptr<Drawable>> children;
    sf::Vector2f size;
    float alpha = 1.0f;
    bool enabled = true;

public:
    void draw(sf::RenderWindow& window) override;

    void update(sf::Time deltaTime) override;

    void updateLayout(sf::Time deltaTime);

    [[nodiscard]] float getAlpha() const { return alpha; }
    void setAlpha(const float newAlpha) { alpha = newAlpha; }

    [[nodiscard]] bool isEnabled() const { return enabled; }
    void setEnabled(const bool isEnabled) { enabled = isEnabled; }
};

#endif //CONTAINER_H
