//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

class TimeManager {
public:
    TimeManager();

    void update();
    float getDeltaTime() const;
private:
    float lastTime;
    float deltaTime;
};

#endif //TIMEMANAGER_H
