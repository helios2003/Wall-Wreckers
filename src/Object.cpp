#include <SFML/Graphics.hpp>
#include "Object.h"

void Object::draw_object(sf::RenderWindow &window)
{
    window.draw(m_object);
}

sf::RectangleShape Object::get_shape()
{
    return m_object;
}

sf::Vector2f Object::get_position() const
{
    return m_object.getPosition();
}

sf::Vector2f Object::get_size() const
{
    return m_object.getSize();
}

sf::FloatRect Object::get_bounds() const
{
    return m_object.getGlobalBounds();
}