#include <SFML/Graphics.hpp>
#include "Object.h"

void Object::draw_object(sf::RenderWindow& window)
{
    window.draw(m_object);
}

sf::RectangleShape Object::get_shape()
{
    return m_object;
}
