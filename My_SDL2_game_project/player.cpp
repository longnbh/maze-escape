#include "map.h"
#include "player.h"
#include "CommonFunc.h"

#include <iostream>
#include <SDL.h>



SDL_Rect player::createCharacter()
{
    SDL_Rect character = { PLAYER_START_X, PLAYER_START_Y, PLAYER_HEIGHT, PLAYER_WIDTH };
    //character.x = 23; character.y = 38; character.h = 10; character.w = 10;
    return character;
}

void player::moveCharacter(SDL_Rect& character, SDL_Event& event)
{
    if (event.type != SDL_KEYDOWN) return;

    const int(*mazeMap)[MAP_WIDTH] = Map::getMazeMap(); //gan bien mazeMap bang 1 con tro toi mang 2 chieu

    switch (event.key.keysym.sym) {
    case SDLK_UP:
    case SDLK_DOWN: {
        int dir = (event.key.keysym.sym == SDLK_DOWN) ? 1 : -1;
        int checkY = character.y + dir * PLAYER_HEIGHT;
        if (checkY < 0 || checkY >= SCREEN_HEIGHT || mazeMap[checkY / CELL_SIZE][character.x / CELL_SIZE] == 1) {
            character.y -= dir * PLAYER_HEIGHT;
            return;
        }
        character.y += (event.key.keysym.sym == SDLK_DOWN) ? PLAYER_HEIGHT : -PLAYER_HEIGHT;
        break;
    }
    case SDLK_LEFT:
    case SDLK_RIGHT: {
        int dir = (event.key.keysym.sym == SDLK_RIGHT) ? 1 : -1;
        int checkX = character.x + dir * PLAYER_WIDTH;
        if (checkX < 0 || checkX >= SCREEN_WIDTH || mazeMap[character.y / CELL_SIZE][checkX / CELL_SIZE] == 1) {
            character.x -= dir * PLAYER_HEIGHT;
            return;
        }
        character.x += dir * PLAYER_HEIGHT;
        break;
    }
    }

    // In vi tri nhan vat
    //std::cout << "y = " << character.y << ", x = " << character.x << std::endl;
}
