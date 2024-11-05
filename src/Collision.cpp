#include "Collision.h"
#include <cmath>
#include <iostream>

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
