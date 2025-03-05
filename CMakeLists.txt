cmake_minimum_required(VERSION 3.30)
project(RythmoSphere)

set(CMAKE_CXX_STANDARD 20)

# find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
find_package(SFML 2.6 COMPONENTS graphics window system audio REQUIRED)

add_executable(RythmoSphere
        main.cpp
        src/core/Game.cpp
        src/graphics/DrawableHitObject.cpp
        src/managers/AudioManager.cpp
        src/managers/GraphicsManager.cpp
        src/managers/SceneManager.cpp
        src/managers/TimeManager.cpp
        src/scenes/GameScene.cpp
        src/scenes/MainScene.cpp
)

target_link_libraries(RythmoSphere sfml-graphics sfml-window sfml-system sfml-audio)