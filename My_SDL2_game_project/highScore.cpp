#include "highScore.h"
#include <fstream>
#include <algorithm>

highScore::highScore(const std::string& filename) : filePath(filename) {
    loadScores();
}

void highScore::loadScores() 
{
    scores.clear();
    std::ifstream readFile(filePath);
    if (!readFile.is_open()) 
    {
        std::cerr << "Failed to open " << filePath << " for reading high score." << std::endl;
        return;
    }

    int score;
    while (readFile >> score) 
    {
        scores.push_back(score);
    }
    readFile.close();
    std::sort(scores.rbegin(), scores.rend()); // Sort scores in descending order
}

void highScore::update(int newScore) 
{
    scores.push_back(newScore);
    std::sort(scores.rbegin(), scores.rend()); // Sort scores in descending order

    if (scores.size() > 5) {
        scores.resize(5);
    }

    saveScores();
}

void highScore::saveScores() {
    std::ofstream fileOut(filePath, std::ios::trunc);
    if (!fileOut.is_open()) {
        std::cerr << "Failed to open " << filePath << " for writing high score." << std::endl;
        return;
    }

    for (int highScore : scores) {
        fileOut << highScore << std::endl;
    }
    fileOut.close();
}

std::vector<int> highScore::getHighScores() {
    return scores;
}

void highScore::displayHighScores (SDL_Renderer* renderer, highScore& hs, TTF_Font* font)
{
    //SDL_RenderClear(renderer);
    std::vector<int> highScores = hs.getHighScores();

    int yPosition = 100;  // Bắt đầu từ vị trí y này trên màn hình
    for (int score : highScores) 
    {
        std::string scoreText = "Highest score: " + std::to_string(score);
        SDL_Surface* textSurface = TTF_RenderText_Solid(font, scoreText.c_str(), { 255, 255, 255 });

        if (textSurface == NULL) { std::cerr << "Unable to create high score texture from surface: " << SDL_GetError() << std::endl; continue; }
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if (textTexture == NULL) std::cerr << "Unable to high score texture from surface: " << SDL_GetError() << std::endl;
        else {
            SDL_Rect textRect = { 100, yPosition, textSurface->w, textSurface->h };
            SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
            //SDL_FreeSurface(textSurface);
            SDL_DestroyTexture(textTexture);
            
        }
        SDL_FreeSurface(textSurface);
        yPosition += 30;  // Cập nhật vị trí y cho mỗi điểm số cao
        
    }
    SDL_RenderPresent(renderer);
}