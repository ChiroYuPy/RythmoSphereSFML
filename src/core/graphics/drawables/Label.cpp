//
// Created by adrian on 05/03/25.
//

#include "../../../../include/core/graphics/drawables/Label.h"

Label::Label(const std::string& text, const sf::Font& font, const unsigned int size) {
    labelText.setString(text);
    labelText.setFont(font);
    labelText.setCharacterSize(size);
}

void Label::draw(sf::RenderWindow& window) {
    const sf::FloatRect bounds = labelText.getLocalBounds();
    const sf::Vector2f originPosition = computeAnchor(origin);
    labelText.setOrigin({originPosition.x * bounds.width, originPosition.y * bounds.height});
    if (parent) {
        labelText.setPosition(parent->getAbsolutePosition(getPosition()));
        labelText.setRotation(parent->getRotation() + getRotation());
        labelText.setScale({parent->getScale().x * getScale().x, parent->getScale().y * getScale().y});
    } else {
        labelText.setPosition(getPosition());
        labelText.setRotation(getRotation());
        labelText.setScale(getScale());
    }
    labelText.setFillColor(color);
    window.draw(labelText);
}

void Label::update(sf::Time globalTime, sf::Time deltaTime) {

}

void Label::setText(const std::string& newText) {
    labelText.setString(newText);
}