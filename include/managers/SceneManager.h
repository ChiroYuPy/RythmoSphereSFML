//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <memory>
#include <map>

#include "../scenes/Scene.h"
#include "../scenes/SceneType.h"

class SceneManager {
public:
    SceneManager();

    void changeScene(SceneType sceneType);
    std::shared_ptr<Scene> getCurrentScene();

private:
	std::shared_ptr<Scene> currentScene;
    std::map<SceneType, std::shared_ptr<Scene>> sceneCache;
};

#endif //SCENEMANAGER_H
