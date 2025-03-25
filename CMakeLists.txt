cmake_minimum_required(VERSION 3.30)
project(RythmoSphere CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(SFML 2.6.1 COMPONENTS graphics window system audio REQUIRED)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp" "main.cpp")

add_executable(RythmoSphere main ${SOURCES})

target_link_libraries(RythmoSphere
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)