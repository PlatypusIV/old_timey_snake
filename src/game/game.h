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
    Game(int cellSize);
    // Food food;
    std::vector<Food> foodCollection;
    void draw();
    void updateSnakePosition();
    void generateFood();
    void handleInput();

private:
};