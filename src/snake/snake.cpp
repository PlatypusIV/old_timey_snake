#include "snake.h"

Snake::Snake()
{
    body = std::deque{Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    currentDirection = RIGHT;
}

void Snake::draw()
{
    for (int i = 0; i < body.size(); i++)
    {
        float x = body[i].x * 40;
        float y = body[i].y * 40;

        Rectangle segment = Rectangle{x, y, 40.0f, 40.0f};
        DrawRectangleRounded(segment, 0.5, 6, DARKGREEN);
    }
}

void Snake::move()
{
    Vector2 headPosition = body.front();
    Vector2 newHeadPosition;

    switch (currentDirection)
    {
    case RIGHT:
        newHeadPosition = {headPosition.x + 1, headPosition.y};
        break;
    case LEFT:
        newHeadPosition = {headPosition.x - 1, headPosition.y};
        break;
    case UP:
        newHeadPosition = {headPosition.x, headPosition.y - 1};
        break;
    case DOWN:
        newHeadPosition = {headPosition.x, headPosition.y + 1};
        break;
    default:
        break;
    }

    if (newHeadPosition.x > 20)
    {
        newHeadPosition.x = 0;
    }
    if (newHeadPosition.x < 0)
    {
        newHeadPosition.x = 20;
    }
    if (newHeadPosition.y > 20)
    {
        newHeadPosition.y = 0;
    }
    if (newHeadPosition.y < 0)
    {
        newHeadPosition.y = 19;
    }

    body.pop_back();
    body.push_front(newHeadPosition);
}

void Snake::changeDirection(Direction newDirection)
{
    if (newDirection == Direction::LEFT && currentDirection == Direction::RIGHT)
        return;

    currentDirection = newDirection;
}