#include "CommonFunc.h"
#include "textObject.h"

SDL_Renderer* renderer = nullptr;
SDL_Window* window = nullptr;

SDL_Texture* LoadImage(SDL_Renderer* renderer, const std::string& file_path)
{
    SDL_Surface* surface = IMG_Load(file_path.c_str());
    if (!surface) {
        std::cerr << "Failed to load image: " << file_path << ". Error: " << IMG_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture) {
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
    if (!menuBackground) 
    {
        std::cerr << "Failed to load menu background image!" << std::endl;
        return -1;
    }

    // Load ảnh cho nút "Play game" và "Exit"
    SDL_Texture* playButtonTexture = LoadImage(renderer, "img/play_button.png");
    SDL_Texture* exitButtonTexture = LoadImage(renderer, "img/exit_button.png");

    if (!playButtonTexture || !exitButtonTexture) 
    {
        std::cerr << "Failed to load button images!" << std::endl;
        return -1;
    }

    bool startGame = false; //check if player want to start the game

    bool inMenu = true;
    while (inMenu) 
    {
        SDL_Event event;
        while (SDL_PollEvent(&event)) 
        {
            if (event.type == SDL_QUIT) { inMenu = false; break; }
            else if (event.type == SDL_MOUSEBUTTONDOWN) 
            {
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
                    // Người chơi nhấn vào nút "Exit"
                    return false; // Thoát khỏi hàm và kết thúc chương trình
                }
            }
        }

        // Vẽ menu lên màn hình
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, menuBackground, NULL, NULL);
        SDL_Rect playButtonRect = { PLAY_BUTTON_X, PLAY_BUTTON_Y, BUTTON_WIDTH, BUTTON_HEIGHT };
        SDL_RenderCopy(renderer, playButtonTexture, NULL, &playButtonRect);
        SDL_Rect exitButtonRect = { EXIT_BUTTON_X, EXIT_BUTTON_Y, BUTTON_WIDTH, BUTTON_HEIGHT };
        SDL_RenderCopy(renderer, exitButtonTexture, NULL, &exitButtonRect);
        SDL_RenderPresent(renderer);
    }

    // Giải phóng bộ nhớ khi đã sử dụng xong
    SDL_DestroyTexture(menuBackground);
    SDL_DestroyTexture(playButtonTexture);
    SDL_DestroyTexture(exitButtonTexture);

    return startGame;
}


bool Game::outGame(SDL_Event& event)
{
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
        return true;
    }
    return false;
}

void Game::handleEndMaze(SDL_Renderer* renderer, Map& gameMap, player& nhanvat, int& countdown_time, int& last_time, SDL_Texture*& wallTexture)
{
    SDL_Event e;
    bool running = true;

    SDL_Rect continueButton = { 350, 150, 200, 50 };
    SDL_Rect exitButton = { 350, 250, 200, 50 };

    // Mo font ngoai vong lap
    TTF_Font* font = TTF_OpenFont("fonts/tahoma.ttf", 24);
    if (!font) {
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
                    wallTexture = gameMap.loadRandomMap(renderer);
                    nhanvat.resetPosition();
                    gameMap.drawMap(renderer, wallTexture);

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

void Game::QuitGame() {

    TTF_Quit(); Mix_CloseAudio();
    // Clean up SDL & exit program  
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
