#include "../include/config.h"

// variables
Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

int cellSize = 30;

int cellCount = 25;

// functions
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 640;

    InitWindow(cellSize * cellCount, cellSize * cellCount, "Retro Sneg");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
                      //--------------------------------------------------------------------------------------

    // Color red = {255,0,0,255};
    Food food(5, 10, 20, darkGreen);

    // Main game loop
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

        // DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        // DrawCircle3D(Vector3())

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context

    return 0;
}