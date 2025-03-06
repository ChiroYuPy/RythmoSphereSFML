cmake_minimum_required(VERSION 3.30)
project(RythmoSphere)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.6.1 COMPONENTS graphics window system audio REQUIRED)

add_executable(RythmoSphere
        main.cpp
        src/core/Game.cpp
        src/core/managers/AudioManager.cpp
        src/core/managers/ConfigManager.cpp
        src/core/managers/GraphicsManager.cpp
        src/core/managers/SceneManager.cpp
        src/core/managers/TimeManager.cpp
        src/core/scenes/GameScene.cpp
        src/core/scenes/MainScene.cpp
        src/core/objects/HitObject.cpp
        src/core/objects/HitCircle.cpp
        src/core/graphics/DrawableHitObject.cpp
        src/core/graphics/DrawableHitCircle.cpp
        src/core/graphics/Label.cpp
        src/core/graphics/Button.cpp
        src/core/transform/Transform.cpp
        src/core/transform/Transformable.cpp
)
target_link_libraries(RythmoSphere sfml-graphics sfml-window sfml-system sfml-audio)