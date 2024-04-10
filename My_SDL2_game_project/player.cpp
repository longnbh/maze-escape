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
        std::cout << "Could not load surface: " << SDL_GetError() << std::endl;
        return;
    }

    spritesheet = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);

    if (spritesheet == nullptr) {
        std::cout << "Could not load texture from surface: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_QueryTexture(spritesheet, NULL, NULL, &fWidth, &fHeight);

    // tinh toan cac frame clips
    for (int i = 0; i < numFrame; ++i) {
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
    case SDLK_DOWN: {
        dirY = (event.key.keysym.sym == SDLK_DOWN) ? 1 : -1;
        int checkY = pos.y + dirY * PLAYER_HEIGHT / 6;
        if (checkY < 0 || checkY >= SCREEN_HEIGHT || mazeMap[checkY / CELL_SIZE][pos.x / CELL_SIZE] == 1
            || mazeMap[(checkY + PLAYER_HEIGHT) / CELL_SIZE][pos.x / CELL_SIZE] == 1) {
            pos.y -= dirY * PLAYER_HEIGHT / 6;
            return;
        }
        /*if (mazeMap[checkY / CELL_SIZE][pos.x / CELL_SIZE] == 4) {
            // Neu nguoi choi den vi tri ket thuc
            std::cout << "Game over!" << std::endl;
            exit(0); // Ket thuc chuong trinh
        }*/

        denCuoi(renderer, checkY, pos.x);
        pos.y += (event.key.keysym.sym == SDLK_DOWN) ? PLAYER_HEIGHT / 6 : -PLAYER_HEIGHT / 6;
        break;
    }
    case SDLK_LEFT:
    case SDLK_RIGHT: {
        dirX = (event.key.keysym.sym == SDLK_RIGHT) ? 1 : -1;
        int checkX = pos.x + dirX * PLAYER_WIDTH / 6;
        if (checkX < 0 || checkX >= SCREEN_WIDTH || mazeMap[pos.y / CELL_SIZE][checkX / CELL_SIZE] == 1
            || mazeMap[pos.y / CELL_SIZE][(checkX + PLAYER_WIDTH) / CELL_SIZE] == 1) {
            pos.x -= dirX * PLAYER_HEIGHT / 6;
            return;
        }

        /*if (mazeMap[pos.y / CELL_SIZE][checkX / CELL_SIZE] == 4) {
            // 4 la ket thuc
            std::cout << "Game over!" << std::endl;
            exit(0); // End program
        }*/

        denCuoi(renderer, checkX, pos.y);
        pos.x += dirX * PLAYER_HEIGHT / 6;
        break;
    }
    }

    // In vi tri nhan vat
    //std::cout << "y = " << character.y << ", x = " << character.x << std::endl;
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