#include "Score.h"

Score::Score()
{
    m_font.loadFromFile("assets/font/stencil.ttf");
    m_text.setFont(m_font);
    m_text.setCharacterSize(24);
    m_text.setFillColor(sf::Color::White);

    sf::FloatRect textBounds = m_text.getGlobalBounds();
    m_text.setOrigin(textBounds.width, 20);
    
    std::string display_message = "Score: " + std::to_string(m_score);
    m_text.setString(display_message);

}

void Score::draw_score(sf::RenderWindow &window)
{
    m_text.setPosition(window.getSize().x - SCORE_WIDTH, SCORE_HEIGHT);
    window.draw(m_text);
}

void Score::increase_score()
{
    m_score += 20;
    update_score_text();
}

void Score::decrease_score()
{
    m_score -= 10;
    m_score = std::min(0, m_score);
    update_score_text();
}

void Score::update_score_text()
{
    std::string display_message = "Score: " + std::to_string(m_score);
    m_text.setString(display_message); 
}