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
    sf::FloatRect get_bounds() const { return m_paddle.getGlobalBounds(); }
    sf::Vector2f get_position() const { return m_paddle.getPosition(); }
};

// void Ball::paddle_collision(Paddle &paddle)
// {
//     sf::FloatRect paddleBounds = paddle.get_bounds();
    
//     // Ball's bottom edge and center position
//     float ball_bottom = m_y + 2 * m_radius;
//     float ball_center_x = m_x + m_radius;

//     // Check if ball is within paddle's horizontal bounds and slightly above it
//     if (ball_bottom >= paddleBounds.top && ball_bottom <= paddleBounds.top + m_radius &&
//         ball_center_x >= paddleBounds.left && ball_center_x <= paddleBounds.left + paddleBounds.width)
//     {
//         m_vy *= -1;  // Reverse the vertical direction

//         // Optional: Reposition the ball to avoid clipping
//         m_y = paddleBounds.top - 2 * m_radius;

//         sound.sound_paddle_collision();  // Play sound on collision
//     }
// } 