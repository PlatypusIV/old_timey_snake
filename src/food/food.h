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
    float scale;

public:
    Food(int size);
    ~Food();
    void draw();
    void clear();
    Vector2 generateRandomPosition();
    Texture2D texture;
};