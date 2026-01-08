#include "../../include/config.h"
#include "food.h"

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

Food::Food(int size)
{
    cellSize = size;
    foodImage = LoadImage("../assets/blueberrySmall.png");
    texture = LoadTextureFromImage(foodImage);
    UnloadImage(foodImage);

    cellCount = 20;
    position = Food::generateRandomPosition({});
    std::cout << texture.width << " " << texture.height << std::endl;
};

Food::~Food()
{
    UnloadTexture(texture);
}

void Food::draw()
{
    // DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, color);
    DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
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
