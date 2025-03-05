//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <memory>
#include <SFML/Graphics.hpp>

#include "Scene.h"
#include "../graphics/Drawable.h"
#include "../graphics/DrawableHitObject.h"

class GameScene final : public Scene {
public:
    GameScene() = default;

    void initialize() override;
    void update(float deltaTime) override;
    void render() override;
    void onEnter() override;
    void onExit() override;

private:
    std::vector<std::shared_ptr<Drawable>> drawables;
    std::vector<std::shared_ptr<DrawableHitObject>> hitObjects;
    float songPosition;
};

#endif //GAMESCENE_H
