//
// Created by adrian on 01/04/25.
//

#ifndef PANEL_H
#define PANEL_H

#include "Container.h"

class Panel final : public Container {
public:
    explicit Panel(std::unique_ptr<LayoutBehavior> layoutBehavior = nullptr) : Container(std::move(layoutBehavior)) {}

    void draw(sf::RenderWindow& window) override;

protected:
    sf::RectangleShape rect;
};

#endif //PANEL_H
