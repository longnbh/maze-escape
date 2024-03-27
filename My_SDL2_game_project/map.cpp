#include "map.h"
#include <SDL_image.h>
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
    SDL_Texture* wallTexture = IMG_LoadTexture(renderer, "img/wall1.png");
    if (!wallTexture) {
        std::cout << "Couldnt load image : " << SDL_GetError() << std::endl;
    }

    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            if (mazeMap[i][j] == 1) {
                SDL_Rect wallRect = { j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE };
                SDL_RenderCopy(renderer, wallTexture, NULL, &wallRect);
            }
            else {
                // Draw path (same as before)
            }
        }
    }
}

const int(*Map::getMazeMap()) [MAP_WIDTH] {
    return mazeMap;
    }