#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "CommonFunc.h"
#include "BaseObject.h"

#undef main


int mazeMap[MAP_WIDTH][MAP_HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 1, 1, 0, 1, 0, 1, 1, 0},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 0},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void DrawMaze(SDL_Renderer* renderer) {

    SDL_Texture* wallTexture;
    wallTexture = IMG_LoadTexture(renderer, "img/wall1.png");
    if (!wallTexture)
    {
        std::cout << "Couldnt load image : " << SDL_GetError() << std::endl;
    }
    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            if (mazeMap[i][j] == 1) {
                // Draw wall
                //SDL_Rect wallRect = { j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE };
                //SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
                //SDL_RenderFillRect(renderer, &wallRect);

                SDL_Rect wallRect = { j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE };
                SDL_RenderCopy(renderer, wallTexture, NULL, &wallRect);
            }
            else {
                // Draw road
                SDL_Rect pathRect = { j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE };
                SDL_SetRenderDrawColor(renderer, 255, 223, 142, 255); // white
                SDL_RenderFillRect(renderer, &pathRect);
            }
        }
    }
}

int main() {
    // Khoi tao SDL
    if (!InitSDL()) {
        return 1;
    }

    // Tao cua so
    SDL_Window* window = CreateWindow("Maze escape", SCREEN_HEIGHT, SCREEN_HEIGHT);
    if (!window) {
        return 1;
    }

    // Tao trinh ket xuat (renderer)
    SDL_Renderer* renderer = CreateRenderer(window);
    if (!renderer) {
        return 1;
    }

    SDL_Event event;
    bool quit = false;

    //tao nhan vat
    SDL_Rect character = createCharacter();


    while (!quit)
    {

        while (SDL_PollEvent(&event)) {
            if (isEscTapped(event)) {
                quit = true; // Get out of loop when Esc press
            }
            // Thiet lap mau nen
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

            // Xoa man hinh
            SDL_RenderClear(renderer);

            //draw my first maze
            DrawMaze(renderer);

            SDL_Texture* wallTexture;
            wallTexture = IMG_LoadTexture(renderer, "image/wall1.png");

            //ve nhan vat   
            SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255); //orange
            SDL_RenderFillRect(renderer, &character);




            // Cap nhat man hinh
            SDL_RenderPresent(renderer);

            //di chuyen nhan vat
            moveCharacter(character, event, mazeMap);
        }
    }

    // Destroy SDL
    QuitSDL();

    return 0;
}