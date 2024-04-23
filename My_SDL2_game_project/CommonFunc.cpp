#include "CommonFunc.h"
#include "textObject.h"

SDL_Renderer* renderer = nullptr;
SDL_Window* window = nullptr;

SDL_Texture* LoadImage(SDL_Renderer* renderer, const std::string& file_path)
{
    SDL_Surface* surface = IMG_Load(file_path.c_str());
    if (!surface)
    {
        std::cerr << "Failed to load image: " << file_path << ". Error: " << IMG_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture)
    {
        std::cerr << "Failed to create texture from surface! Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }
    return texture;
}

bool Game::InitSDL() {
    // Khoi tao SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return false;
    }
    if (TTF_Init() != 0) {
        SDL_Log("Failed to initialize SDL_TTF: %s", TTF_GetError());
        return false;
    }
    return true;
}

SDL_Window* Game::CreateWindow(const char* title, int width, int height) {
    // Tao cua so
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        SDL_Log("Failed to create a window: %s", SDL_GetError());
        return nullptr;
    }
    return window;
}

SDL_Renderer* Game::CreateRenderer(SDL_Window* window) {
    //Tao renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        SDL_Log("Failed to create a renderer: %s", SDL_GetError());
        return nullptr;
    }
    return renderer;
}

bool Game::ShowMenu(SDL_Renderer* renderer)
{
    // Load ảnh làm nền cho menu
    SDL_Texture* menuBackground = LoadImage(renderer, "img/menu.jpg");
    if (!menuBackground) { std::cerr << "Failed to load menu background image!" << std::endl;return -1; }

    // Load ảnh cho nút "Play game" và "Exit"
    SDL_Texture* playButtonTexture = LoadImage(renderer, "img/play_button.png");
    SDL_Texture* exitButtonTexture = LoadImage(renderer, "img/exit_button.png");

    if (!playButtonTexture || !exitButtonTexture) { std::cerr << "Failed to load button images!" << std::endl;return -1; }

    //load font for Game name & My name
    TTF_Font* font = TTF_OpenFont("fonts/SNAP.ttf", 36); // choose size
    if (!font) { std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;return -1; }

    //create surface contains Game name
    SDL_Color textColor = { 255, 255, 255 };
    SDL_Surface* gameNameSurface = TTF_RenderText_Solid(font, "MAZE ESCAPE GAME!", textColor);
    if (!gameNameSurface) { std::cerr << "Failed to render game name text: " << TTF_GetError() << std::endl;return -1; }
    SDL_Texture* gameNameTexture = SDL_CreateTextureFromSurface(renderer, gameNameSurface);
    if (!gameNameTexture) { std::cerr << "Failed to create texture from game name surface: " << SDL_GetError() << std::endl;return -1; }

    // create surface contains My name
    SDL_Surface* myNameSurface = TTF_RenderText_Solid(font, "By NBHL", textColor);
    if (!myNameSurface) { std::cerr << "Failed to render your name text: " << TTF_GetError() << std::endl;return -1; }
    SDL_Texture* myNameTexture = SDL_CreateTextureFromSurface(renderer, myNameSurface);
    if (!myNameTexture) { std::cerr << "Failed to create texture from your name surface: " << SDL_GetError() << std::endl;return -1; }


    bool startGame = false; //check if player want to start the game

    bool inMenu = true;
    while (inMenu) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) { inMenu = false;break; }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                if (mouseX >= PLAY_BUTTON_X && mouseX <= PLAY_BUTTON_X + BUTTON_WIDTH &&
                    mouseY >= PLAY_BUTTON_Y && mouseY <= PLAY_BUTTON_Y + BUTTON_HEIGHT) {
                    // player chose "Play game"
                    startGame = true;
                    inMenu = false;
                    break;
                }
                else if (mouseX >= EXIT_BUTTON_X && mouseX <= EXIT_BUTTON_X + BUTTON_WIDTH &&
                    mouseY >= EXIT_BUTTON_Y && mouseY <= EXIT_BUTTON_Y + BUTTON_HEIGHT) {
                    // player chose "Exit"
                    return false; // Thoát khỏi hàm và kết thúc chương trình
                }
            }
        }

        // Draw menu on screen
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, menuBackground, NULL, NULL);
        SDL_Rect playButtonRect = { PLAY_BUTTON_X, PLAY_BUTTON_Y, BUTTON_WIDTH, BUTTON_HEIGHT };
        SDL_RenderCopy(renderer, playButtonTexture, NULL, &playButtonRect);
        SDL_Rect exitButtonRect = { EXIT_BUTTON_X, EXIT_BUTTON_Y, BUTTON_WIDTH, BUTTON_HEIGHT };
        SDL_RenderCopy(renderer, exitButtonTexture, NULL, &exitButtonRect);
        //Draw credits on screen
        SDL_Rect gameNameRect = { 100, 50, gameNameSurface->w, gameNameSurface->h };
        SDL_RenderCopy(renderer, gameNameTexture, NULL, &gameNameRect);
        int nameX = (EXIT_BUTTON_X + BUTTON_WIDTH / 2) - (myNameSurface->w / 2);
        SDL_Rect NameRect = { nameX, 100, myNameSurface->w, myNameSurface->h };
        SDL_RenderCopy(renderer, myNameTexture, NULL, &NameRect);
        //cap nhat man hinh
        SDL_RenderPresent(renderer);
    }

    // Giải phóng bộ nhớ khi đã sử dụng xong
    SDL_DestroyTexture(menuBackground);
    SDL_DestroyTexture(playButtonTexture);
    SDL_DestroyTexture(exitButtonTexture);
    SDL_DestroyTexture(gameNameTexture);
    SDL_DestroyTexture(myNameTexture);
    SDL_FreeSurface(gameNameSurface);
    SDL_FreeSurface(myNameSurface);
    TTF_CloseFont(font);


    return startGame;
}


