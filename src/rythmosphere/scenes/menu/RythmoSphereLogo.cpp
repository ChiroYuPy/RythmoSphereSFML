//
// Created by adrian on 17/03/25.
//

#include "core/managers/FontManager.h"
#include "rythmosphere/scenes/menu/RythmoSphereLogo.h"

RythmoSphereLogo::RythmoSphereLogo() : isVisible(false), appearanceDuration(1024.f) {
    sf::Font& font = FontManager::getInstance().getFont("main");

    circle = std::make_shared<Circle>(40);
    addInternal(circle);

    label = std::make_shared<Label>("RS Logo", font, 36);
    addInternal(label);

    RythmoSphereLogo::show();
}

void RythmoSphereLogo::show() {
    if (!isVisible) {
        isVisible = true;
        circle->colorTo(sf::Color::Black, sf::Color::Red, 0.f, appearanceDuration, Easing::EaseInOutQuad);
        circle->scaleTo({1, 1}, {4, 4}, 0.f, appearanceDuration, Easing::EaseInOutQuad);
        label->colorTo(sf::Color::Black, sf::Color::White, 0.f, appearanceDuration, Easing::EaseInOutQuad);
        label->scaleTo({0.25, 0.25}, {1, 1}, 0.f, appearanceDuration, Easing::EaseInOutQuad);
    }
}

void RythmoSphereLogo::hide() {
    if (isVisible) {
        isVisible = false;
        circle->colorTo(sf::Color::Red, sf::Color::Black, 0.f, appearanceDuration, Easing::EaseInOutQuad);
        circle->scaleTo({4, 4}, {1, 1}, 0.f, appearanceDuration, Easing::EaseInOutQuad);
        label->colorTo(sf::Color::White, sf::Color::Black, 0.f, appearanceDuration, Easing::EaseInOutQuad);
        label->scaleTo({1, 1}, {0.25, 0.25}, 0.f, appearanceDuration, Easing::EaseInOutQuad);
    }
}

bool RythmoSphereLogo::isLogoVisible() const {
    return isVisible;
}