#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Collision.h"
#include "Ball.h"
#include "Sound.h"
#include "Paddle.h"
#include "Brick.h"
#include "Config.h"

class Game
{
private:
    sf::RenderWindow window;
    Ball ball;
    Paddle paddle;
    Brick bricks[LAYER_COUNT][BRICK_COUNT_PER_LAYER];
    Sound sound;
public:
    Game();
    void run_game();
    void start_game();
    void handle_events();
    void update();
    void render();
};