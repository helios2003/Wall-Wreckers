#pragma once

#include <SFML/Graphics.hpp>
#include "Object.h"

class Paddle : public Object
{
private:
    float m_position;
    sf::RectangleShape m_paddle;
public:
    bool m_paddle_move = false;
    Paddle();
    void move_left();
    void move_right();
};
