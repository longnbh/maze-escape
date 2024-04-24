#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <vector>
#include <string>

class highScore {
public:
    highScore(const std::string& filename);
    void updateHighScores(int newScore);
    std::vector<int> getHighScores();

private:
    std::string filePath;
    std::vector<int> scores;
    void loadScores();
    void saveScores();
};

#endif // HIGHSCORE_H
