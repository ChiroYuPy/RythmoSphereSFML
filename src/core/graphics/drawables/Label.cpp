//
// Created by adrian on 05/03/25.
//

#include "../../../../include/core/graphics/drawables/Label.h"

Label::Label(const std::string& text, const float x, const float y, const sf::Font& font, const unsigned int size) {
    labelText.setString(text);
    labelText.setFont(font);
    labelText.setCharacterSize(size);
    labelText.setPosition(x, y);
}

void Label::draw(sf::RenderWindow& window) {
    window.draw(labelText);
}

void Label::update(sf::Time globalTime, sf::Time deltaTime) {

}

void Label::setText(const std::string& newText) {
    labelText.setString(newText);
}

void Label::setPosition(const float x, const float y) {
    labelText.setPosition(x, y);
    position = sf::Vector2f(x, y);
}