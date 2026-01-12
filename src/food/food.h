#pragma once
#include "../../include/config.h"

class Food
{

private:
    Color color;
    int width;
    int height;
    int cellSize;
    int cellCount;

public:
    Vector2 position;
    // Image foodImage;
    // Texture2D texture;
    Food(unsigned int size);
    ~Food();
    void draw();
    void clear();
    Vector2 generateRandomPosition(std::deque<Vector2> snakeBody);
    bool elementExistsInCollection(std::deque<Vector2> collection, Vector2 element);
};