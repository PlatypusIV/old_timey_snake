#include "../../include/config.h"

Food::Food(int x, int y, int size, Color foodColor)
{
    cellSize = size;
    color = foodColor;
    Image image = LoadImage("../assets/blueberry.png");
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    scale = 0.01f;
    cellCount = 20;
    position = Food::generateRandomPosition();
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

Vector2 Food::generateRandomPosition()
{
    // remove magic numbers and make cellsize and cellcount changeable
    float x = GetRandomValue(0, cellCount * 40 - 1);
    float y = GetRandomValue(0, cellCount * 40 - 1);

    Vector2 position = Vector2{x, y};
    return position;
}
