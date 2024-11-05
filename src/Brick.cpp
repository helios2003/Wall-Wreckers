#include <SFML/Graphics.hpp>
#include "Brick.h"

Brick::Brick(float x, float y, sf::Color color)
{
    m_object.setSize(sf::Vector2f(50.0f, 20.0f));
    m_object.setFillColor(color);
    m_object.setOutlineColor(sf::Color::White);
    m_object.setOutlineThickness(1.0f);
    m_object.setPosition(x, y);
};
