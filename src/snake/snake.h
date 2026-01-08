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
    enum Direction currentDirection;

public:
    std::deque<Vector2> body;
    Snake();
    void draw();
    void move();
    void changeDirection(Direction newDirection);
    void eatFood();
    bool checkForCollision();
};