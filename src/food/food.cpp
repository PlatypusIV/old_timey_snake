#include "../../include/config.h"
#include "food.h"

Food::Food(unsigned int size)
{
    cellSize = size;
    // foodImage = LoadImage("../assets/blueberrySmall.png");
    // texture = LoadTextureFromImage(foodImage);
    // UnloadImage(foodImage);

    cellCount = 20;
    position = Food::generateRandomPosition({});
};

Food::~Food()
{
    // UnloadTexture(texture);
}

void Food::draw()
{
    DrawRectangle(position.x * cellSize + 75, position.y * cellSize + 75, cellSize, cellSize, BLACK);
    // DrawTexture(texture, position.x * cellSize + 75, position.y * cellSize + 75, WHITE);
    // DrawTextureEx(texture, position, 0.0f, 0.01f, WHITE);
}

void Food::clear()
{
    printf("Clearing food!");
}

Vector2 Food::generateRandomPosition(std::deque<Vector2> snakeBody)
{
    float x = GetRandomValue(0, cellCount - 1);
    float y = GetRandomValue(0, cellCount - 1);

    Vector2 position = Vector2{x, y};
    if (Food::elementExistsInCollection(snakeBody, position))
    {
        return Food::generateRandomPosition(snakeBody);
    }
    return position;
}

bool Food::elementExistsInCollection(std::deque<Vector2> collection, Vector2 element)
{
    for (unsigned int i = 0; i < collection.size(); i++)
    {
        if (Vector2Equals(collection[i], element))
        {
            return true;
        }
    }
    return false;
}