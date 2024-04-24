//Dinh nghia thong so & goi include
//o day
#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include <SDL_image.h>
#include <SDL.h>
#include "sound.h"
#include "highScore.h"
#include "player.h"
#include "map.h"
const int SCREEN_WIDTH = 630;
const int SCREEN_HEIGHT = 700;
const int PLAY_BUTTON_X = 270; const int PLAY_BUTTON_Y = 250;const int EXIT_BUTTON_X = 270;const int EXIT_BUTTON_Y = 300;
const int HS_BUTTON_X = 270; const int HS_BUTTON_Y = 320;
const int GAME_OVER_X = 200, GAME_OVER_Y = 200, GAME_OVER_WIDTH = 250, GAME_OVER_HEIGHT = 197;
const int BUTTON_WIDTH = 100;
const int BUTTON_HEIGHT = 43;


class Game
{
public:
	Game() { }
	~Game() { ; }

	bool InitSDL();
	SDL_Window* CreateWindow(const char* title, int width, int height);
	SDL_Renderer* CreateRenderer(SDL_Window* window);
	void HandleEvents();
	bool ShowMenu(SDL_Renderer* renderer);

	bool outGame(SDL_Event& event);
	void render();
	void QuitGame();

	static void handleEndMaze(SDL_Event e, SDL_Renderer* renderer, Map& gameMap, player& nhanvat, int& countdown_time, int& last_time, SDL_Texture*& wallTexture,
		SDL_Texture*& roadTexture, highScore& hs, int score);
	void handleEndTime(SDL_Renderer* renderer, highScore& hs, int score);
	static void renderText(SDL_Renderer* renderer, TTF_Font* font, const char* text, SDL_Color textColor, SDL_Rect button);

protected:
	SDL_Renderer* renderer;
	SDL_Window* window;
};

SDL_Texture* LoadImage(SDL_Renderer* renderer, const std::string& file_path);

#endif