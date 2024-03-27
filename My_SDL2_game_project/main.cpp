#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "CommonFunc.h"
#include "BaseObject.h"
#include "map.h"


#undef main

int main() {
    // Khoi tao SDL
    if (!InitSDL()) {
        return 1;
    }

    // Tao cua so
    SDL_Window* window = CreateWindow("Maze escape", SCREEN_HEIGHT, SCREEN_HEIGHT);
    if (!window)
    {
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

    //vong lap game
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

            /*       // Define the map file path
                   const char* mapFilePath = "map1.txt";


                   // Load the map
                   int mapSuccess = loadMap(mapFilePath);

                   if (mapSuccess != 0) {
                       std::cout << "Error loading map!" << std::endl;
                       return 1;
                   }

                   //draw my first maze
                   DrawMaze(renderer);
           */

            Map gameMap;
            gameMap.loadMap("map/map1.txt");

            gameMap.drawMap(renderer);

            //ve nhan vat   
            SDL_SetRenderDrawColor(renderer, 255, 165, 0, 255); //orange
            SDL_RenderFillRect(renderer, &character);


            // Cap nhat man hinh
            SDL_RenderPresent(renderer);

            //di chuyen nhan vat
            moveCharacter(character, event);
        }
    }

    // Destroy SDL
    QuitSDL();

    return 0;
}