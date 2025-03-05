//
// Created by adrian on 05/03/25.
//

#include "../../../include/core/graphics/Label.h"

Label::Label(const std::string& text, float x, float y, const sf::Font& font, unsigned int size) {
    labelText.setString(text);
    labelText.setFont(font);
    labelText.setCharacterSize(size);
    labelText.setPosition(x, y);
}

void Label::draw(sf::RenderWindow& window) const {
    window.draw(labelText);
}

void Label::update(float deltaTime) {

}

void Label::setText(const std::string& newText) {
    labelText.setString(newText);
}

void Label::setPosition(float x, float y) {
    labelText.setPosition(x, y);
}