//
// Created by adrian on 01/04/25.
//

#include "core/graphics/drawables/layouts/AnchorLayout.h"

#include <iostream>

void AnchorLayout::arrange(std::vector<std::shared_ptr<Drawable>>& children, int parentX, int parentY, int parentWidth, int parentHeight) {
    for (const auto& child : children) {
        const sf::Vector2f relative = anchorToRelative(child->getAnchor());
        child->setPosition({relative.x * parentWidth, relative.y * parentHeight});
    }
}
