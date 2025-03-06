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
    Button(const std::string& text, float x, float y, const sf::Font& font, unsigned int size,
           std::function<void()> onClick);

    void draw(sf::RenderWindow& window) const override;
    void update(float deltaTime) override;

    bool isHovered(float mouseX, float mouseY) const;

    void handleClick(float mouseX, float mouseY) const;

    void setPosition(float x, float y);

private:
    sf::RectangleShape buttonShape;
    sf::Text buttonText;
    std::function<void()> onClick;  // Fonction callback appelée lors d'un clic
};

#endif //BUTTON_H
