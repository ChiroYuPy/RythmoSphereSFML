//
// Created by adrian on 17/03/25.
//

#include "core/managers/FontManager.h"
#include "rythmosphere/scenes/menu/RythmoSphereLogo.h"

RythmoSphereLogo::RythmoSphereLogo() : isVisible(false), appearanceDuration(1024.f) {
    sf::Font& font = FontManager::getInstance().getFont("main");

    circleButton = std::make_shared<CircleButton>(40);
    addChild(circleButton);

    label = std::make_shared<Label>("RS Logo", font, 36);
    label->setScale({0.25, 0.25});
    addChild(label);

    setAnchor(Anchor::Center);

    RythmoSphereLogo::show();

}

void RythmoSphereLogo::show() {

    if (!isVisible) {
        isVisible = true;
        circleButton->colorTo(sf::Color::Black, sf::Color::Red, 0.f, appearanceDuration, Easing::EaseInOutQuad);
        label->colorTo(sf::Color::Black, sf::Color::White, 0.f, appearanceDuration, Easing::EaseInOutQuad);

        scaleTo({1, 1}, {4, 4}, 0.f, appearanceDuration, Easing::EaseInOutQuad);
        rotateTo(0, 360, 0.f, appearanceDuration, Easing::EaseInOutQuad);
    }
}

void RythmoSphereLogo::hide() {
    if (isVisible) {
        isVisible = false;
        circleButton->colorTo(sf::Color::Red, sf::Color::Black, 0.f, appearanceDuration, Easing::EaseInOutQuad);
        label->colorTo(sf::Color::White, sf::Color::Black, 0.f, appearanceDuration, Easing::EaseInOutQuad);

        scaleTo({4, 4}, {1, 1}, 0.f, appearanceDuration, Easing::EaseInOutQuad);
        rotateTo(360, 0, 0.f, appearanceDuration, Easing::EaseInOutQuad);
    }
}

bool RythmoSphereLogo::isLogoVisible() const {
    return isVisible;
}