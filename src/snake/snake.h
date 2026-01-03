#pragma once
#include "../../include/config.h"

class Snake
{

public:
    enum Direction
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
    };

private:
    std::deque<Vector2> body;
    enum Direction currentDirection;

public:
    Snake();
    void draw();
    void move();
    void changeDirection(Direction newDirection);
    void eatFood();
    bool checkForCollision();
};