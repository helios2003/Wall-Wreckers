#include "Ball.h"

Ball::Ball() : m_moving(false), m_radius(BALL_RADIUS), m_vx(HORIZONTAL_VELOCITY),
               m_vy(VERTICAL_VELOCITY), m_x(HORIZONTAL_POSITION), 
               m_y(WINDOW_HEIGHT - PADDLE_HEIGHT - 2 * BALL_RADIUS)
{
    m_ball.setFillColor(sf::Color::White);
    m_ball.setRadius(m_radius);
    m_ball.setPosition(m_x, m_y);
};

void Ball::draw_ball(sf::RenderWindow &window)
{
    window.draw(m_ball);
}

void Ball::move_ball()
{
    if (m_moving)
    {
        m_x -= m_vx;
        m_y -= m_vy;

        screen_collision();

        m_ball.setPosition(m_x, m_y);
    }
}

void Ball::start_ball()
{
    m_moving = true;
}

void Ball::screen_collision()
{

    // left and right screen
    if (m_x <= 0 || m_x + 2 * BALL_RADIUS >= WINDOW_WIDTH)
    {
        m_vx *= -1;
        sound.sound_paddle_collision();
    }
    // top screen
    if (m_y + 2 * BALL_RADIUS <= 0 || m_y >= WINDOW_HEIGHT)
    {
        m_vy *= -1;
        sound.sound_paddle_collision();
    }
}

sf::CircleShape Ball::get_shape()
{
    return m_ball;
}