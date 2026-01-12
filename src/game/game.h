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
    GameState currentGameState = GameState::PLAY;
    bool isGamePaused;

private:
    Snake snake;
    int fps;
    int movementLimiter;
    int movementLimitCounter;
    int score;
    int cellSize;
    double lastUpdateTime;
    double interval;
    int score;

public:
    Game(int size);
    void draw();
    void updateSnakePositionAndSize();
    void generateFood();
    void handleInput();
    void checkCollision();
    void gameOver();

    Food food{cellSize};

private:
};