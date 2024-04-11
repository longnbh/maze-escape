#include "CommonFunc.h"
#include "player.h"
#include "map.h"

SDL_Renderer* renderer = nullptr;
SDL_Window* window = nullptr;

bool Game::InitSDL() {
    // Khoi tao SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return false;
    }
    if (TTF_Init() != 0) {
        SDL_Log("Failed to initialize SDL_TTF: %s", TTF_GetError());
        return false;
    }
    return true;
}

SDL_Window* Game::CreateWindow(const char* title, int width, int height) {
    // Tao cua so
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        SDL_Log("Failed to create a window: %s", SDL_GetError());
        return nullptr;
    }
    return window;
}

SDL_Renderer* Game::CreateRenderer(SDL_Window* window) {
    //Tao renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        SDL_Log("Failed to create a renderer: %s", SDL_GetError());
        return nullptr;
    }
    return renderer;
}

void Game::HandleEvents()
{

}

void Game::DrawGraphics(SDL_Renderer* renderer)
{

}

bool Game::outGame(SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
        return true;
    }
    return false;
}

void Game::handleEndMaze(SDL_Renderer* renderer)
{
    SDL_Event e;
    bool running = true;

    SDL_Rect continueButton = { 100, 100, 200, 50 };
    SDL_Rect exitButton = { 100, 200, 200, 50 };

    // Mo font ngoai vong lap
    TTF_Font* font = TTF_OpenFont("fonts/tahoma.ttf", 24);
    if (!font) {
        // Xu ly khi khong mo duoc font
        SDL_Log("Failed to load font: %s", TTF_GetError());
        return;
    }

    while (running)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                SDL_Quit();
                exit(0);
            }
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x >= continueButton.x && x <= continueButton.x + continueButton.w &&
                    y >= continueButton.y && y <= continueButton.y + continueButton.h) {
                    // Xử lý khi người chơi chọn "Continue"
                    running = false; // Thoát khỏi vòng lặp
                    break;
                }
                else if (x >= exitButton.x && x <= exitButton.x + exitButton.w &&
                    y >= exitButton.y && y <= exitButton.y + exitButton.h) {
                    // Xử lý khi người chơi chọn "Exit"
                    SDL_Quit();
                    exit(0);
                }
            }
        }

        // Draw box and button
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &continueButton);
        SDL_RenderFillRect(renderer, &exitButton);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &continueButton);
        SDL_RenderDrawRect(renderer, &exitButton);

        SDL_Color textColor = { 0, 0, 0 };
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, "Continue", textColor);
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_Rect textRect = { continueButton.x + 50, continueButton.y + 10, textSurface->w, textSurface->h };
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);

        textSurface = TTF_RenderText_Solid(font, "Exit", textColor);
        textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        textRect = { exitButton.x + 70, exitButton.y + 10, textSurface->w, textSurface->h };
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);

        SDL_RenderPresent(renderer);
    }

    // Dong font sau khi dung
    TTF_CloseFont(font);
}

void Game::QuitGame() {

    TTF_Quit(); Mix_CloseAudio();
    // Clean up SDL & exit program  
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
