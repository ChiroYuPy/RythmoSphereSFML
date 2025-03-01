//
// Created by adrian on 27/02/25.
//

#pragma once

#include <SFML/Graphics.hpp>

#include "Beatmap.h"
#include "HitObject.h"

#ifndef GAMEAREA_H
#define GAMEAREA_H



class Playground {
public:
    Playground();

    void draw(sf::RenderWindow *window);
    sf::Vector2f convertPlaygroundToWindowPosition(sf::Vector2f playgroundPosition) const;

    sf::Vector2f convertWindowPositionToPlayground(sf::Vector2f gameObjectPosition) const;

    void spawnHitObject(HitObjectData data);

    void setPosition(sf::Vector2f newPosition);
    void setSize(sf::Vector2f newSize);
    void setZoom(float newZoom);

    float getZoom() const;

    std::vector<HitObject *>& getObjects() { return objects; }


private:
    sf::Vector2f position;
    sf::Vector2f size;
    float zoom;

    sf::RectangleShape area;

    std::vector<HitObject *> objects;
};



#endif //GAMEAREA_H
