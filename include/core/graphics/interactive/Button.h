//
// Created by adrian on 05/03/25.
//

#ifndef BUTTON_H
#define BUTTON_H

#include "InteractiveUI.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <functional>
#include <iostream>

class Button : public InteractiveUI {
public:
    virtual ~Button() = default;

    virtual bool contains(float x, float y) = 0;

    void setOnClick(const std::function<void()> &action) {
        onClick = action;
    }

    void handleEvent(const sf::Event& event) override {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y))) {
                if (onClick) {
                    onClick();
                }
            }
        }
    }

private:
    std::function<void()> onClick;
};

#endif //BUTTON_H
