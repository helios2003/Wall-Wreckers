#pragma once

#include "Brick.h"

#define BALL_RADIUS 15
#define HORIZONTAL_VELOCITY 4.0f
#define VERTICAL_VELOCITY 4.0f
#define HORIZONTAL_POSITION 600.0f

#define PADDLE_HEIGHT 20.0f
#define PADDLE_WIDTH 250.0f
#define DISTANCE 10.0f

#define WINDOW_HEIGHT 800.0f
#define WINDOW_WIDTH 1200.0f

const int BRICK_COUNT_PER_LAYER = 24; 
const int LAYER_COUNT = 3; 

inline Brick bricks[LAYER_COUNT][BRICK_COUNT_PER_LAYER] = {
    {
        Brick(0, 50, sf::Color::Red), Brick(50, 50, sf::Color::Red), Brick(100, 50, sf::Color::Red), Brick(150, 50, sf::Color::Red),
        Brick(200, 50, sf::Color::Red), Brick(250, 50, sf::Color::Red), Brick(300, 50, sf::Color::Red), Brick(350, 50, sf::Color::Red),
        Brick(400, 50, sf::Color::Red), Brick(450, 50, sf::Color::Red), Brick(500, 50, sf::Color::Red), Brick(550, 50, sf::Color::Red),
        Brick(600, 50, sf::Color::Red), Brick(650, 50, sf::Color::Red), Brick(700, 50, sf::Color::Red), Brick(750, 50, sf::Color::Red),
        Brick(800, 50, sf::Color::Red), Brick(850, 50, sf::Color::Red), Brick(900, 50, sf::Color::Red), Brick(950, 50, sf::Color::Red),
        Brick(1000, 50, sf::Color::Red), Brick(1050, 50, sf::Color::Red), Brick(1100, 50, sf::Color::Red), Brick(1150, 50, sf::Color::Red)
    },
    {
        Brick(0, 80, sf::Color::Green), Brick(50, 80, sf::Color::Green), Brick(100, 80, sf::Color::Green), Brick(150, 80, sf::Color::Green),
        Brick(200, 80, sf::Color::Green), Brick(250, 80, sf::Color::Green), Brick(300, 80, sf::Color::Green), Brick(350, 80, sf::Color::Green),
        Brick(400, 80, sf::Color::Green), Brick(450, 80, sf::Color::Green), Brick(500, 80, sf::Color::Green), Brick(550, 80, sf::Color::Green),
        Brick(600, 80, sf::Color::Green), Brick(650, 80, sf::Color::Green), Brick(700, 80, sf::Color::Green), Brick(750, 80, sf::Color::Green),
        Brick(800, 80, sf::Color::Green), Brick(850, 80, sf::Color::Green), Brick(900, 80, sf::Color::Green), Brick(950, 80, sf::Color::Green),
        Brick(1000, 80, sf::Color::Green), Brick(1050, 80, sf::Color::Green), Brick(1100, 80, sf::Color::Green), Brick(1150, 80, sf::Color::Green)
    },
    {
        Brick(0, 110, sf::Color::Blue), Brick(50, 110, sf::Color::Blue), Brick(100, 110, sf::Color::Blue), Brick(150, 110, sf::Color::Blue),
        Brick(200, 110, sf::Color::Blue), Brick(250, 110, sf::Color::Blue), Brick(300, 110, sf::Color::Blue), Brick(350, 110, sf::Color::Blue),
        Brick(400, 110, sf::Color::Blue), Brick(450, 110, sf::Color::Blue), Brick(500, 110, sf::Color::Blue), Brick(550, 110, sf::Color::Blue),
        Brick(600, 110, sf::Color::Blue), Brick(650, 110, sf::Color::Blue), Brick(700, 110, sf::Color::Blue), Brick(750, 110, sf::Color::Blue),
        Brick(800, 110, sf::Color::Blue), Brick(850, 110, sf::Color::Blue), Brick(900, 110, sf::Color::Blue), Brick(950, 110, sf::Color::Blue),
        Brick(1000, 110, sf::Color::Blue), Brick(1050, 110, sf::Color::Blue), Brick(1100, 110, sf::Color::Blue), Brick(1150, 110, sf::Color::Blue)
    }
};
