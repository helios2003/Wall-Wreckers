#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Config.h"

class Brick : public Object
{
private:
    bool is_destroyed = false;
public:
    Brick();
    void draw_object(sf::RenderWindow& window) override;
    Brick(float x, float y, sf::Color color);
};