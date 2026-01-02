#pragma once
#include "../../include/config.h"
#include <deque>

class Snake
{
private:
public:
    Snake();
    std::deque<Vector2> body;
    void draw();
};