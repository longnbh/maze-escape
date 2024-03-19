#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include <SDL.h>

//declare function to create a character
SDL_Rect createCharacter();

void moveCharacter(SDL_Rect&, SDL_Event);

#endif