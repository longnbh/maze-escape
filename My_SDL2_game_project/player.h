﻿#ifndef MAIN_OBJECT_H_
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
		pos.w = PLAYER_WIDTH;
		pos.h = PLAYER_HEIGHT;
		/*fWidth = 0;
		fHeight = 0;*/
		/*pos.x = PLAYER_START_X;
		pos.y = PLAYER_START_Y;*/

		const int(*mazeMap)[MAP_WIDTH] = Map::getMazeMap();
		bool foundStartPos = false;
		int i = 0;
		//for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			if (mazeMap[i][j] == 3) {
				pos.x = j * CELL_SIZE; // Tính toán vị trí x
				pos.y = i * CELL_SIZE; // Tính toán vị trí y
				foundStartPos = true;
				break;  //Kết thúc vòng lặp khi tìm thấy vị trí 3
				//break;
			}

		}
		//return; break;
	//}
	/*pos.x = PLAYER_START_X;
	pos.y = PLAYER_START_Y;*/
		if (!foundStartPos) {
			pos.x = PLAYER_START_X;
			pos.y = PLAYER_START_Y;
		}
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

	static void denCuoi(SDL_Renderer* renderer, const int checkY, const int checkX);


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