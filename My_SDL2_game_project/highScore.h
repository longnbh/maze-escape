#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <vector>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <iostream>

class highScore {
public:
    highScore(const std::string& filename);
    void update(int newScore);
    std::vector<int> getHighScores();
    static void displayHighScores(SDL_Renderer* renderer, highScore& hs, TTF_Font* font);

private:
    std::string filePath;
    std::vector<int> scores;
    void loadScores();
    void saveScores();
};

#endif // HIGHSCORE_H
