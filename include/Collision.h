#pragma once

#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Object.h"

bool check_collision(const sf::CircleShape& ball, const sf::RectangleShape& object);
void calculate_collision(Ball& ball, Object& object);
