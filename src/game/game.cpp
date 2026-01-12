#include "game.h"

Game::Game(unsigned int size)
{
    InitAudioDevice();
    snake = Snake();
    cellSize = size;
    food = Food(cellSize);
    lastUpdateTime - 0;
    interval = 0.2;
    isGamePaused = false;
    score = 0;
    eatSound = LoadSound("../assets/yoshi.mp3");
    deathSound = LoadSound("../assets/bruh-meme-sound-effect.mp3");
}

Game::~Game()
{
    UnloadSound(eatSound);
    CloseAudioDevice();
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
    if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))
    {
        snake.changeDirection(Snake::Direction::RIGHT);
        isGamePaused = false;
    }
    if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A))
    {
        snake.changeDirection(Snake::Direction::LEFT);
        isGamePaused = false;
    }
    if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W))
    {
        snake.changeDirection(Snake::Direction::UP);
        isGamePaused = false;
    }
    if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S))
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
        PlaySound(eatSound);
        score++;
        printf("Food has been eaten!\n");
    }
}

void Game::gameOver()
{
    PlaySound(deathSound);
    isGamePaused = true;
    printf("GAME OVER!\n");
    currentGameState = GameState::SCORE;
    snake.reset();
    food.generateRandomPosition(snake.body);
    score = 0;
}

unsigned int Game::getScore()
{
    return score;
}