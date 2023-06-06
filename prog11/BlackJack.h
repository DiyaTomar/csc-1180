//4.13.2023
//Diya Tomar
//The header file contains a class that represents the game BlackJack. 
//The BlackJack class has a Deck of Cards, a 2-card hand for the dealer,
//and a 2-card hand for the player. In this simple version, the
//winner is the one with the higher hand value for both cards combined.
//Dealer wins all ties. The dealer’s hand and the player’s hand will be
//printed, along with a message indicating who wins. The play method 
//plays one round of Black-Jack. The reset method resets both hands, and 
//reshuffles the deck.

#pragma once //this tells the compiler to only include this file one time
#include <iostream>//for outputting the results to the screen
#include "Deck.h"//including contents of "Deck.h" file
#include "Card.h"//including contents of "Card.h" file

const int HAND_SIZE = 2;//constant for the size of the dealer and player's hands

//the BlackJack class represents the game BlackJack
class BlackJack {
    
    private://access specifier, contains private class members
        Card dHand[HAND_SIZE];//dealer's hand, array containing 2 Card objects
        Card pHand[HAND_SIZE];//player's hand, array containing 2 Card objects
        Deck bjDeck;//attribute of type Deck for card deck for BlackJack
        
    public://access specifier, contains public class members
        BlackJack();//constructor
        void play();//method to play a round of BlackJack
        void reset();//method to reset game (shuffle deck, reset hands)
        
        //There are no get/set methods because in the context of a
        //BlackJack game, there is no need to make changes to the hands
        //or deck since the class is only required to be accessed to
        //simulate the game and not to manipulate the hands or deck
        //in the game.
        
    
};//end class definition

//the BlackJack constructor shuffles the card deck
BlackJack::BlackJack() {
    
    bjDeck.shuffle();//shuffling the card deck
    
}//end BlackJack constructor

//the play method plays a round of BlackJack 
void BlackJack::play() {
    
    //variables to store total value of dealer and player's hands
    int dVal = 0;
    int pVal = 0;
    
     //a for loop that keeps going till the dealer and player have 2 cards
    for (int i = 0; i < HAND_SIZE; i++) {
        //dealing card to dealer and storing it at corresponding index of array
        dHand[i] = bjDeck.deal();
        //dealing card to player and storing it at corresponding index of array
        pHand[i] = bjDeck.deal();
    }
    
    //printing the cards in the dealer and player's hands
    std::cout << "Dealer has: " << dHand[HAND_SIZE - 2] << ", " << dHand[HAND_SIZE - 1] << std::endl;
    std::cout << "Player has: " << pHand[HAND_SIZE - 2] << ", " << pHand[HAND_SIZE - 1] << std::endl;
    
    //a for loop that keeps going till values of cards in dealer and 
    //player's hands are added to their total hand value
    for (int i = 0; i < HAND_SIZE; i++) {
        dVal += dHand[i].getValue();
        pVal += pHand[i].getValue();
    }
    
    
    if (dVal > pVal) { //if dealer's hand value is greater than player's hand value
        std::cout << "Dealer Wins!" << std::endl; //Dealer wins
    }
    else if (dVal == pVal) {//if both hands are the same total value
        std::cout << "Tie, Dealer Wins!" << std::endl; //Dealer wins 
    }
    else {//if player's hand value is greater than dealer's hand
        std::cout << "Player Wins!" << std::endl;//Player wins
    }
    
}//end play

//the reset methods reshuffles card deck
void BlackJack::reset() {
    
    bjDeck.shuffle();//shuffling the card deck
    
    //this method does not contain code to reset the dealer and
    //player's hand because this is done when the play method is called,
    //where the dealer and player are dealt new cards
    
}//end reset
