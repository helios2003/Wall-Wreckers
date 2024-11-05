#pragma once

#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"

bool check_collision(const sf::CircleShape& ball, const sf::RectangleShape& object);
