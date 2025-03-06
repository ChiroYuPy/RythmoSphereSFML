//
// Created by adrian on 05/03/25.
//

#ifndef BUTTON_H
#define BUTTON_H

#include "Drawable.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <functional>

class Button : public Drawable {
public:
    Button(float x, float y, float width, float height, const sf::Font& font, unsigned int size, std::function<void()> onClick);

    void draw(sf::RenderWindow& window) override;
    void update(float deltaTime) override;
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window) override;

    bool isHovered(float mouseX, float mouseY) const;

    void setPosition(float x, float y);

private:
    sf::RectangleShape buttonShape;
    std::function<void()> onClick;
};

#endif //BUTTON_H
