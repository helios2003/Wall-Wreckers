#include "Game.h"

Game::Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Wall Wreckers")
{
    for (int i = 0; i < LAYER_COUNT; ++i)
    {
        for (int j = 0; j < BRICK_COUNT_PER_LAYER; ++j)
        {
            if (i == 0)
            {
                bricks[i][j] = Brick(60 * j, 60 * (i + 1), sf::Color::Red);
            }
            else if (i == 1)
            {
                bricks[i][j] = Brick(60 * j, 60 * (i + 1), sf::Color::Green);
            }
            else
            {
                bricks[i][j] = Brick(60 * j, 60 * (i + 1), sf::Color::Blue);
            }
        }
    }
}

void Game::run_game()
{
    while (window.isOpen())
    {
        handle_events();
        update();
        render();
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

    while (is_active && window.isOpen())
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

        // Update text bounds and origin
        textBounds = text.getGlobalBounds();
        text.setOrigin(textBounds.width / 2, textBounds.height / 2);

        window.draw(text);
        window.display();
    }
}

void Game::end_game()
{
    sf::Font font;
    font.loadFromFile("assets/font/stencil.ttf");

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(60);
    text.setFillColor(sf::Color::White);

    text.setString("YOU LOOSE!!");
    sf::FloatRect textBounds = text.getGlobalBounds();
    text.setOrigin(textBounds.width / 2, textBounds.height / 2);
    text.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    sf::Clock clock;
    sound.sound_failure();

    while (clock.getElapsedTime().asSeconds() < 2.0f)
    {
        window.draw(text);
        window.display();
    }
    window.close();
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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            paddle.move_left();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            paddle.move_right();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            start_game();
        }
    }
}

void Game::update()
{

    if (Collision::check_collision(ball, paddle))
    {
        Collision::calculate_collision(ball, paddle);
        score.increase_score();
    }
    if (2 * ball.m_radius + ball.m_y > WINDOW_HEIGHT)
    {
        end_game();
        return;
    }
    ball.move_ball(paddle);
    Collision::screen_collision(ball);
}

void Game::render()
{
    window.clear();
    paddle.draw_object(window);
    score.draw_score(window);

    for (int i = 0; i < LAYER_COUNT; ++i)
    {
        for (int j = 0; j < BRICK_COUNT_PER_LAYER; ++j)
        {
            bricks[i][j].draw_object(window);
        }
    }

    ball.draw_ball(window);
    window.display();
}
