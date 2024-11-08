#include "Collision.h"

bool check_collision(Ball &ball, Object &object)
{
    sf::FloatRect box_rect = object.get_bounds();
    float radius = ball.m_radius;

    sf::Vector2f ball_center = sf::Vector2f(ball.m_x, ball.m_y) + sf::Vector2f(radius, radius);

    float closest_x = std::max(box_rect.left, std::min(ball_center.x, box_rect.left + box_rect.width));
    float closest_y = std::max(box_rect.top, std::min(ball_center.y, box_rect.top + box_rect.height));

    float distance_x = ball_center.x - closest_x;
    float distance_y = ball_center.y - closest_y;
    float distance_squared = (distance_x * distance_x) + (distance_y * distance_y);

    return distance_squared < (radius * radius);
}

void calculate_collision(Ball &ball, Object &object)
{
    sf::Vector2f ball_position(ball.m_x, ball.m_y);
    sf::Vector2f ball_center = ball_position + sf::Vector2f(ball.m_radius, ball.m_radius);

    sf::Vector2f object_position = object.get_position();
    sf::Vector2f object_size = object.get_size();
    sf::Vector2f object_center(
        (object_position.x + object_size.x / 2),
        (object_position.y + object_size.y / 2));

    // Calculate the distance between the ball and the object
    float x_dis = std::abs(ball_center.x - object_center.x);
    float half_len = object_size.x / 2;

    float adjustment_factor = 1.0f + (1.0f / (1.0f + std::exp(-3 * ((x_dis * 0.1f) / half_len - 0.5f)))) * 0.1f;
    float new_vy = ball.m_vy * adjustment_factor;
    ball.m_vy = new_vy;
}