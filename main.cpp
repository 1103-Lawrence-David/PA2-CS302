#include "SnakeGame.h"

int main() {
    runTestSuite();
    char playAgain = 'Y';
    int sessionSeed = 98765;
    
    while (playAgain == 'Y' || playAgain =='y') {
        SnakeGame game(sessionSeed);
        sessionSeed += 1234; 

        while (!game.isGameOver()) {
            game.draw();
            
            cout << "Enter move direction (W/A/S/D) or 'Q' to quit: ";
            char input;
            cin >> input;

            if (input == 'Q' || input == 'q') {
                break;
            }

            game.setDirection(input);
            game.update();
        }

        game.draw();
        cout << "\n================================" << endl;
        cout << "          GAME OVER             " << endl;
        cout << "Score: " << game.getScore() << endl;
        cout << "================================" << endl;

        cout << "Play Again? (Y/N): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing. Goodbye." << endl;
    return 0;
}