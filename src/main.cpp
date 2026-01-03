#include "../include/config.h"
#include "game/game.h"
#include "food/food.h"

// variables
Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

const int cellSize = 40;
const int screenWidth = 800;
const int screenHeight = 800;

// functions
int main()
{
    InitWindow(screenWidth, screenHeight, "Retro Sneg");

    SetTargetFPS(60);
    Game game = Game(cellSize);

    // foodCounter++;
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

        // event handling
        game.handleInput();
        // updating positions
        game.generateFood();
        game.updateSnakePosition();

        // drawing objects
        BeginDrawing();

        // ClearBackground(RAYWHITE);
        ClearBackground(green);

        // draw objects AFTER clear
        game.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

// void generateFood(){

// }