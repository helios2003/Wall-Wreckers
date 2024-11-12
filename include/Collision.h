#pragma once

#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Object.h"
#include "Paddle.h"

namespace Collision
{
    bool check_collision(Ball &ball, Object &object);
    void screen_collision(Ball& ball);
    void calculate_collision(Ball &ball, Object &object);
}

