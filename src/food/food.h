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
    float scale;

public:
    Food(int x, int y, int size, Color color);
    ~Food();
    void draw();
    void clear();
    Texture2D texture;
};