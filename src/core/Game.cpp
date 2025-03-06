//
// Created by adrian on 05/03/25.
//

#include "../../include/core/Game.h"

Game::Game()
    : graphicsManager(std::make_unique<GraphicsManager>(*this)),
      configManager(std::make_unique<ConfigManager>(*this)),
      audioManager(std::make_unique<AudioManager>(*this)),
      timeManager(std::make_unique<TimeManager>(*this)),
      sceneManager(std::make_unique<SceneManager>(*this)) {

}

void Game::run() const {
    sf::Clock globalClock;
    sf::Clock deltaClock;

    sceneManager->changeScene(SceneType::Main);
    sceneManager->changeScene(SceneType::Game);
    sceneManager->changeScene(SceneType::Main);
    sceneManager->changeScene(SceneType::Game);

    while (graphicsManager->getWindow().isOpen()) {
        const sf::Time globalTime = globalClock.getElapsedTime();
        const sf::Time deltaTime = deltaClock.restart();

        sf::Event event{};
        while (graphicsManager->getWindow().pollEvent(event)) {
            sceneManager->getCurrentScene()->handleEvent(event, graphicsManager->getWindow());
            if (event.type == sf::Event::Closed) {
                graphicsManager->getWindow().close();
            }
        }

        sceneManager->update(globalTime, deltaTime);
        graphicsManager->render();
    }
}

GraphicsManager* Game::getGraphicsManager() const { return graphicsManager.get(); };
AudioManager* Game::getAudioManager() const { return audioManager.get(); };
TimeManager* Game::getTimeManager() const { return timeManager.get(); };
SceneManager* Game::getSceneManager() const { return sceneManager.get(); };