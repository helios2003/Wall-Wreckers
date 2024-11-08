#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "Ball.h"
#include "Config.h"
#include "Sound.h"

class Ball
{
private:
    bool m_moving;
    sf::CircleShape m_ball;
    sf::SoundBuffer buffer;
    Sound sound;
public:
    int m_radius;
    float m_vx; // horizontal velocity
    float m_vy; // vertical velocity
    float m_x;  // horizontal position
    float m_y;  // vertical position
    Ball();
    void draw_ball(sf::RenderWindow &window);
    void move_ball();
    void start_ball();
    void screen_collision();
    sf::CircleShape get_shape();
    sf::FloatRect get_bounds();
};