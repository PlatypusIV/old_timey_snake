#include "../include/config.h"
#include "game/game.h"
#include "food/food.h"

// variables
Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

const unsigned int cellSize = 40;
const unsigned int screenWidth = 800;
const unsigned int screenHeight = 800;
const unsigned int border = 75;

Rectangle borderRectangle = Rectangle{
    (float)border - 5,
    (float)border - 5,
    (float)cellSize * 20 + 10,
    (float)cellSize * 20 + 10,
};
const unsigned int borderRectangleThickness = 5;
const Color borderRectangleColor = BLACK;

// functions
int main()
{
    InitWindow(screenWidth + border * 2, screenHeight + border * 2, "Retro Sneg");

    SetTargetFPS(60);
    Game game = Game(cellSize);

    // foodCounter++;
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

        // event handling
        game.handleInput();
        // updating positions
        game.updateSnakePositionAndSize();

        // drawing objects
        BeginDrawing();

        // ClearBackground(RAYWHITE);
        ClearBackground(green);

        // draw objects AFTER clear
        DrawText("Old timey sneg", border - 5, 20, 40, BLACK);
        DrawText(TextFormat("Score: %i", game.getScore()), 600, 20, 40, BLACK);
        DrawRectangleLinesEx(borderRectangle, borderRectangleThickness, borderRectangleColor);
        game.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}