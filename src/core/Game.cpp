//
// Created by adrian on 05/03/25.
//

#include "../../include/core/Game.h"

Game::Game()
    : graphicsManager(std::make_unique<GraphicsManager>()),
      audioManager(std::make_unique<AudioManager>()),
      timeManager(std::make_unique<TimeManager>()),
      sceneManager(std::make_unique<SceneManager>()) {}

void Game::run() const {
    sf::Clock clock;

    sceneManager->changeScene(SceneType::Main);

    while (graphicsManager->getWindow().isOpen()) {
        sf::Time deltaTime = clock.restart();

        sf::Event event{};
        while (graphicsManager->getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                graphicsManager->getWindow().close();
            }
        }

        sceneManager->getCurrentScene()->update(deltaTime.asSeconds());

        graphicsManager->clear();

        sceneManager->getCurrentScene()->render();

        graphicsManager->render();
    }
}

GraphicsManager* Game::getGraphicsManager() const { return graphicsManager.get(); };
AudioManager* Game::getAudioManager() const { return audioManager.get(); };
TimeManager* Game::getTimeManager() const { return timeManager.get(); };
SceneManager* Game::getSceneManager() const { return sceneManager.get(); };