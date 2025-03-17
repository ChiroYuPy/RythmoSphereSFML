#ifndef RYTHMOSPHERELOGO_H
#define RYTHMOSPHERELOGO_H

#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../../core/graphics/drawables/containers/CompositeDrawable.h"
#include "../../../core/graphics/drawables/BoxButton.h"
#include "../../../core/graphics/drawables/Circle.h"

class RythmoSphereLogo : public CompositeDrawable {
private:
    bool isVisible;                // État de visibilité du logo
    float appearanceDuration;      // Durée de l'apparition du logo
    std::shared_ptr<Circle> circle; // Exemple d'élément graphique à afficher

public:
    RythmoSphereLogo() : isVisible(false), appearanceDuration(1024.f) {
        // Initialisation du logo avec un cercle
        circle = std::make_shared<Circle>(40);
        circle->scaleTo({1, 1}, {4, 4}, 0.f, appearanceDuration, Easing::EaseInOutQuad);
        circle->setColor(sf::Color::Black);
        circle->colorTo(sf::Color::Black, sf::Color::Red, 0.f, appearanceDuration, Easing::EaseInOutQuad);

        addInternal(circle);  // Ajouter l'élément graphique à la liste
    }

    // Méthode pour afficher le logo avec animation
    void show() {
        if (!isVisible) {
            isVisible = true;
            // Animation d'apparition (par exemple, fade-in ou scale-up)
            circle->colorTo(sf::Color::Red, sf::Color::Black, 0.f, appearanceDuration, Easing::EaseInOutQuad);
            circle->scaleTo({4, 4}, {1, 1}, 0.f, appearanceDuration, Easing::EaseInOutQuad);
        }
    }

    // Méthode pour masquer le logo avec animation
    void hide() {
        if (isVisible) {
            isVisible = false;
            // Animation de disparition (par exemple, fade-out ou scale-down)
            circle->colorTo(sf::Color::Black, sf::Color::Red, 0.f, appearanceDuration, Easing::EaseInOutQuad);
            circle->scaleTo({1, 1}, {4, 4}, 0.f, appearanceDuration, Easing::EaseInOutQuad);
        }
    }

    // Méthode pour vérifier si le logo est visible
    bool isLogoVisible() const {
        return isVisible;
    }
};

#endif // RYTHMOSPHERELOGO_H
