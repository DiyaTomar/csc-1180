//BlackJack main program

#include <iostream>
#include "BlackJack.h"

int main() {
    
    char again;//continue flag
    BlackJack game;//instance of game
    
    do {
        game.play();
        game.reset();
        std::cout << "Play again? (Y or N): ";
        std::cin >> again;
    } while (again == 'y' || again == 'Y');
    
    return 0;
}
