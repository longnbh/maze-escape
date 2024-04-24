#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "CommonFunc.h"
#include "highScore.h"
#include "player.h"
#include "map.h"
#include "sound.h"
#include "textObject.h"
#undef main

int main() {

    Game trochoi;
    Sound sound;
    highScore hs("highScore/highscores.txt");
    // Khoi tao SDL
    if (!trochoi.InitSDL()) { return 1; }

    if (!sound.khoiTaoSound()) { return 1; }

    // Tao cua so
    SDL_Window* window = trochoi.CreateWindow("Maze escape", SCREEN_WIDTH, SCREEN_HEIGHT); if (!window) { return 1; }

    // Tao trinh ket xuat (renderer)
    SDL_Renderer* renderer = trochoi.CreateRenderer(window);if (!renderer) { return 1; }

    bool startGame = trochoi.ShowMenu(renderer);

    if (!startGame) { trochoi.QuitGame(); return 0; }


    Map gameMap;
    gameMap.loadMap("map/map2.txt");
    SDL_Texture* wallTexture = IMG_LoadTexture(renderer, "img/wall/wall2.png");
    SDL_Texture* roadTexture = IMG_LoadTexture(renderer, "img/road/road2.png");
    //tao nhan vat
    player nhanvat;
    nhanvat.createCharacter(renderer, "img/player/player3.PNG");

    SDL_Event event;
    bool quit = false;

    // Khởi tạo thời gian đếm ngược
    int countdown_time = TIME_LIMIT;
    int last_time = SDL_GetTicks(); //take current time
    int playerScore = 0; //take player's score
    TTF_Font* font = TTF_OpenFont("fonts/AGENCYR.ttf", 20); // Thay đổi đường dẫn và kích thước phù hợp

    if (font == nullptr)
    {
        std::cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
        return 1;
    }

    Text countdown_text("Time left: ");
    countdown_text.SetText(""); // Khởi tạo văn bản với thời gian ban đầu
    countdown_text.SetColor(Text::GREEN_TEXT); // Thiết lập màu văn bản
    int text_x = 10; // Thay đổi vị trí hiển thị văn bản
    int text_y = 610;

    Text scoreText("Score: ");
    scoreText.SetText("Score: 0"); scoreText.SetColor(Text::PURPLE_TEXT);
    int score_x = 400; int score_y = 610;

    //vong lap game
    while (!quit)
    {
        int current_time = SDL_GetTicks(); // Lấy thời gian hiện tại
        int delta_time = current_time - last_time; // Tính thời gian trôi qua kể từ lần cuối cùng
        if (delta_time >= 1000) // Nếu đã qua 1 giây
        {
            countdown_time--; // Giảm thời gian đếm ngược đi 1
            last_time = current_time; // Cập nhật thời gian lần cuối
            std::cout << "Thoi gian: " << countdown_time << std::endl;
        }

        if (countdown_time <= 0)
        {
            //Game::handleEndMaze(renderer,gameMap,nhanvat, countdown_time, last_time, wallTexture);
            trochoi.handleEndTime(renderer);
            quit = true; // Thoát khỏi vòng lặp sự kiện
            break; // Thoát khỏi vòng lặp game
        }

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
            countdown_text.UpdateText(font, renderer, text_x, text_y, countdown_time);
            scoreText.UpdateText(font, renderer, score_x, score_y, playerScore);

            //SDL_Texture* wallTexture = IMG_LoadTexture(renderer, "img/wall2.png");
            gameMap.drawMap(renderer, wallTexture, roadTexture);

            //di chuyen nhan vat
            nhanvat.moveCharacter(renderer, event);
            nhanvat.render(renderer);


            if (nhanvat.denCuoi(renderer))
            {
                if (!sound.loadSound("sound/congrats.wav")) { return 1; }
                sound.playSound();

                Game::handleEndMaze(event,renderer, gameMap, nhanvat, countdown_time, last_time, wallTexture, roadTexture);
                playerScore++;
                
                scoreText.UpdateText(font, renderer, score_x, score_y, playerScore);
            }
            nhanvat.updateAnimation();

            // Cap nhat man hinh
            SDL_RenderPresent(renderer);
        }
        hs.update(playerScore);
    }

    // Destroy SDL
    trochoi.QuitGame();

    return 0;
}