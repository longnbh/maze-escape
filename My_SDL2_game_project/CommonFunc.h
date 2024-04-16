//Dinh nghia thong so & goi include
//o day
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include <SDL.h>
#include "player.h"
#include "map.h"
const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 700;

class Game
{
public:
	Game() { }
	~Game() { ; }

	bool InitSDL();
	SDL_Window* CreateWindow(const char* title, int width, int height);
	SDL_Renderer* CreateRenderer(SDL_Window* window);
	void HandleEvents();
	void DrawGraphics(SDL_Renderer* renderer);

	bool outGame(SDL_Event& event);
	void render();
	void QuitGame();

	static void handleEndMaze(SDL_Renderer* renderer, Map& gameMap, player& nhanvat, int& countdown_time, int& last_time, SDL_Texture*& wallTexture);

protected:
	SDL_Renderer* renderer;
	SDL_Window* window;
};

#endif