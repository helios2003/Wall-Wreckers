#include "Brick.h"

Brick::Brick()
{
    m_object.setSize(sf::Vector2f(BRICK_WIDTH, BRICK_HEIGHT));
    m_object.setOutlineColor(sf::Color::White);
}

Brick::Brick(float x, float y, sf::Color color) : Brick() 
{
    m_object.setFillColor(color);
    m_object.setOutlineThickness(1.0f);
    m_object.setPosition(x, y);
};
