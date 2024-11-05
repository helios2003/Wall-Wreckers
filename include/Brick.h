#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"

class Brick : public Object
{
private:
    //sf::RectangleShape m_brick;

public:
    Brick(float x, float y, sf::Color color);
    //void draw_object(sf::RenderWindow& window) override;
};