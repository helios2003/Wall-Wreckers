#include "Collision.h"

void Collision::screen_collision(Ball &ball)
{
    if (ball.m_x <= 0 || ball.m_x + 2 * ball.m_radius >= WINDOW_WIDTH)
    {
        ball.m_vx *= -1;
    }

    if (ball.m_y <= 0)
    {
        ball.m_vy *= -1;
    }
}

bool Collision::check_collision(Ball &ball, Object &object)
{
    sf::FloatRect box_rect = object.get_bounds();
    float radius = ball.m_radius;

    sf::Vector2f ball_center = sf::Vector2f(ball.m_x, ball.m_y) + sf::Vector2f(radius, radius);

    float closest_x = std::max(box_rect.left,
                               std::min(ball_center.x, box_rect.left + box_rect.width));
    float closest_y = std::max(box_rect.top,
                               std::min(ball_center.y, box_rect.top + box_rect.height));

    float distance_x = ball_center.x - closest_x;
    float distance_y = ball_center.y - closest_y;
    float distance_squared = (distance_x * distance_x) + (distance_y * distance_y);

    return distance_squared < (radius * radius);
}

void Collision::calculate_collision(Ball &ball, Object &object)
{
    sf::FloatRect box_rect = object.get_bounds();
    float radius = ball.m_radius;

    sf::Vector2f ball_center = sf::Vector2f(ball.m_x, ball.m_y) + sf::Vector2f(radius, radius);

    float closest_x = std::max(box_rect.left,
                               std::min(ball_center.x, box_rect.left + box_rect.width));

    float distance_x = ball_center.x - closest_x;

    const float half_len = PADDLE_WIDTH / 2;
    float adjustment_factor = 1.0f + (1.0f / (1.0f + std::exp(-3 * ((distance_x * 0.1f) / half_len - 0.4f)))) * 0.1f;
    float new_vy = ball.m_vy * adjustment_factor;
    ball.m_vy = -new_vy;
}