bool Game::outGame(SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) { return true; }
    return false;
}

void Game::handleEndMaze(SDL_Renderer* renderer, Map& gameMap, player& nhanvat, int& countdown_time, int& last_time, SDL_Texture*& wallTexture, SDL_Texture*& roadTexture)
{
    SDL_Event e;
    bool running = true;

    SDL_Rect continueButton = { 300, 250, 200, 50 };
    SDL_Rect exitButton = { 300, 350, 200, 50 };

    // Mo font ngoai vong lap
    TTF_Font* font = TTF_OpenFont("fonts/tahoma.ttf", 24);
    if (!font)
    {
        // Xu ly khi khong mo duoc font
        SDL_Log("Failed to load font: %s", TTF_GetError());
        return;
    }

    while (running)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                SDL_Quit();
                exit(0);
            }
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x >= continueButton.x && x <= continueButton.x + continueButton.w &&
                    y >= continueButton.y && y <= continueButton.y + continueButton.h)
                {
                    // Xu ly khi nguoi chon "Continue"
                    running = false; // Thoát khỏi vòng lặp
                    countdown_time = TIME_LIMIT;
                    last_time = SDL_GetTicks();
                    wallTexture = gameMap.loadRandomMapAndWall(renderer);
                    nhanvat.resetPosition();
                    roadTexture = gameMap.loadRandomRoad(renderer);
                    gameMap.drawMap(renderer, wallTexture, roadTexture);

                    break;
                }
                else if (x >= exitButton.x && x <= exitButton.x + exitButton.w &&
                    y >= exitButton.y && y <= exitButton.y + exitButton.h) {
                    // Xu ly khi nguoi chon "Exit"
                    SDL_Quit();
                    exit(0);
                }
            }
        }

        // Draw box and button
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &continueButton);
        SDL_RenderFillRect(renderer, &exitButton);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &continueButton);
        SDL_RenderDrawRect(renderer, &exitButton);

        SDL_Color textColor = { 0, 0, 0 };
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, "Continue", textColor);
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_Rect textRect = { continueButton.x + 50, continueButton.y + 10, textSurface->w, textSurface->h };
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);

        textSurface = TTF_RenderText_Solid(font, "Exit", textColor);
        textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        textRect = { exitButton.x + 70, exitButton.y + 10, textSurface->w, textSurface->h };
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);

        SDL_RenderPresent(renderer);
    }

    // Dong font sau khi dung
    TTF_CloseFont(font);
}

//xu ly khi het thoi gian
void Game::handleEndTime(SDL_Renderer* renderer)
{
    SDL_Event e;
    bool running = true;

    SDL_Rect exitButton = { 225, 400, 200, 50 };

    // Load font
    TTF_Font* font = TTF_OpenFont("fonts/tahoma.ttf", 24);
    if (!font) {
        SDL_Log("Failed to load font: %s", TTF_GetError());
        return;
    }

    // Load game over image
    SDL_Texture* gameOverTexture = LoadImage(renderer, "img/game_over.png");
    if (!gameOverTexture) {
        std::cerr << "Failed to load game over image!" << std::endl; return;
    }
    Sound endSound; if (!endSound.khoiTaoSound()) { return; } if (!endSound.loadSound("sound/game_over.wav")) { return; }
    endSound.playSound();

    while (running)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT) { running = false;break; }
            if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x >= exitButton.x && x <= exitButton.x + exitButton.w &&
                    y >= exitButton.y && y <= exitButton.y + exitButton.h) {
                    // Handle Exit button
                    running = false;
                    break;
                }
            }
        }

        // Clear the renderer
        SDL_RenderClear(renderer);

        // Render game over image
        SDL_Rect gameOverRect = { GAME_OVER_X, GAME_OVER_Y, GAME_OVER_WIDTH, GAME_OVER_HEIGHT };
        SDL_RenderCopy(renderer, gameOverTexture, NULL, &gameOverRect);

        // Render exit button
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &exitButton);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderDrawRect(renderer, &exitButton);

        // Render exit button text
        SDL_Color color_exit = { 255, 255, 0 };
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, "Exit", color_exit);
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_Rect textRect = { exitButton.x + 70, exitButton.y + 10, textSurface->w, textSurface->h };
        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);

        // Present everything on the screen
        SDL_RenderPresent(renderer);
    }

    // Free resources
    SDL_DestroyTexture(gameOverTexture);
    TTF_CloseFont(font);
}

void Game::QuitGame()
{
    TTF_Quit(); Mix_CloseAudio();
    // Clean up SDL & exit program  
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
