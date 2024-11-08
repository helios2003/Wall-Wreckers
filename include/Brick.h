#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Config.h"

class Brick : public Object
{
public:
    Brick();
    Brick(float x, float y, sf::Color color);
};