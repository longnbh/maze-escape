#include "CommonFunc.h"
#include "BaseObject.h"

SDL_Renderer* renderer = nullptr;
SDL_Window* window = nullptr;

bool InitSDL() {
    // Khoi tao SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return false;
    }
    return true;
}

SDL_Window* CreateWindow(const char* title, int width, int height) {
    // Tao cua so
    SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        SDL_Log("Failed to create a window: %s", SDL_GetError());
        return nullptr;
    }
    return window;
}

SDL_Renderer* CreateRenderer(SDL_Window* window) {
    //Tao renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        SDL_Log("Failed to create a renderer: %s", SDL_GetError());
        return nullptr;
    }
    return renderer;
}

void HandleEvents()
{

}

void DrawGraphics(SDL_Renderer* renderer)
{

}

bool isEscTapped(SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
        return true;
    }
    return false;
}



void QuitSDL() {
    // Clean up SDL & exit program  
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
