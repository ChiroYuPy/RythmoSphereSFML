//
// Created by adrian on 13/03/25.
//

#ifndef INTERACTIVEUI_H
#define INTERACTIVEUI_H

#include <SFML/Graphics.hpp>

class InteractiveUI {
  public:
    virtual ~InteractiveUI() = default;

    virtual void handleEvent(const sf::Event& event) = 0;
};

#endif //INTERACTIVEUI_H
