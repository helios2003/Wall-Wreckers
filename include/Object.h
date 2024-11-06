#pragma once
#include <SFML/Graphics.hpp>

class Object
{
protected:
    float m_position;
    sf::RectangleShape m_object;

public:
    void draw_object(sf::RenderWindow &window);
    sf::RectangleShape get_shape();
    sf::Vector2f get_position() const;
    sf::Vector2f get_size() const;
};