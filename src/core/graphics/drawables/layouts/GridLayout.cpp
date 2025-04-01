//
// Created by adrian on 01/04/25.
//

#include "core/graphics/drawables/layouts/GridLayout.h"

void GridLayout::arrange(std::vector<std::shared_ptr<Drawable>>& children, int parentX, int parentY, int parentWidth, int parentHeight) {
    int currentX = parentX;
    int currentY = parentY;
    int maxRowHeight = 0;
    int count = 0;

    for (auto& child : children) {
        child->setPosition({static_cast<float>(currentX), static_cast<float>(currentY)});

        maxRowHeight = std::max(maxRowHeight, static_cast<int>(child->getSize().y));
        currentX += child->getSize().x;

        count++;
        if (count % columns == 0) {
            currentX = parentX;
            currentY += maxRowHeight;
            maxRowHeight = 0;
        }
    }

    parentWidth = currentX - parentX;
    parentHeight = currentY - parentY;
}
