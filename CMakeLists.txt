cmake_minimum_required(VERSION 3.30)
project(RythmoSphere)

set(CMAKE_CXX_STANDARD 26)

find_package(SFML 2.6.1 COMPONENTS graphics window system audio REQUIRED)

add_executable(RythmoSphere
        main.cpp
        src/core/Game.cpp
        src/core/managers/AudioManager.cpp
        src/core/managers/ConfigManager.cpp
        src/core/managers/SceneManager.cpp
        src/core/managers/TimeManager.cpp
        src/core/scenes/GameScene.cpp
        src/core/scenes/MainScene.cpp
        src/core/objects/HitObject.cpp
        src/core/objects/HitCircle.cpp
        src/core/graphics/drawables/DrawableHitObject.cpp
        src/core/graphics/drawables/DrawableHitCircle.cpp
        src/core/graphics/drawables/Label.cpp
        src/core/graphics/drawables/Circle.cpp
        src/core/graphics/drawables/Box.cpp
        src/core/graphics/drawables/BoxButton.cpp
        src/core/graphics/drawables/Container.cpp
        src/core/graphics/Button.cpp
        src/core/transform/Transformable.cpp
        src/core/transform/Animator.cpp
        src/core/transform/Animation.cpp
)
target_link_libraries(RythmoSphere
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)