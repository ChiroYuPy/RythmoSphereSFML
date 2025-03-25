//
// Created by adrian on 05/03/25.
//

#include "rythmosphere/Game.h"


Game::Game() {
    window = std::make_unique<sf::RenderWindow>(sf::VideoMode(800, 600), "RythmoSphere");
    window->setFramerateLimit(330);
    FontManager::getInstance().loadFont("main", "/home/adrian/CLionProjects/RythmoSphere/assets/fonts/Rubik-Bold.ttf");

    configManager = std::make_unique<ConfigManager>(*this);
    audioManager = std::make_unique<AudioManager>(*this);
    timeManager = std::make_unique<TimeManager>(*this);
    sceneManager = std::make_unique<SceneManager>(*this);
}

void Game::run() const {
    sf::Clock globalClock;
    sf::Clock deltaClock;

    sceneManager->changeScene(SceneType::Main);

    while (window->isOpen()) {
        const sf::Time globalTime = globalClock.getElapsedTime();
        const sf::Time deltaTime = deltaClock.restart();

        sf::Event event{};
        while (window->pollEvent(event)) {
            sceneManager->getCurrentScene()->handleEvent(event, *window);
            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }

        sceneManager->update(globalTime, deltaTime);

        window->clear();
        sceneManager->render(*window);
        window->display();
    }
}

sf::RenderWindow* Game::getRenderWindow() const { return window.get(); }

ConfigManager* Game::getConfigManager() const { return configManager.get(); }
AudioManager* Game::getAudioManager() const { return audioManager.get(); }
TimeManager* Game::getTimeManager() const { return timeManager.get(); }
SceneManager* Game::getSceneManager() const { return sceneManager.get(); }