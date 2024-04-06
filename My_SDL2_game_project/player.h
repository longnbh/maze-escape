#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include <SDL.h>
#include "CommonFunc.h"
#include "map.h"

const int PLAYER_WIDTH = 10;
const int PLAYER_HEIGHT = 10;
const int PLAYER_START_X = 31;
const int PLAYER_START_Y = 31;


class player
{

public:
	player() { ; }
	~player() { ; }

	//declare function to create a character
	SDL_Rect createCharacter();

	void moveCharacter(SDL_Rect& character, SDL_Event& event);

	//Handle input events
	void handleInput();


	//update game state
	void updateGame();

	//render graphics
	void render();

	void DrawMaze(SDL_Renderer* renderer);

private:
};

#endif