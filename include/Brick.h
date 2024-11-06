#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"

class Brick : public Object
{
public:
    Brick(float x, float y, sf::Color color);
};