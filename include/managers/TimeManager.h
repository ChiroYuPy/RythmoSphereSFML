//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

class Game;

class TimeManager {
public:
    explicit TimeManager(Game& game);

    void update();
    float getDeltaTime() const;
private:
    Game& game;
    float lastTime;
    float deltaTime;
};

#endif //TIMEMANAGER_H
