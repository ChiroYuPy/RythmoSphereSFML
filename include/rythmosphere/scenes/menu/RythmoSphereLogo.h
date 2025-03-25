#ifndef RYTHMOSPHERELOGO_H
#define RYTHMOSPHERELOGO_H

#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../../core/managers/FontManager.h"
#include "../../../core/graphics/drawables/containers/CompositeDrawable.h"
#include "../../../core/graphics/drawables/Label.h"
#include "../../../core/graphics/drawables/Circle.h"

class RythmoSphereLogo : public CompositeDrawable {
private:
    bool isVisible;
    float appearanceDuration;
    std::shared_ptr<Circle> circle;
    std::shared_ptr<Label> label;

public:
    RythmoSphereLogo() : isVisible(false), appearanceDuration(1024.f) {
        sf::Font& font = FontManager::getInstance().getFont("main");

        circle = std::make_shared<Circle>(40);
        addInternal(circle);

        label = std::make_shared<Label>("RS Logo", font, 36);
        addInternal(label);

        show();
    }

    // Méthode pour afficher le logo avec animation
    void show() {
        if (!isVisible) {
            isVisible = true;
            circle->colorTo(sf::Color::Black, sf::Color::Red, 0.f, appearanceDuration, Easing::EaseInOutQuad);
            circle->scaleTo({1, 1}, {4, 4}, 0.f, appearanceDuration, Easing::EaseInOutQuad);
            label->colorTo(sf::Color::Black, sf::Color::White, 0.f, appearanceDuration, Easing::EaseInOutQuad);
            label->scaleTo({0.25, 0.25}, {1, 1}, 0.f, appearanceDuration, Easing::EaseInOutQuad);
        }
    }

    // Méthode pour masquer le logo avec animation
    void hide() {
        if (isVisible) {
            isVisible = false;
            // Animation de disparition (par exemple, fade-out ou scale-down)
            circle->colorTo(sf::Color::Red, sf::Color::Black, 0.f, appearanceDuration, Easing::EaseInOutQuad);
            circle->scaleTo({4, 4}, {1, 1}, 0.f, appearanceDuration, Easing::EaseInOutQuad);
            label->colorTo(sf::Color::White, sf::Color::Black, 0.f, appearanceDuration, Easing::EaseInOutQuad);
            label->scaleTo({1, 1}, {0.25, 0.25}, 0.f, appearanceDuration, Easing::EaseInOutQuad);
        }
    }

    // Méthode pour vérifier si le logo est visible
    bool isLogoVisible() const {
        return isVisible;
    }
};

#endif // RYTHMOSPHERELOGO_H
