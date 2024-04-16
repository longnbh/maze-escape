#include "map.h"
#include "player.h"
#include <SDL_image.h>
#include<string>
#include "CommonFunc.h"
using namespace std;

int Map::mazeMap[MAP_WIDTH][MAP_HEIGHT];

void Map::loadMap(const char* name) {
    ifstream input(name);
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

void Map::drawMap(SDL_Renderer* renderer, SDL_Texture* wallTexture) {

    //SDL_Texture* wallTexture = IMG_LoadTexture(renderer, "img/wall4.png");
    SDL_Texture* startTexture = IMG_LoadTexture(renderer, "img/batdau.png");
    SDL_Texture* endTexture = IMG_LoadTexture(renderer, "img/ketthuc.png");
    if (!wallTexture || !startTexture || !endTexture) {
        cout << "Couldnt load image : " << SDL_GetError() << endl;
    }

    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            if (mazeMap[i][j] == 1)
            {
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

    //SDL_DestroyTexture(startTexture);
    //SDL_DestroyTexture(endTexture);
}

const int(*Map::getMazeMap()) [MAP_WIDTH] {
    return mazeMap;
    }

    SDL_Texture* Map::loadRandomMap(SDL_Renderer* renderer)
    {
        //thiet lap seed cho rand
        srand(time(0));
        int randomMapIdx = rand() % numMap + 1;

        string mapName = "map/map" + to_string(randomMapIdx) + ".txt";
        loadMap(mapName.c_str());

        int randomWall = rand() % numWall + 1;
        string wallName = "img/wall" + to_string(randomWall) + ".png";
        SDL_Texture* newWallTexture = IMG_LoadTexture(renderer, wallName.c_str());
        //drawMap(renderer, newWallTexture);

        return newWallTexture;
        //SDL_DestroyTexture(newWallTexture);
    }