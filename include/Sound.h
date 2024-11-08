#pragma once

#include <SFML/Audio.hpp>

class Sound
{
private:
    sf::SoundBuffer countdown_buffer;
    sf::SoundBuffer brick_collision_buffer;
    sf::SoundBuffer paddle_collision_buffer;
    sf::SoundBuffer failure_buffer;

    sf::Sound countdown_sound;
    sf::Sound brick_collision_sound;
    sf::Sound paddle_collision_sound;
    sf::Sound failure_sound;

public:
    Sound();

    void sound_countdown();
    void sound_brick_collision();
    void sound_paddle_collision();
    void sound_failure();
};