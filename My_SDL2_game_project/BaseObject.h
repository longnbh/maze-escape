#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include <SDL.h>
#include "CommonFunc.h"

//declare function to create a character
SDL_Rect createCharacter();

void moveCharacter(SDL_Rect& character, SDL_Event& event, const int(&mazeMap)[MAP_WIDTH][MAP_HEIGHT]);

//Handle input events
void handleInput();

//update game state
void updateGame();

//render graphics
void render();

void DrawMaze(SDL_Renderer* renderer);

#endif