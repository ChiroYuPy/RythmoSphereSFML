//
// Created by adrian on 27/02/25.
//

#include "Playground.h"

#include <iostream>

#include "HitObject.h"
#include "GameManager.h"
#include "Renderer.h"

Playground::Playground() : position(0, 0), size(0, 0), zoom(1.0f) {
    area.setFillColor(sf::Color(32, 32, 32, 127));
    area.setOutlineThickness(1);
    area.setOutlineColor(sf::Color::Blue);
}

void Playground::draw(sf::RenderWindow *window) {
    GameManager& gameManager = GameManager::getInstance();

    window->draw(area);
    for (auto& gameObject : gameManager.getPlayground().getObjects()) {
        if (auto* hitCircle = dynamic_cast<Circle*>(gameObject)) {
            Renderer::drawHitObject(*window, *hitCircle);
        }
    }
}

sf::Vector2f Playground::convertPlaygroundToWindowPosition(sf::Vector2f playgroundPosition) const {

    sf::Vector2f windowPosition = area.getPosition();
    windowPosition = playgroundPosition * zoom + windowPosition;

    return windowPosition;
}

sf::Vector2f Playground::convertWindowPositionToPlayground(sf::Vector2f windowPosition) const {

    sf::Vector2f playgroundPosition = area.getPosition();
    playgroundPosition = windowPosition;

    return playgroundPosition;
}

void Playground::spawnHitObject(HitObjectData data) {
    static int count = 0;
    count++;

    objects.push_back(new Circle(data));
    std::cout << "Spawning Hit Object #" << count << std::endl;
}

void Playground::setPosition(sf::Vector2f newPosition) {
    position = newPosition;
    area.setPosition(newPosition - size * (zoom / 2));
};

void Playground::setSize(sf::Vector2f newSize) {
    size = newSize;
    area.setSize(size * zoom);
};

void Playground::setZoom(float newZoom) {
    zoom = newZoom;
    area.setSize(size * zoom);
}

float Playground::getZoom() const {
    return zoom;
}