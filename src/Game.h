//
// Created by adrian on 26/02/25.
//

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "GameManager.h"
#include "Renderer.h"

class Game {
public:
    Game();

    void run();

    sf::RenderWindow& getRenderWindow() { return window; };

private:
    void processEvents();

    void update(float deltaTime);

    void render();

    GameManager& gameManager = GameManager::getInstance();
    Renderer renderer = Renderer();

    sf::RenderWindow window;
    sf::Clock clock;
    bool gameRunning;
};

#endif // GAME_H
