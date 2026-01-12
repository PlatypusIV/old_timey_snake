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
    isGamePaused = false;
    score = 0;
}

void Game::updateSnakePositionAndSize()
{
    if (isGamePaused)
    {
        return;
    }
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        snake.move();
        lastUpdateTime = currentTime;
        checkCollision();
    }
}

void Game::draw()
{
    food.draw();

    snake.draw();
}

void Game::handleInput()
{
    if (IsKeyPressed(KEY_RIGHT))
    {
        snake.changeDirection(Snake::Direction::RIGHT);
        isGamePaused = false;
    }
    if (IsKeyPressed(KEY_LEFT))
    {
        snake.changeDirection(Snake::Direction::LEFT);
        isGamePaused = false;
    }
    if (IsKeyPressed(KEY_UP))
    {
        snake.changeDirection(Snake::Direction::UP);
        isGamePaused = false;
    }
    if (IsKeyPressed(KEY_DOWN))
    {
        snake.changeDirection(Snake::Direction::DOWN);
        isGamePaused = false;
    }
}

void Game::checkCollision()
{
    // use pointers or references here
    for (unsigned int i = 2; i < snake.body.size(); i++)
    {
        if (Vector2Equals(snake.body[0], snake.body[i]))
        {
            gameOver();
        }
    }
    if (Vector2Equals(snake.body[0], food.position))
    {
        food.position = food.generateRandomPosition(snake.body);
        snake.eatFood();
        printf("Food has been eaten!\n");
    }

    // implement collision checking for snake
}

void Game::gameOver()
{
    isGamePaused = true;
    printf("GAME OVER!\n");
    currentGameState = GameState::SCORE;
    snake.reset();
    food.generateRandomPosition(snake.body);
}