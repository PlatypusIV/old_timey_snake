#include "snake.h"

Snake::Snake()
{
    body = std::deque{Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    currentDirection = RIGHT;
    addSegment = false;
}

void Snake::draw()
{
    for (unsigned int i = 0; i < body.size(); i++)
    {
        float x = body[i].x * 40;
        float y = body[i].y * 40;

        Rectangle segment = Rectangle{x, y, 40.0f, 40.0f};
        DrawRectangleRounded(segment, 0.5, 6, BLACK);
    }
}

void Snake::move()
{

    Vector2 headPosition = body.front();
    Vector2 newHeadPosition;
    Vector2 direction;

    switch (currentDirection)
    {
    case RIGHT:
        direction = {1, 0};
        newHeadPosition = {headPosition.x + 1, headPosition.y};
        break;
    case LEFT:
        direction = {-1, 0};
        newHeadPosition = {headPosition.x - 1, headPosition.y};
        break;
    case UP:
        direction = {0, -1};
        newHeadPosition = {headPosition.x, headPosition.y - 1};
        break;
    case DOWN:
        direction = {0, 1};
        newHeadPosition = {headPosition.x, headPosition.y + 1};
        break;
    default:
        break;
    }

    if (newHeadPosition.x > 19)
    {
        newHeadPosition.x = 0;
    }
    if (newHeadPosition.x < 0)
    {
        newHeadPosition.x = 19;
    }
    if (newHeadPosition.y > 19)
    {
        newHeadPosition.y = 0;
    }
    if (newHeadPosition.y < 0)
    {
        newHeadPosition.y = 19;
    }
    body.push_front(newHeadPosition);
    if (addSegment)
    {

        addSegment = false;
        return;
    }
    body.pop_back();
}

void Snake::changeDirection(Direction newDirection)
{
    if (newDirection == RIGHT && currentDirection == LEFT || newDirection == LEFT && currentDirection == RIGHT || newDirection == UP && currentDirection == DOWN || newDirection == DOWN && currentDirection == UP)
    {
        return;
    }
    currentDirection = newDirection;
}

void Snake::eatFood()
{
    addSegment = true;
}

void Snake::reset()
{
    body = std::deque{Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    currentDirection = RIGHT;
    addSegment = false;
}