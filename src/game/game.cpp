#include "game.h"

Game::Game(int size)
{
    snake = Snake();
    movementLimiter = 10;
    movementLimitCounter = 0;
    cellSize = size;
    food = Food(cellSize);
    lastUpdateTime - 0;
    interval = 0.2;
}

void Game::updateSnakePositionAndSize()
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        snake.move();
        lastUpdateTime = currentTime;
        checkCollision();
    }
}

void Game::generateFood()
{
}

void Game::draw()
{
    food.draw();

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

void Game::checkCollision()
{
    if (Vector2Equals(snake.body[0], food.position))
    {
        food.position = food.generateRandomPosition(snake.body);

        printf("Food has been eaten!\n");
    }

    // implement collision checking for snake
}