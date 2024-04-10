#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "CommonFunc.h"
#include "player.h"
#include "map.h"


#undef main

int main() {

    Game trochoi;

    // Khoi tao SDL
    if (!trochoi.InitSDL()) {
        return 1;
    }

    // Tao cua so
    SDL_Window* window = trochoi.CreateWindow("Maze escape", SCREEN_HEIGHT, SCREEN_HEIGHT);
    if (!window)
    {
        return 1;
    }

    // Tao trinh ket xuat (renderer)
    SDL_Renderer* renderer = trochoi.CreateRenderer(window);
    if (!renderer) {
        return 1;
    }

    //tao nhan vat
    player nhanvat;
    nhanvat.createCharacter(renderer, "img/player_right.PNG");

    SDL_Event event;
    bool quit = false;


    Map gameMap;
    gameMap.loadMap("map/map4.txt");

    //vong lap game
    while (!quit)
    {

        while (SDL_PollEvent(&event)) {
            if (trochoi.outGame(event)) {
                quit = true; // Get out of loop when Esc press
            }
            // Thiet lap mau nen
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

            // Xoa man hinh
            SDL_RenderClear(renderer);



            gameMap.drawMap(renderer);

            //di chuyen nhan vat
            nhanvat.render(renderer);
            nhanvat.moveCharacter(event);
            nhanvat.updateAnimation();


            // Cap nhat man hinh
            SDL_RenderPresent(renderer);
        }
    }

    // Destroy SDL
    trochoi.QuitGame();

    return 0;
}