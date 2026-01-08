#include "../../include/config.h"
#include "food.h"

Food::Food(int size)
{
    cellSize = size;
    Image image = LoadImage("../assets/blueberrySmall.png");
    texture = LoadTextureFromImage(image);

    UnloadImage(image);
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
    DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
    // DrawTextureEx(texture, position, 0.0f, 1.0f, GREEN);

    // std::cout << texture.width << " " << texture.height << std::endl;
}

void Food::clear()
{
    printf("Clearing food!");
}

Vector2 Food::generateRandomPosition()
{
    // remove magic numbers and make cellsize and cellcount changeable
    float x = GetRandomValue(0, cellCount - 1);
    float y = GetRandomValue(0, cellCount - 1);

    Vector2 position = Vector2{x, y};

    return position;
}
