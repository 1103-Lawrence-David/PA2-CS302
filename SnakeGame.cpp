#include "SnakeGame.h"

SnakeGame::SnakeGame(int seed){
    randomState = seed;
    resetGame();
}

int SnakeGame::getCustomRandom(int min, int max){
    randomState = ((randomState ^ 146959) * 10995); //loosely based on FNV1-A, but the primes were too big. whoops.
    int range = max - min + 1;
    return min + (int)(randomState % range);
}

// Spawns food at an unoccupied position
void SnakeGame::spawnFood(){
    bool invalidLocation = true;

    while(invalidLocation){
        invalidLocation = false;
        int r = getCustomRandom(1, rows - 2);
        int c = getCustomRandom(1, cols - 2);
        food = Position(r, c);

        // Ensure food does not land on the snake body matching alias parameters
        for(int i = 0; i < snake.getLength(); i++){
            if(snake.get(i) == food){
                invalidLocation = true;
                break;
            }
        }
    }
}

// Resets/Initializes game parameters
void SnakeGame::resetGame(){
    snake.clear();
    score = 0;
    gameOver = false;
    direction = 'D';

    snake.insert(0, Position(7, 5));
    snake.insert(1, Position(7, 4));
    snake.insert(2, Position(7, 3));

    spawnFood();
}

bool SnakeGame::isGameOver(){ 
    return gameOver; 
}

int SnakeGame::getScore(){ 
    return score; 
}

// Handles input changes while ignoring instant 180-degree pivots
void SnakeGame::setDirection(char input){
    if(input == 'W' || input == 'w'){
        direction = 'W';
    }

    if(input == 'S' || input == 's'){
        direction = 'S';
    }

    if(input == 'A' || input == 'a'){
        direction = 'A';
    }

    if(input == 'D' || input == 'd'){
        direction = 'D';
    }
}

// Game turn logic loop
void SnakeGame::update(){
    if (gameOver) return;

    Position currentHead = snake.get(0);
    Position nextHead = currentHead;

    if(direction == 'W'){
        nextHead.row--;
    }
    
    if(direction == 'S'){
        nextHead.row++;
    }
    
    if(direction == 'A'){
        nextHead.column--;
    }

    if(direction == 'D'){
        nextHead.column++;
    }

    // Wall Collision Detection
    if(nextHead.row <= 0 || nextHead.row >= rows - 1 || nextHead.column <= 0 || nextHead.column >= cols - 1){
        gameOver = true;
        return;
    }

    // Self-Collision Detection
    for(int i = 0; i < snake.getLength(); i++){
        if(nextHead == snake.get(i)){
            gameOver = true;
            return;
        }
    }

    // Insert new head coordinates forward
    snake.insert(0, nextHead);

    // Food Target Intersection
    if(nextHead == food){
        score += 10;
        spawnFood(); // Grows automatically by keeping the current tail intact
    }
    else{
        // Prune the previous tail node to advance forward cleanly
        snake.remove(snake.getLength() - 1);
    }
}

// Renders the board map grid via basic newlines
void SnakeGame::draw(){
    for(int i = 0; i < 40; ++i){
        cout << '\n';
    }

    cout << "=== LEGALLY DISTINCT SNAKE ===" << endl;
    cout << "Score: " << score << "\tCurrent Length: " << snake.getLength() << endl;
    cout << "Controls: W(up), A(left), S(down), D(right) | Q(quit)" << endl;

    for(int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            Position currentCell(r, c);

            if(r == 0 || r == rows - 1 || c == 0 || c == cols - 1){
                cout << "#";
            } 
            
            else if(currentCell == snake.get(0)){
                std::cout << "O";
            }
            
            else if(currentCell == food){
                std::cout << "*";
            }
            
            else{
                bool isBody = false;
                for(int i = 1; i < snake.getLength(); i++){
                    if(currentCell == snake.get(i)){
                        isBody = true;
                        break;
                    }
                }

                if(isBody){
                    std::cout << "o";
                }
                
                else{
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
}