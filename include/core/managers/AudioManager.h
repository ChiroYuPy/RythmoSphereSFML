//
// Created by adrian on 05/03/25.
//

#pragma once

#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

class Game;

#include <string>
#include <SFML/Audio.hpp>

class AudioManager {
public:
    explicit AudioManager(Game& game);
    ~AudioManager();

    bool loadMusic(const std::string& filepath);

    void play();
    void pause();
    void stop();

    void setTime(sf::Time time);
    sf::Time getTime() const;
    void setLatency(sf::Time latency);

    void setVolume(float volume);

private:
    Game& game;
    sf::Music music;
    sf::Time latency;
};

#endif //AUDIOMANAGER_H
