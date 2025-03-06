//
// Created by adrian on 05/03/25.
//

#include "../../../include/core/graphics/Button.h"
#include <SFML/Window.hpp>

Button::Button(const std::string& text, float x, float y, const sf::Font& font, unsigned int size,
               std::function<void()> onClick)
    : onClick(std::move(onClick)) {
    // Initialisation du bouton
    buttonShape.setSize(sf::Vector2f(200.f, 50.f));  // Taille par défaut
    buttonShape.setFillColor(sf::Color::Blue);
    buttonShape.setPosition(x, y);

    buttonText.setString(text);
    buttonText.setFont(font);
    buttonText.setCharacterSize(size);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setPosition(x + 10.f, y + 10.f);  // Décalage pour que le texte soit centré
}

void Button::draw(sf::RenderWindow& window) const {
    window.draw(buttonShape);
    window.draw(buttonText);
}

void Button::update(float deltaTime) {
    // Aucun besoin de mise à jour pour le bouton, mais tu pourrais ajouter des animations ici
}

bool Button::isHovered(float mouseX, float mouseY) const {
    // Vérifie si le clic est dans les limites du bouton
    return buttonShape.getGlobalBounds().contains(mouseX, mouseY);
}

void Button::handleClick(float mouseX, float mouseY) const {
    if (isHovered(mouseX, mouseY)) {
        onClick();  // Appelle la fonction callback si le bouton est cliqué
    }
}

void Button::setPosition(float x, float y) {
    buttonShape.setPosition(x, y);
    buttonText.setPosition(x + 10.f, y + 10.f);
}