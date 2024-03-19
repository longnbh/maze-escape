#include "BaseObject.h"
#include <iostream>

SDL_Rect createCharacter()
{
    SDL_Rect character = { 23, 38, 10, 10 };
    character.x = 23; character.y = 38; character.h = 10; character.w = 10;
    return character;
}

void moveCharacter(SDL_Rect& character, SDL_Event event)
{
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
        case SDLK_UP:
            character.y -= 10; // Di chuyen len
            std::cout << "Moving up\n"; std::cout << "y = " << character.y << std::endl;
            break;
        case SDLK_DOWN:
            character.y += 10; // Di chuyen xuong
            break;
        case SDLK_LEFT:
            character.x -= 10; // Sang trai
            break;
        case SDLK_RIGHT:
            character.x += 10; // Sang phai
            break;
        }
    }
}