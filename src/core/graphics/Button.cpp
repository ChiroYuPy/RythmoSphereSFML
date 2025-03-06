//
// Created by adrian on 05/03/25.
//

#include "../../../include/core/graphics/Button.h"
#include <SFML/Window.hpp>

Button::Button(const float x, const float y, const float width, const float height, const sf::Font& font, const unsigned int size, std::function<void()> onClick) : onClick(std::move(onClick)) {
    // Initialisation du bouton
    buttonShape.setSize(sf::Vector2f(width, height));
    buttonShape.setFillColor(sf::Color::Blue);
    setPosition(x, y);
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(buttonShape);
}

void Button::update(float deltaTime) {

}

void Button::handleEvent(const sf::Event& event, const sf::RenderWindow& window) {
    if (event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        if (isHovered(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
            onClick();
        }
    }
}

bool Button::isHovered(float mouseX, float mouseY) const {
    return buttonShape.getGlobalBounds().contains(mouseX, mouseY);
}

void Button::setPosition(float x, float y) {
    buttonShape.setPosition(x, y);
    position = sf::Vector2f(x, y);
}