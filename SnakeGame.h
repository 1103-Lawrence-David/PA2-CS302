#include "tests.h"
using SnakeBody = LinkedList<Position>;
#ifndef SNAKEGAME_h
#define SNAKEGAME_H

class SnakeGame{
    int rows = 10;
    int cols = 25;

    SnakeBody snake;
    Position food;
    char direction; 
    int score;
    bool gameOver;

  
    unsigned long long randomState;

    int getCustomRandom(int min, int max);
    void spawnFood();

    public:
        SnakeGame(int seed = 12345);
        void resetGame();
        bool isGameOver();
        int getScore();
        void setDirection(char input);
        void update();
        void draw();
};

#endif