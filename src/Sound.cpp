#include "Sound.h"

Sound::Sound()
{
    countdown_buffer.loadFromFile("assets/sound/countdown.wav");
    countdown_sound.setBuffer(countdown_buffer);

    brick_collision_buffer.loadFromFile("assets/sound/brick_collision.wav");
    brick_collision_sound.setBuffer(brick_collision_buffer);

    paddle_collision_buffer.loadFromFile("assets/sound/paddle_collision.wav");
    paddle_collision_sound.setBuffer(paddle_collision_buffer);

    failure_buffer.loadFromFile("assets/sound/failure.wav");
    failure_sound.setBuffer(failure_buffer);
}

void Sound::sound_countdown()
{
    countdown_sound.play();
}

void Sound::sound_brick_collision()
{
    brick_collision_sound.play();
}

void Sound::sound_paddle_collision()
{
    paddle_collision_sound.play();
}

void Sound::sound_failure()
{
    failure_sound.play();
}