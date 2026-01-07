#include "game.h"

Game::Game(int size)
{
    snake = Snake();
    movementLimiter = 10;
    movementLimitCounter = 0;
    foodSpawnTimer = 0;
    foodLimiter = 10;
    foodSpawnLimiter = 90;
    foodCollection = {};
    cellSize = size;
    // foodCollection.push_back(Food(cellSize));
}

void Game::updateSnakePosition()
{
    if (movementLimitCounter >= movementLimiter)
    {
        snake.move();
        movementLimitCounter = 0;
    }
    else
    {
        movementLimitCounter++;
    }
}

void Game::generateFood()
{
    if (foodCollection.size() < foodLimiter && foodSpawnTimer >= foodSpawnLimiter)
    {
        // guarantee non clashing later
        foodCollection.push_back(Food(cellSize));
        foodSpawnTimer = 0;
        // printf("Food generated\n");
    }
    else
    {
        foodSpawnTimer++;
    }
}

void Game::draw()
{
    for (int i = 0; i < foodCollection.size(); i++)
    {
        foodCollection[i].draw();
    }
    snake.draw();
}

void Game::handleInput()
{
    if (IsKeyDown(KEY_RIGHT))
        snake.changeDirection(Snake::Direction::RIGHT);
    if (IsKeyDown(KEY_LEFT))
        snake.changeDirection(Snake::Direction::LEFT);
    if (IsKeyDown(KEY_UP))
        snake.changeDirection(Snake::Direction::UP);
    if (IsKeyDown(KEY_DOWN))
        snake.changeDirection(Snake::Direction::DOWN);
}