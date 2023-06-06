//4.5.2023
//Diya Tomar
//The header file contains a class to model a Deck of Cards. The class
//contains an array of 52 cards, consisting of Ace through King in each 
//of the four suits. The Deck class has methods for shuffling the deck 
//and dealing a card.

#pragma once //this tells the compiler to only include this file one time
#include "Card.h"//including contents of "Card.h" file
#include <iostream>//for outputting the results to the screen
#include <cstdlib>//for random generation
#include <ctime>//for time

const int DECK_SIZE = 52;//constant for the size of the Deck

//the Deck class models a Deck of Cards
class Deck {
    
    private://access specifier, contains private class members
        //DoC is an array containing 52 Card objects    
        //Does not have set method since deck is set in the constructor
        Card DoC[DECK_SIZE];
        //attribute of type int for index value of top card of deck 
        //does not have set method since there is no need for the value to be set
        int top;  
    
    public://access specifier, contains public class members
        Deck();//constructor
        
        //get methods (accessors)
        int getTop() const;
        const Card* getDoC() const;
        
        //overloaded stream insertion, non-member function
        friend std::ostream& operator<<(std::ostream&, const Deck&);
                                                                        
        void shuffle();//method to shuffle deck                         
        
        Card deal();//method to deal top card of deck

};//end class definition


//----------------------------CONSTRUCTOR-------------------------------

//the Deck constructor sets the face and suit values for each Card in the Deck
Deck::Deck() {
    
    int index = 0;//initializing index value of card 
    top = 0;//initializing index value of top card of deck
    
    for (int f = Two; f <= Ace; f++) {//a for loop that goes through each face value
        for (int s = Hearts; s <= Clubs; s++) {//a for loop that goes through each suit value
            DoC[index].setFace((Face)f);//set the face value
            DoC[index].setSuit((Suit)s);//set the suit value
            index++;//increment index by 1 to set next Card's face and suit value
        }
    }
}//end Deck constructor


//----------------------------GET METHODS-------------------------------

//returns top value
int Deck::getTop() const {
    return top;
}//end getTop

//returns DoC (deck of cards)
//constant pointer (address stored in array name can't be changed)
const Card* Deck::getDoC() const {
    return DoC;
}//end getDoC
                                                                            

//--------------------------OTHER METHODS-------------------------------

//the shuffle method shuffles the Cards in the Deck
void Deck::shuffle() {
    
    srand(time(0));//seed random number generator
    
    //a for loop that goes through each Card in the Deck
    for (int i = 0; i < DECK_SIZE; i++) {
        //swapping two cards in the deck (similar to c = a, a = b, b = c)
        int secondCard = rand() % DECK_SIZE; //random index value for second card being swapped
        Card j = DoC[i];//new Card object that has the card value stored at corresponding index of the Deck
        DoC[i] = DoC[secondCard];//setting the card value of the first Card to the second card being swapped
        DoC[secondCard] = j;//setting the second card value to the original card value of the first Card
    }
    
    top = 0;//resetting the index value of the top card to 0
    
}//end shuffle

//the deal method deals the top Card of the Deck
Card Deck::deal() {
    
    //if the top value is equal to the size of the Deck
    if (top == DECK_SIZE) {
        shuffle();//reshuffle the Deck                                  
    }
    
    //return the Card at the top of the Deck
    return DoC[top++];
}//end deal

//the operation overloading function for << outputs the Cards in the Deck
//out means output, deck is deck of cards
std::ostream& operator<<(std::ostream& out, const Deck& deck) {
    //a for loop that goes through each Card in the Deck
    for (int index = 0; index < DECK_SIZE; index++) {
        //outputs Card at the corresponding index (one card per line)
        out << deck.DoC[index] << std::endl;                            
    }
    
    //returning the output
    return out;
}//end stream insertion                                                                    


