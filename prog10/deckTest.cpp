#include "Deck.h"

#include <iostream>
using namespace std;

int main() {

    Deck newDeck;//creates a new deck

    cout << newDeck << endl;//prints the deck, one card per line

    newDeck.shuffle();//shuffles the deck, so cards are in random order

    cout << newDeck << endl;//prints the deck again, to illustrate shuffling occurred

    //now deal one card
    cout << newDeck.deal() << endl;
    
    cout << newDeck.getDoC() << endl;

    return 0;

}    

