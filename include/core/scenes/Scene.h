//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef SCENE_H
#define SCENE_H

class Scene {
public:
    virtual ~Scene() = default;

    virtual void initialize() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render() = 0;
    virtual void onEnter() = 0;
    virtual void onExit() = 0;
};

#endif //SCENE_H
