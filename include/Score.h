#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Config.h"

class Score
{
private:
    sf::Font m_font;
    sf::Text m_text;
    
public:
    int m_score = 0;
    Score();
    void draw_score(sf::RenderWindow& window);
    void increase_score();
    void decrease_score();
    void update_score_text();
};