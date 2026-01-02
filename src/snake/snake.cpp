#include "snake.h"

Snake::Snake()
{
    body = std::deque{Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
}

void Snake::draw()
{
    for (int i = 0; i < body.size() - 1; i++)
    {
        DrawRectangle(body[i].x * 40, body[i].y * 40, 40, 40, DARKGREEN);
    }
}