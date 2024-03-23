//Dinh nghia thong so & goi include
//o day
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <SDL.h>
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int CELL_SIZE = 20; //size of each cell in the maze
const int MAP_WIDTH = 10;
const int MAP_HEIGHT = 10;


bool InitSDL();
SDL_Window* CreateWindow(const char* title, int width, int height);
SDL_Renderer* CreateRenderer(SDL_Window* window);
void HandleEvents();
void DrawGraphics();
void QuitSDL();
bool isEscTapped(SDL_Event& event);

#endif