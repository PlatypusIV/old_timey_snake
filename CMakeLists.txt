cmake_minimum_required(VERSION 3.10)

project(snake)

add_executable(
    snake
    src/main.cpp
    src/food/food.cpp
    src/snake/snake.cpp
    src/game/game.cpp
)

target_include_directories(
    snake 
    PRIVATE
    include
)

target_link_directories(
    snake 
    PRIVATE
    lib
)

target_link_libraries(snake
    raylib
    opengl32
    gdi32
    winmm
)
