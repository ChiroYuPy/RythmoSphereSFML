//
// Created by adrian on 01/04/25.
//

#include "core/graphics/drawables/layouts/HBoxLayout.h"

void HBoxLayout::arrange(std::vector<std::shared_ptr<Drawable>>& children, int parentX, int parentY, int parentWidth, int parentHeight) {
    int currentX = parentX;
    int maxHeight = 0;

    for (auto& child : children) {
        child->setPosition({static_cast<float>(currentX), static_cast<float>(parentY)});

        currentX += child->getSize().x;
        maxHeight = std::max(maxHeight, static_cast<int>(child->getSize().y));
    }

    parentWidth = currentX - parentX;
    parentHeight = maxHeight;
}
