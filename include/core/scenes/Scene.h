//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef SCENE_H
#define SCENE_H

#include <memory>
#include <SFML/Graphics.hpp>

#include "../graphics/Drawable.h"
#include "../graphics/drawables/Container.h"
#include "../graphics/interactive/InteractiveUI.h"

#include <iostream>

class Game;

class Scene {
protected:
    std::vector<std::shared_ptr<InteractiveUI>> interactives;
    std::shared_ptr<Container> root;

public:
    Scene() {
        root = std::make_shared<Container>();
    }

    virtual ~Scene() = default;

    void addObject(const std::shared_ptr<Drawable>& obj) const {
        root->addChild(obj);
    }

    void clearObjects() const {
        root->clearChild();
    }

    void update(const sf::Time& currentTime, const sf::Time& deltaTime) {
        root->update(deltaTime);
        onUpdate(currentTime, deltaTime);
    }

    void render(sf::RenderWindow& window) {
        root->draw(window);
        onRender(window);
    }

    virtual void onEnter() = 0;
    virtual void onExit() = 0;
    virtual void initialize() = 0;
    virtual void onUpdate(sf::Time currentTime, sf::Time deltaTime) = 0;
    virtual void onRender(sf::RenderWindow& window) = 0;
    virtual void handleEvent(const sf::Event& event, const sf::RenderWindow& window) = 0;
};

#endif // SCENE_H
