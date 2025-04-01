//
// Created by adrian on 11/03/25.
//

#ifndef CONTAINER_H
#define CONTAINER_H

#include "../../Drawable.h"

#include "CompositeDrawable.h"
#include "../layouts/LayoutBehavior.h"

class Container : public CompositeDrawable {
protected:
    std::unique_ptr<LayoutBehavior> layout;
    float alpha = 1.0f;
    bool enabled = true;

public:
    explicit Container(std::unique_ptr<LayoutBehavior> layoutBehavior = nullptr) : layout(std::move(layoutBehavior)) {}

    void draw(sf::RenderWindow& window) override;

    void update(sf::Time deltaTime) override;

    void updateLayout(sf::Time deltaTime);

    [[nodiscard]] float getAlpha() const { return alpha; }
    void setAlpha(const float newAlpha) { alpha = newAlpha; }

    [[nodiscard]] bool isEnabled() const { return enabled; }
    void setEnabled(const bool isEnabled) { enabled = isEnabled; }
};

#endif //CONTAINER_H
