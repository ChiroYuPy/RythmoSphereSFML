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

    void loadMusic(const std::string& file);
    void playMusic();
    void pauseMusic();
    void stopMusic();
    float getSongPosition() const;

private:
    Game& game;
    sf::Music music;
};

#endif //AUDIOMANAGER_H
