#include "Ball.h"
#include <cmath>

Ball::Ball() : m_moving(false), m_radius(BALL_RADIUS), m_vx(HORIZONTAL_VELOCITY),
               m_vy(VERTICAL_VELOCITY), m_x(HORIZONTAL_POSITION),
               m_y(WINDOW_HEIGHT - PADDLE_HEIGHT - 2 * BALL_RADIUS)
{
    m_ball.setFillColor(sf::Color::White);
    m_ball.setRadius(m_radius);
    m_ball.setPosition(m_x, m_y);
}

void Ball::draw_ball(sf::RenderWindow &window)
{
    window.draw(m_ball);
}

void Ball::move_ball(Object &object)
{
    if (m_moving)
    {
        m_x += m_vx;
        m_y += m_vy;
        m_ball.setPosition(m_x, m_y);
    }
}

void Ball::start_ball()
{
    m_moving = true;
}

sf::CircleShape Ball::get_shape()
{
    return m_ball;
}
