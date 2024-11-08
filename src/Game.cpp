#include "Game.h"

Game::Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Wall Wreckers")
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Wall Wreckers");
    Ball ball;
    Paddle paddle;

    for (int i = 0; i < LAYER_COUNT; ++i)
    {
        for (int j = 0; j < BRICK_COUNT_PER_LAYER; ++j)
        {
            if (i == 0)
            {
                bricks[i][j] = Brick(50 * j, 50 * (i + 1), sf::Color::Red);
            }
            else if (i == 1)
            {
                bricks[i][j] = Brick(50 * j, 50 * (i + 1), sf::Color::Green);
            }
            else
            {
                bricks[i][j] = Brick(50 * j, 50 * (i + 1), sf::Color::Blue);
            }
        }
    }
}

void Game::run_game()
{
    while (window.isOpen())
    {
        handle_events();
        render();
        update();
    }
}

void Game::start_game()
{
    sf::Font font;

    font.loadFromFile("assets/font/stencil.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(60);
    text.setFillColor(sf::Color::White);

    sf::FloatRect textBounds = text.getGlobalBounds();
    text.setOrigin(textBounds.width / 2, textBounds.height / 2);
    text.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    int value = 3;
    bool is_active = true;
    sf::Clock clock;
    text.setString(std::to_string(value));
    sound.sound_countdown();

    while (is_active)
    {
        window.clear();

        if (clock.getElapsedTime().asSeconds() >= 1.0f)
        {
            value--;
            clock.restart();
        }
        if (value == 0)
        {
            text.setString("BEGIN!!");
            window.draw(text);
        }
        else if (value > -1)
        {
            text.setString(std::to_string(value));
            window.draw(text);
        }
        else
        {
            is_active = false;
            ball.start_ball();
        }

        // update the bounds
        textBounds = text.getGlobalBounds();
        text.setOrigin(textBounds.width / 2, textBounds.height / 2);
        window.display();
    }
}

void Game::handle_events()
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
            start_game();
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
}

void Game::update()
{
    ball.move_ball();
    if (check_collision(ball, paddle))
    {
        calculate_collision(ball, paddle);
    }
}

void Game::render()
{
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

    window.display();
}