//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <SFML/Graphics.hpp>

#include "../graphics/Drawable.h"

class Game;

class Scene {
protected:
    std::vector<std::shared_ptr<Drawable>> drawables;

public:
    virtual ~Scene() = default;

    virtual void onEnter() = 0;                             // on entering scene
    virtual void onExit() = 0;                              // on exiting scene
    virtual void initialize() = 0;                          // on application starting ( after game initialization )
    virtual void update(sf::Time globalTime, sf::Time deltaTime) = 0;               // on application update
    virtual void handleEvent(const sf::Event& event, const sf::RenderWindow& window) = 0;   // on window event
};

#endif //SCENE_H
