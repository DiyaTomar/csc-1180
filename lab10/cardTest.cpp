/* Program to test the Card class
 * Lab 10, CSC 1180
 * April 4, 2023
*/
#include "Card.h"

#include <iostream>
using namespace std;

int main() {

    Card myCard; //the default card
    Card yourCard(Jack, Hearts);//card is specifically Jack of Spades

    cout << "My card is: " << myCard << endl;
    cout << "Your card is: " << yourCard << endl;

    if ( myCard == yourCard )
        cout << "We have the same card!" << endl;
    else
        cout << "Our cards are different." << endl;

    cout << "My card value is: " << myCard.value() << endl;
    cout << "Your card value is: " << yourCard.value() << endl;

    return 0;

}

/* Example output:
   My card is: Ace of Spades
   Your card is: Jack of Hearts
   Our cards are different.
   My card value is: 11
   Your card value is: 10
*/   
