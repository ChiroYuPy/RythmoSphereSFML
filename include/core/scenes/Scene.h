//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>

class Game;

class Scene {
public:
    virtual ~Scene() = default;

    virtual void initialize() = 0;                          // on application starting ( after game initialization )
    virtual void update(float deltaTime) = 0;               // on application update
    virtual void handleEvent(const sf::Event& event) = 0;   // on window event
    virtual void onEnter() = 0;                             // on entering scene
    virtual void onExit() = 0;                              // on exiting scene
};

#endif //SCENE_H
