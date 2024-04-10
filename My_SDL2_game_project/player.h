#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include <SDL.h>
#include "CommonFunc.h"
#include "map.h"

const int PLAYER_WIDTH = 30;
const int PLAYER_HEIGHT = 30;
const int PLAYER_START_X = 45;
const int PLAYER_START_Y = 45;
const int numFrame = 12;


class player
{
public:
	player() {
		spritesheet = nullptr;
		currentFrame = 0;
		/*fWidth = 0;
		fHeight = 0;*/
		pos.x = PLAYER_START_X;
		pos.y = PLAYER_START_Y;
		pos.w = PLAYER_WIDTH;
		pos.h = PLAYER_HEIGHT;
	}
	~player()
	{
		if (spritesheet != nullptr) {
			SDL_DestroyTexture(spritesheet);
		}
	}

	//declare function to create a character
	void createCharacter(SDL_Renderer* renderer, const char* spritePath);

	void moveCharacter(SDL_Renderer* renderer, SDL_Event& event);
	void updateAnimation();


	//render graphics
	void render(SDL_Renderer* renderer);

	static void denCuoi(SDL_Renderer* renderer, const int checkY, const int checkX) {
		const int(*mazeMap)[MAP_WIDTH] = Map::getMazeMap();

		if (mazeMap[checkY / CELL_SIZE][checkX / CELL_SIZE] == 4) {
			// so 4 la ket thuc, trong mang 2 chieu
			std::cout << "Ket thuc man choi!" << std::endl;
			Game::handleEndMaze(renderer); // ket thuc chuong trinh
		}
	}


private:
	SDL_Texture* spritesheet;
	SDL_Rect frame_clip[numFrame];
	int currentFrame;
	int dirX; //luu tru huong di chuyen theo truc X
	int dirY;//luu tru huong di chuyen theo truc Y
	int fWidth = 384;
	int fHeight = 32;

	SDL_Rect pos;
};

#endif