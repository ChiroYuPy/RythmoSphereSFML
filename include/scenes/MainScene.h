//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef MAINSCENE_H
#define MAINSCENE_H

#include "Scene.h"

class MainScene final : public Scene {
public:
    MainScene() = default;

    void initialize() override;
    void update(float deltaTime) override;
    void render() override;
    void onEnter() override;
    void onExit() override;
};

#endif //MAINSCENE_H
