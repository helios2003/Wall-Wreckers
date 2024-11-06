#include "Collision.h"
#include <cmath>

bool check_collision(const sf::CircleShape &ball, const sf::RectangleShape &object)
{
    sf::FloatRect box_rect = object.getGlobalBounds();

    sf::Vector2f circle_center = ball.getPosition() + sf::Vector2f(ball.getRadius(), ball.getRadius());
    float radius = ball.getRadius();

    float closest_x = std::max(box_rect.left, std::min(circle_center.x, box_rect.left + box_rect.width));
    float closest_y = std::max(box_rect.top, std::min(circle_center.y, box_rect.top + box_rect.height));

    float distance_x = circle_center.x - closest_x;
    float distance_y = circle_center.y - closest_y;
    float distance_squared = (distance_x * distance_x) + (distance_y * distance_y);

    return distance_squared < (radius * radius);
}

void calculate_collision(Ball &ball, Object &object)
{
    sf::Vector2f ball_position(ball.m_x, ball.m_y);
    sf::Vector2f circle_center = ball_position + sf::Vector2f(ball.m_radius, ball.m_radius);
    sf::Vector2f object_position = object.get_position();
    sf::Vector2f object_size = object.get_size();
    sf::Vector2f object_center(
        (object_position.x + object_size.x / 2),
        (object_position.y + object_size.y / 2));

    // Calculate the distance between the ball and the object
    float x_dis = std::abs(circle_center.x - object_center.x);
    float y_dis = std::abs(circle_center.y - object_center.y);

    bool is_horizontal_collision = x_dis < circle_center.x + object_center.x;
    bool is_vertical_collision = y_dis < circle_center.y + object_center.y;

    if (is_vertical_collision)
    {
        if (circle_center.x + 2 * ball.m_radius > object_position.x &&
            circle_center.x < object_center.x)
        {
            ball.m_vx *= -1;
        }
        else if (circle_center.x > object_center.x &&
                 circle_center.x < object_center.x + object_size.x)
        {
            ball.m_vy *= -1;
        }
    }

    if (is_horizontal_collision)
    {
        if (circle_center.y + 2 * ball.m_radius > object_position.y &&
            circle_center.y < object_center.y)
        {
            ball.m_vx *= -1;
        }
        else if (circle_center.x > object_center.x &&
                 circle_center.x < object_center.x + object_size.x)
        {
            ball.m_vy *= -1;
        }
    }
}