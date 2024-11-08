#pragma once

#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Object.h"

bool check_collision(Ball &ball, Object &object);
void calculate_collision(Ball& ball, Object& object);
