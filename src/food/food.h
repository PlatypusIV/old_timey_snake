#pragma once
#include "../../include/config.h"

class Food
{

private:
    Color color;
    int width;
    int height;
    int cellSize;
    Vector2 position;
    std::string foodImage;
    int cellCount;

public:
    Texture2D texture;
    Food(int size);
    ~Food();
    void draw();
    void clear();
    Vector2 generateRandomPosition();
};