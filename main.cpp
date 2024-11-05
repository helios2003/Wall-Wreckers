#include <SFML/Graphics.hpp>
#include "include/Ball.h"
#include <iostream>
#include "include/Paddle.h"
#include "include/Config.h"
#include "include/Collision.h"
#include "include/Brick.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game Window");

    Ball ball;
    Paddle paddle;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                ball.start_ball();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                paddle.move_left();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                paddle.move_right();
            }
        }

        if (check_collision(ball.get_shape(), paddle.get_shape()))
        {
            std::cout << "Collision detected! Stopping the game." << std::endl;
            break;
        }
        window.clear();
        ball.draw_ball(window);
        paddle.draw_object(window);

        for (int i = 0; i < LAYER_COUNT; ++i)
        {
            for (int j = 0; j < BRICK_COUNT_PER_LAYER; ++j)
            {
                bricks[i][j].draw_object(window);
            }
        }

        ball.move_ball();
        window.display();
    }

    return EXIT_SUCCESS;
}
