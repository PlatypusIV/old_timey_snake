#pragma once
#include "../../include/config.h"
#include "../snake/snake.h"
#include "../food/food.h"

class Game
{
public:
    enum GameState
    {
        MENU,
        PLAY,
        SCORE,
    };
    int foodSpawnLimiter;

private:
    Snake snake;
    int fps;
    int movementLimiter;
    int movementLimitCounter;
    int score;
    int foodSpawnTimer;
    int foodLimiter;
    int cellSize;

public:
    Game(int size);
    void draw();
    void updateSnakePositionAndSize();
    void generateFood();
    void handleInput();
    void checkCollision();

    Food food{cellSize};

private:
};