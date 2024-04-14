#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "CommonFunc.h"
#include "player.h"
#include "map.h"
#include "sound.h"

#undef main

int main() {

    Game trochoi;
    Sound sound;

    // Khoi tao SDL
    if (!trochoi.InitSDL()) { return 1; }

    if (!sound.khoiTaoSound()) { return 1; }

    // Tao cua so
    SDL_Window* window = trochoi.CreateWindow("Maze escape", SCREEN_HEIGHT, SCREEN_HEIGHT);
    if (!window) { return 1; }

    // Tao trinh ket xuat (renderer)
    SDL_Renderer* renderer = trochoi.CreateRenderer(window);
    if (!renderer) { return 1; }


    Map gameMap;
    gameMap.loadMap("map/map2.txt");

    //tao nhan vat
    player nhanvat;
    nhanvat.createCharacter(renderer, "img/player_right.PNG");

    SDL_Event event;
    bool quit = false;

    //vong lap game
    while (!quit)
    {

        while (SDL_PollEvent(&event))
        {
            if (trochoi.outGame(event))
            {
                quit = true; // Get out of loop when Esc press
            }

            // Thiet lap mau nen
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

            // Xoa man hinh
            SDL_RenderClear(renderer);


            gameMap.drawMap(renderer);

            //di chuyen nhan vat
            nhanvat.moveCharacter(renderer, event);
            nhanvat.render(renderer);

            if (nhanvat.denCuoi(renderer))
            {
                if (!sound.loadSound("sound/congrats.wav")) {
                    return 1;
                }
                sound.playSound();
                Game::handleEndMaze(renderer);
            }
            nhanvat.updateAnimation();


            // Cap nhat man hinh
            SDL_RenderPresent(renderer);
        }

    }

    // Destroy SDL
    trochoi.QuitGame();

    return 0;
}