#include "../../include/config.h"

Food::Food(int x, int y, int size, Color foodColor)
{
    position.x = x;
    position.y = y;
    cellSize = size;
    color = foodColor;
    Image image = LoadImage("../assets/blueberry.png");
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    scale = 0.01f;
};

Food::~Food()
{
    UnloadTexture(texture);
}

void Food::draw()
{
    // DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, color);
    // DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
    DrawTextureEx(texture, position, 0.0f, scale, WHITE);

    // std::cout << texture.width << " " << texture.height << std::endl;
}

void Food::clear()
{
    printf("Clearing food!");
}
