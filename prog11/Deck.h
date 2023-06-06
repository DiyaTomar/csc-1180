/* Deck class for project 10
 Jacob Somervell
 April 10, 2023
*/
#pragma once

#include "Card.h"
#include <cstdlib> //for random numbers
#include <ctime>

//there are 52 cards, create a constant for that number
const int DECK_SIZE = 52;

class Deck
{
    private:
        Card *theDeck;//pointer to deck of cards
        //you can use an array here if you prefer
        int top;//keep track of the top of the deck
    
    public:
        ~Deck();//I have to deallocate any memory
        Deck();//constructor
        void shuffle();//shuffle the deck
        Card deal();//return the top card
        int getTop() const;//what is the top of the deck
        //stream insertion, for printing
        friend std::ostream& operator<<(std::ostream&, const Deck&);
    
};//end class Deck
Deck::~Deck()
{
    //make sure I deallocate any memory
    delete [] theDeck;
}

Deck::Deck()
{
    std::srand(time(0));//seed random number generator, this only happens once

    theDeck = new Card[DECK_SIZE];//allocate a new array on the heap

    int counter = 0;//local variable to keep track of where we are in the deck

    //this loop updates the cards with the correct faces and suits
    for ( int s = Hearts; s <= Clubs; s++) //loop for suits
        for ( int f = Two; f <= Ace; f++) {//loop for faces
            theDeck[counter].setFace((Face)f);//convert the integer to the Face type
            theDeck[counter].setSuit((Suit)s);//convert the integer to the Suit type
            counter++;//update counter
        }
    top = 0;//start at zero and go up for dealing purposes
}//end constructor

std::ostream& operator<<(std::ostream& out, const Deck& d)
{
//run through each card in the deck, printing it directly
//recall that the Card class has overloaded stream insertion
    for(int i = 0; i < DECK_SIZE; i++)
        //access theDeck in the d object, allowed because it is a friend function
        out << d.theDeck[i] << std::endl;
    return out;//return the modified stream object
}
Card Deck::deal()
{
//if we have dealt the last card, reshuffle the deck before dealing another
    if ( top == DECK_SIZE )
        shuffle();
//this returns a copy of the "top" card AND updates the top of the deck
    return theDeck[top++];
}
void Deck::shuffle()
{
    for(int i = 0; i < 1000; i++) //loop runs 1000 times, should be enough
    {
        int index1 = rand()%DECK_SIZE;//find a random card in the deck
        int index2 = rand()%DECK_SIZE;//find another
    //swap the cards using a temp variable
        Card temp = theDeck[index1];
        theDeck[index1] = theDeck[index2];
        theDeck[index2] = temp;
    }//end for

    top = 0;//reset the top of the deck
}//end shuffle method
