#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Config.h"

Paddle::Paddle() : m_position((WINDOW_WIDTH - ((PADDLE_WIDTH) / 2.0f)) / 2.0f)
{
    m_object.setFillColor(sf::Color::Red);
    m_object.setSize(sf::Vector2f(PADDLE_WIDTH, PADDLE_WIDTH));
    m_object.setPosition(m_position, WINDOW_HEIGHT - PADDLE_HEIGHT);
};

void Paddle::move_left()
{
    m_position -= DISTANCE;
    if (m_position < 0.0f)
    {
        m_position = 0.0f;
    }
    m_object.setPosition(m_position, WINDOW_HEIGHT - PADDLE_HEIGHT);
}

void Paddle::move_right()
{
    m_position += DISTANCE;
    if (m_position + m_object.getSize().x > WINDOW_WIDTH)
    {
        m_position = WINDOW_WIDTH - m_object.getSize().x;
    }
    m_object.setPosition(m_position, WINDOW_HEIGHT - PADDLE_HEIGHT);
}
