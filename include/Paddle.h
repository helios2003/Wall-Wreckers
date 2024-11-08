#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"

class Paddle : public Object
{
private:
    float m_position;
    sf::RectangleShape m_paddle;
    
public:
    Paddle();
    void move_left();
    void move_right();
};