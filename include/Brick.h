#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Config.h"

class Brick : public Object
{
public:
    Brick();
    bool is_destroyed = false;
    void draw_object(sf::RenderWindow& window) override;
    void remove_object();
    Brick(float x, float y, sf::Color color);

};