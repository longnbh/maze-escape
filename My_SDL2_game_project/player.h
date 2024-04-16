#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include <SDL.h>
//#include "CommonFunc.h"
#include "map.h"
using namespace std;
const int PLAYER_WIDTH = 30;
const int PLAYER_HEIGHT = 30;
const int PLAYER_START_X = 45;
const int PLAYER_START_Y = 45;
const int numFrame = 12;
const int disMove = PLAYER_WIDTH / 3;


class player
{
public:
	player()
	{
		spritesheet = nullptr;
		currentFrame = 0;
		pos.w = PLAYER_WIDTH;
		pos.h = PLAYER_HEIGHT;

		const int(*mazeMap)[MAP_WIDTH] = Map::getMazeMap();
		bool foundStartPos = false;

		// Lặp qua toàn bộ bản đồ để tìm vị trí xuất hiện của nhân vật (giá trị 3)
		for (int i = 0; i < MAP_HEIGHT; ++i) {
			for (int j = 0; j < MAP_WIDTH; ++j) {
				if (mazeMap[i][j] == 3) {
					pos.x = j * CELL_SIZE; // Tính toán vị trí x
					pos.y = i * CELL_SIZE; // Tính toán vị trí y
					foundStartPos = true;
					break;  // Kết thúc vòng lặp khi tìm thấy vị trí 3
				}
			}
			if (foundStartPos) // Nếu đã tìm thấy vị trí, thoát khỏi vòng lặp ngoài
				break;
		}

		// Nếu không tìm thấy vị trí 3 trên bản đồ, sử dụng vị trí mặc định
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

	bool denCuoi(SDL_Renderer* renderer);

	void resetPosition();

private:
	SDL_Texture* spritesheet;
	SDL_Rect frame_clip[numFrame];
	int currentFrame;
	int dirX; //luu tru huong di chuyen theo truc X
	int dirY;//luu tru huong di chuyen theo truc Y
	int fWidth = 384;
	int fHeight = 32;

	int checkX;
	int checkY;
	SDL_Rect pos;
};

#endif