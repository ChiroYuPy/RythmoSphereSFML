cmake_minimum_required(VERSION 3.30)
project(RythmoSphereSFML)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
find_package(SFML 2.6 COMPONENTS graphics window system audio REQUIRED)

add_executable(RythmoSphereSFML
        src/main.cpp
        src/Game.cpp
        src/GameManager.cpp
        src/Playground.cpp
        src/Renderer.cpp
        src/TextureManager.cpp
        src/Parser.cpp
        src/Beatmap.cpp
        src/HitObject.cpp
)

target_link_libraries(RythmoSphereSFML sfml-graphics sfml-window sfml-system sfml-audio)