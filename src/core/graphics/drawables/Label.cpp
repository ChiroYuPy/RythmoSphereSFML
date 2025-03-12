//
// Created by adrian on 05/03/25.
//

#include "../../../../include/core/graphics/drawables/Label.h"

Label::Label(const std::string& text, const float x, const float y, const sf::Font& font, const unsigned int size) {
    labelText.setString(text);
    labelText.setFont(font);
    labelText.setCharacterSize(size);
}

void Label::draw(sf::RenderWindow& window) {
    if (parent) {
        labelText.setPosition(parent->getPosition() + getPosition());
        labelText.setRotation(parent->getRotation() + getRotation());
        labelText.setScale({parent->getScale().x * getScale().x, parent->getScale().y * getScale().y});
    } else {
        labelText.setPosition(getPosition());
        labelText.setRotation(getRotation());
        labelText.setScale(getScale());
    }
    window.draw(labelText);
}

void Label::update(sf::Time globalTime, sf::Time deltaTime) {

}

void Label::setText(const std::string& newText) {
    labelText.setString(newText);
}

void Label::setPosition(const float x, const float y) {
    labelText.setPosition(x, y);
}