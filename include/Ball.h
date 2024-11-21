#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <cmath>
#include "Ball.h"
#include "Config.h"
#include "Sound.h"
#include "Object.h"

class Ball
{
private:
    sf::CircleShape m_ball;
    sf::SoundBuffer buffer;
    Sound sound;

public:
    int m_radius;
    float m_vx; // horizontal velocity
    float m_vy; // vertical velocity
    float m_x;  // horizontal position
    float m_y;  // vertical position
    bool m_ball_move = false;
    Ball();
    void draw_ball(sf::RenderWindow &window);
    void move_ball(Object &object);
    void start_ball();
    sf::CircleShape get_shape();
    sf::FloatRect get_bounds();
};