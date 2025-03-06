//
// Created by adrian on 05/03/25.
//

#ifndef LABEL_H
#define LABEL_H

#include "Drawable.h"
#include <SFML/Graphics.hpp>
#include <string>

class Label : public Drawable {
public:
    Label(const std::string& text, float x, float y, const sf::Font& font, unsigned int size);

    void draw(sf::RenderWindow& window) override;
    void update(float deltaTime) override;
    void handleEvent(const sf::Event& event, const sf::RenderWindow& window) override;

    void setText(const std::string& newText);
    void setPosition(float x, float y);

private:
    sf::Text labelText;
};

#endif //LABEL_H
