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
    unsigned int fps;
    unsigned int cellSize;
    double lastUpdateTime;
    double interval;
    unsigned int score;

public:
    Game(int size);
    ~Game();
    void draw();
    void updateSnakePositionAndSize();
    void generateFood();
    void handleInput();
    void checkCollision();
    void gameOver();
    unsigned int getScore();
    Sound eatSound;

    Food food{cellSize};
};