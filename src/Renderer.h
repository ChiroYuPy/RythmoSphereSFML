//
// Created by adrian on 27/02/25.
//

#ifndef RENDERER_H
#define RENDERER_H



#include <SFML/Graphics.hpp>
#include "GameManager.h"

class Renderer {
public:
    static void drawHitObject(sf::RenderWindow& window, const HitObject& hitObject);

    static void drawHitCircle(sf::RenderWindow &window, const HitObject &hitCircle);

    static void drawHitCircleOverlay(sf::RenderWindow &window, const HitObject &hitCircle, const sf::Color &overlayColor);
};



#endif // RENDERER_H
