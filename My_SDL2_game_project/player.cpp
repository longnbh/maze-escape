#include "map.h"
#include "player.h"
#include "CommonFunc.h"
#include <SDL_image.h>
#include <iostream>
#include <SDL.h>

void player::createCharacter(SDL_Renderer* renderer, const char* spritePath)
{
    SDL_Surface* loadedSurface = IMG_Load(spritePath);
    if (loadedSurface == nullptr) {
        cout << "Could not load surface: " << SDL_GetError() << endl;
        return;
    }

    spritesheet = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);

    if (spritesheet == nullptr) {
        cout << "Could not load texture from surface: " << SDL_GetError() << endl;
        return;
    }

    SDL_QueryTexture(spritesheet, NULL, NULL, &fWidth, &fHeight);

    // tinh toan cac frame clips
    for (int i = 0; i < numFrame; ++i)
    {
        frame_clip[i].x = i * (fWidth / numFrame);
        frame_clip[i].y = 0;
        frame_clip[i].w = fWidth / numFrame;
        frame_clip[i].h = fHeight;
    }
}

void player::render(SDL_Renderer* renderer)
{//render nhan vat dua tren frame hien tai
    //SDL_Rect* currentClip = &frame_clip[currentFrame / (fWidth / numFrame)];
    //srand(0);
    bool standing = false;
    SDL_RenderCopy(renderer, spritesheet, &frame_clip[rand() % 12], &pos);

}

void player::moveCharacter(SDL_Renderer* renderer, SDL_Event& event)
{
    if (event.type != SDL_KEYDOWN) return;

    const int(*mazeMap)[MAP_WIDTH] = Map::getMazeMap(); //gan bien mazeMap bang 1 con tro toi mang 2 chieu

    switch (event.key.keysym.sym)
    {
    case SDLK_UP:
    case SDLK_DOWN:
    {
        dirY = (event.key.keysym.sym == SDLK_DOWN) ? 1 : -1;
        checkY = pos.y + dirY * disMove;
        checkX = pos.x;
        if (checkY < 0 || checkY >= SCREEN_HEIGHT || mazeMap[checkY / CELL_SIZE][pos.x / CELL_SIZE] == 1
            || mazeMap[(checkY + safeDis) / CELL_SIZE][pos.x / CELL_SIZE] == 1
            || mazeMap[checkY / CELL_SIZE][(pos.x + safeDis) / CELL_SIZE] == 1
            || mazeMap[(checkY + PLAYER_HEIGHT) / CELL_SIZE][(pos.x + safeDis) / CELL_SIZE] == 1) { // xu ly 4 goc hinh
            //pos.y -= dirY * disMove;
            pos.y += 0;
            return;
        }

        denCuoi(renderer); //neu nguoi choi den vi tri ket thuc
        pos.y += (event.key.keysym.sym == SDLK_DOWN) ? disMove : -disMove;
        break;
    }
    case SDLK_LEFT:
    case SDLK_RIGHT:
    {
        dirX = (event.key.keysym.sym == SDLK_RIGHT) ? 1 : -1;
        checkX = pos.x + dirX * disMove;
        checkY = pos.y;
        if (checkX < 0 || checkX >= SCREEN_WIDTH || mazeMap[pos.y / CELL_SIZE][checkX / CELL_SIZE] == 1
            || mazeMap[(pos.y + safeDis) / CELL_SIZE][checkX / CELL_SIZE] == 1
            || mazeMap[pos.y / CELL_SIZE][(checkX + safeDis) / CELL_SIZE] == 1
            || mazeMap[(pos.y + safeDis) / CELL_SIZE][(checkX + safeDis) / CELL_SIZE] == 1) { // xu ly 4 goc hinh
            pos.x += 0;
            //pos.x -= dirX * disMove;
            return;
        }

        /*if (mazeMap[pos.y / CELL_SIZE][checkX / CELL_SIZE] == 4) {
            // 4 la ket thuc
            cout << "Game over!" << endl;
            exit(0); // End program
        }*/

        denCuoi(renderer);
        pos.x += dirX * disMove;
        break;
    }
    }

    // In vi tri nhan vat
    //cout << "y = " << character.y << ", x = " << character.x << endl;
}

bool player::denCuoi(SDL_Renderer* renderer)
{
    bool endReach = false;
    const int(*mazeMap)[MAP_WIDTH] = Map::getMazeMap();

    if (mazeMap[checkY / CELL_SIZE][checkX / CELL_SIZE] == 4) {
        // so 4 la ket thuc, trong mang 2 chieu
        endReach = true;
        cout << "Ket thuc man choi!" << endl;
        //Game::handleEndMaze(renderer); // ket thuc man choi
    }
    return endReach;
}

void player::updateAnimation() {
    // cap nhat frame dua tren huong di chuyen
    if (dirX == 0 && dirY == 0) {
        currentFrame = 0; // Nhan vat dung yen
    }
    else {
        // tinh toan frame dua tren huong di chuyen
        currentFrame++;
        if (currentFrame / (fWidth / numFrame) >= numFrame) {
            currentFrame = 0;
        }
    }
}

void player::resetPosition()
{
    const int(*mazeMap)[MAP_WIDTH] = Map::getMazeMap();
    for (int i = 0; i < MAP_HEIGHT; ++i) {
        for (int j = 0; j < MAP_WIDTH; ++j) {
            if (mazeMap[i][j] == 3) {
                pos.x = j * CELL_SIZE; // Tính toán vị trí x
                pos.y = i * CELL_SIZE; return;
            }
        }
    }
}