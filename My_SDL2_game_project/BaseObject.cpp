#include "BaseObject.h"
#include "CommonFunc.h"
#include <iostream>
#include <SDL.h>
const int PLAYER_WIDTH = 10;
const int PLAYER_HEIGHT = 10;
const int PLAYER_START_X = 23;
const int PLAYER_START_Y = 38;


SDL_Rect createCharacter()
{
    SDL_Rect character = { PLAYER_START_X, PLAYER_START_Y, PLAYER_HEIGHT, PLAYER_WIDTH };
    //character.x = 23; character.y = 38; character.h = 10; character.w = 10;
    return character;
}

void moveCharacter(SDL_Rect& character, SDL_Event& event, const int(&mazeMap)[MAP_WIDTH][MAP_HEIGHT]) {
    switch (event.type) {
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_UP:
            // Move character up
            character.y -= PLAYER_HEIGHT;
            std::cout << "y = " << character.y << ", x = " << character.x << std::endl;
            // Check collision with walls
            if (character.y < 0 || mazeMap[character.y / CELL_SIZE][character.x / CELL_SIZE] == 1
                || mazeMap[(character.y + PLAYER_HEIGHT) / CELL_SIZE][(character.x + PLAYER_HEIGHT) / CELL_SIZE] == 1) {
                character.y += PLAYER_HEIGHT; // Undo the movement
            }
            break;
        case SDLK_DOWN:
            // Move character down
            character.y += PLAYER_HEIGHT;
            std::cout << "y = " << character.y << ", x = " << character.x << std::endl;
            // Check collision with walls
            if (character.y + character.h > SCREEN_HEIGHT || mazeMap[(character.y + PLAYER_HEIGHT) / CELL_SIZE][character.x / CELL_SIZE] == 1
                || mazeMap[(character.y + PLAYER_HEIGHT) / CELL_SIZE][(character.x + PLAYER_WIDTH) / CELL_SIZE] == 1
                || mazeMap[character.y / CELL_SIZE][character.x / CELL_SIZE] == 1
                || mazeMap[character.y / CELL_SIZE][(character.x + PLAYER_WIDTH) / CELL_SIZE] == 1) {
                character.y -= PLAYER_HEIGHT; // Undo the movement
            }
            break;
        case SDLK_LEFT:
            // Move character left
            character.x -= PLAYER_HEIGHT;
            std::cout << "y = " << character.y << ", x = " << character.x << std::endl;
            // Check collision with walls
            if (character.x < 0 || mazeMap[(character.y + PLAYER_HEIGHT) / CELL_SIZE][character.x / CELL_SIZE] == 1
                || mazeMap[(character.y + PLAYER_HEIGHT) / CELL_SIZE][(character.x + PLAYER_WIDTH) / CELL_SIZE] == 1
                || mazeMap[character.y / CELL_SIZE][character.x / CELL_SIZE] == 1
                || mazeMap[character.y / CELL_SIZE][(character.x + PLAYER_WIDTH) / CELL_SIZE] == 1) {
                character.x += PLAYER_HEIGHT; // Undo the movement
            }
            break;
        case SDLK_RIGHT:
            // Move character right
            character.x += PLAYER_HEIGHT;
            std::cout << "y = " << character.y << ", x = " << character.x << std::endl;
            // Check collision with walls
            if (character.x + character.w > SCREEN_WIDTH || mazeMap[character.y / CELL_SIZE][(character.x + character.w) / CELL_SIZE] == 1
                || mazeMap[(character.y + PLAYER_HEIGHT) / CELL_SIZE][(character.x + PLAYER_HEIGHT) / CELL_SIZE] == 1) {
                character.x -= PLAYER_HEIGHT; // Undo the movement
            }
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}

