//
// Created by adrian on 01/04/25.
//

#include "core/graphics/drawables/layouts/VBoxLayout.h"

void VBoxLayout::arrange(std::vector<std::shared_ptr<Drawable>>& children, int parentX, int parentY, int parentWidth, int parentHeight) {
    int currentY = parentY;
    int maxWidth = 0;

    for (auto& child : children) {
        child->setPosition({static_cast<float>(parentX), static_cast<float>(currentY)});

        currentY += child->getSize().y;
        maxWidth = std::max(maxWidth, static_cast<int>(child->getSize().x));
    }

    parentWidth = maxWidth;
    parentHeight = currentY - parentY;
}
