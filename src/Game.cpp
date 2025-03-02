#include "Game.h"
#include "TextureManager.h"
#include <iostream>

Game::Game() : window(sf::VideoMode(1920, 1080), "RythmoSphere - SNAPSHOT 0.0.0"), gameRunning(true) {
}

void Game::run() {
    sf::Vector2u windowSize = getRenderWindow().getSize();
    sf::Vector2f size = sf::Vector2f(512, 384);
    sf::Vector2f position = sf::Vector2f(windowSize.x / 2, windowSize.y / 2);

    float deltaX = windowSize.x / size.x;
    float deltaY = windowSize.y / size.y;

    float zoom;
    if (deltaX > deltaY) {
        zoom = deltaY * 0.8f;
    } else {
        zoom = deltaX * 0.8f;
    }

    gameManager.getPlayground().setZoom(zoom);
    gameManager.getPlayground().setSize(size);
    gameManager.getPlayground().setPosition(position);

    TextureManager::loadTexture("hitCircle", "hitcircle.png");
    TextureManager::loadTexture("hitCircleOverlay", "hitcircleoverlay@2x.png");
    TextureManager::loadTexture("0", "default-0@2x.png");
    TextureManager::loadTexture("1", "default-1@2x.png");
    TextureManager::loadTexture("2", "default-2@2x.png");
    TextureManager::loadTexture("3", "default-3@2x.png");
    TextureManager::loadTexture("4", "default-4@2x.png");
    TextureManager::loadTexture("5", "default-5@2x.png");
    TextureManager::loadTexture("6", "default-6@2x.png");
    TextureManager::loadTexture("7", "default-7@2x.png");
    TextureManager::loadTexture("8", "default-8@2x.png");
    TextureManager::loadTexture("9", "default-9@2x.png");

    sf::Clock clock;
    const float targetFPS = 240.0f;
    const float frameTime = 1.0f / targetFPS;

    while (gameRunning && window.isOpen()) {
        processEvents();

        // Calcule le temps écoulé depuis le dernier frame
        float deltaTime = clock.restart().asSeconds();

        // Si le temps écoulé est plus long que le frameTime nécessaire, on met à jour et affiche
        if (deltaTime < frameTime) {
            // Si l'on veut limiter la vitesse à 240 FPS, on attend ici le temps restant
            sf::sleep(sf::seconds(frameTime - deltaTime));
        }

        update(deltaTime);
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
            }
        }
    }
}

void Game::update(float deltaTime) {
    gameManager.update(deltaTime);
}

void Game::render() {
    window.clear();
    gameManager.render(&window);
    window.display();
}
