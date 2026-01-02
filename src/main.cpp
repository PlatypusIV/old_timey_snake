#include "../include/config.h"

// variables
Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

const int cellSize = 40;
const int screenWidth = 800;
const int screenHeight = 800;

// functions
int main()
{
    int foodCounter = 0;
    InitWindow(screenWidth, screenHeight, "Retro Sneg");

    SetTargetFPS(60);
    Food food(5, 10, 20, darkGreen);
    Snake snake = Snake();

    // foodCounter++;
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

        // event handling

        // updating positions
        // drawing objects
        BeginDrawing();

        // ClearBackground(RAYWHITE);
        ClearBackground(green);

        // draw objects AFTER clear
        food.draw();
        snake.draw();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

// void generateFood(){

// }