#include "highScore.h"
#include <fstream>
#include <algorithm>

highScore::highScore(const std::string& filename) : filePath(filename) {
    loadScores();
}

void highScore::loadScores() {
    scores.clear();
    std::ifstream readFile(filePath);
    if (!readFile.is_open()) {
        std::cerr << "Failed to open " << filePath << " for reading high score." << std::endl;
        return;
    }

    int score;
    while (readFile >> score) {
        scores.push_back(score);
    }
    readFile.close();
    std::sort(scores.rbegin(), scores.rend()); // Sort scores in descending order
}

void highScore::update(int newScore) {
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