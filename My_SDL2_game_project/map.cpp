#include "map.h"
#include "player.h"
#include <SDL_image.h>
#include<string>
#include "CommonFunc.h"

int Map::mazeMap[MAP_WIDTH][MAP_HEIGHT];

void Map::loadMap(const char* name) {
    std::ifstream input(name);
    if (!input) return;

    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            int value;
            input >> value;
            mazeMap[i][j] = value;
        }
    }
    input.close();
}

void Map::drawMap(SDL_Renderer* renderer) {

    SDL_Texture* wallTexture = IMG_LoadTexture(renderer, "img/wall4.png");
    SDL_Texture* startTexture = IMG_LoadTexture(renderer, "img/batdau.png");
    SDL_Texture* endTexture = IMG_LoadTexture(renderer, "img/ketthuc.png");
    if (!wallTexture) {
        std::cout << "Couldnt load image : " << SDL_GetError() << std::endl;
    }

    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            if (mazeMap[i][j] == 1) {
                SDL_Rect wallRect = { j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE };
                SDL_RenderCopy(renderer, wallTexture, NULL, &wallRect);
            }
            if (mazeMap[i][j] == 3)
            {
                SDL_Rect wallRect = { j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE };
                SDL_RenderCopy(renderer, startTexture, NULL, &wallRect);
            }
            if (mazeMap[i][j] == 4)
            {
                SDL_Rect wallRect = { j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE }; //vi tri & kich thuoc cua anh
                SDL_RenderCopy(renderer, endTexture, NULL, &wallRect);
            }

        }
    }
}

const int(*Map::getMazeMap()) [MAP_WIDTH] {
    return mazeMap;
    }

    void Map::loadRandomMap()
    {
        //thiet lap seed cho rand
        std::srand(std::time(0));
        int randomMapIdx = std::rand() % numMap + 1;

        std::string mapName = "map/map" + std::to_string(randomMapIdx) + ".txt";

        loadMap(mapName.c_str());


    }