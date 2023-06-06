//4.4.2023
//Diya Tomar
//This header file contains a class to model a standard Card. The class
//contains three attributes: face, suit, and value. Face values can be 2
//through 10, plus Jack, Queen, King, and Ace. There are four suits: 
//Hearts, Spades, Diamonds, and Clubs. Cards 2 through 10 have their 
//face value (2 - 10). Jack, Queen, and King have value 10. Ace has 
//value 11. The implementation includes enumerated types for both the 
//Faces and Suits. 

#pragma once //ensures that this file is only included one time       
#include <iostream>//for outputting the results to the screen
#include <string>//allows for usage of string data type

//enumerated type defining the faces of a card                          
enum Faces {Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};
//enumerated type defining the suits of a card 
enum Suits {Hearts, Spades, Diamonds, Clubs};


//the Card class models a Card using face, suit, and value
class Card {
    private://access specifier, contains private class members
        Faces face;//attribute of type Faces for face
        Suits suit;//attribute of type Suits for suit
        int value;//attribute of type int for value
        
    public://access specifier, contains public class members
        //constructor with default parameters (default card is Two of Hearts)
        Card(Faces = Two, Suits = Hearts);
        
        //get methods (accessors)
        Faces getFace() const;
        Suits getSuit() const;
        int getValue() const;
        
        //set methods (mutators)
        void setFace(Faces);
        void setSuit(Suits);
        
        //overloaded equality operator, member function
        bool operator==(const Card&) const;
        //overloaded stream insertion, non-member function
        friend std::ostream& operator<<(std::ostream&, const Card&);
        
};//end class definition


//----------------------------constructor-------------------------------

//the Card constructor initializes objects and sets the object's       
//face, suit, and value
//f means face, s means suit, v means value
Card::Card(Faces f, Suits s) {
    
    //calling set methods to set face and suit value
    setFace(f);
    setSuit(s);
    
    //switch case that sets card value based on face value
    switch(face) {
        case Ace: value = 11; break;//if Ace, value is 11                   
        case King:
        case Queen:
        case Jack: value = 10; break; //if King, Queen, or Jack, value is 10
        default: value = (int)face; //otherwise, value is equal to face value
    }
}//end Card constructor

//---------------------------get methods--------------------------------

//the getFace method returns the face value    
Faces Card::getFace() const {
    return face;
}//end getFace

//the getSuit method returns the suit value
Suits Card::getSuit() const {
    return suit;
}//end getSuit

//the getValue method returns the card value
int Card::getValue() const {
    return value;
}//end getValue

//---------------------------set methods--------------------------------

//the setFace method sets the face value (f means face)
void Card::setFace(Faces f) {
    face = f;//setting face value to f
}//end setFace

//the setSuit method sets the suit value (s means suit)
void Card::setSuit(Suits s) {
    suit = s;//setting suit value to s
}//end setSuit

//----------------------------other methods-----------------------------
                                                                    
//the operation overloading function for << outputs the card's info (face and suit)
//out means output and c means card
std::ostream& operator<<(std::ostream& out, const Card& c) {
    
    //array with string equivalents of faces
    const std::string FACES[] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    //array with string equivalents of suits
    const std::string SUITS[] = {"Hearts", "Spades", "Diamonds", "Clubs"};
    
    //outputting the face and suit (subracting 2 from index value since in Faces, Two = 2); 
    out << FACES[c.face - 2] << " of " << SUITS[c.suit];
    
    //returning the output
    return out;
}

//the operation overloading function for == determines whether two cards are the same
//other means the 2nd card 
bool Card::operator==(const Card& other) const {
    //if the face and suit is the same for both cards
    if (this->face == other.face && this->suit == other.suit) {
        return true;//return true (the cards are the same)
    }
    return false;//return false (the cards are different)
}


