//Dinh nghia thong so & goi include
//o day
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <SDL.h>

const int SCREEN_WIDTH = 900;
const int SCREEN_HEIGHT = 800;
const int CELL_SIZE = 40; //size of each cell in the maze

class Game
{
public:
	Game() { ; }
	~Game() { ; }

	bool InitSDL();
	SDL_Window* CreateWindow(const char* title, int width, int height);
	SDL_Renderer* CreateRenderer(SDL_Window* window);
	void HandleEvents();
	void DrawGraphics(SDL_Renderer* renderer);

	bool outGame(SDL_Event& event);
	void render();
	void QuitGame();

private:

};

#endif