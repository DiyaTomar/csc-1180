/* Card class
 * Includes enumerated types Face and Suit
*/
#pragma once //this tells the compiler to only include this file one time
#include <iostream>
#include <string>

enum Face {Two=2,Three,Four,Five,Six,Seven,Eight,Nine,Ten,Jack,Queen,King,Ace};
     //start index at 2 for face values, will update Jack - Ace in constructor

enum Suit {Hearts,Spades,Diamonds,Clubs};
    //0-3 for indexing

class Card {
    private:
        Face face;
        Suit suit;
        int value;
    public:
        Face getFace() const;
        Suit getSuit() const;
        void setFace(Face);
        void setSuit(Suit);
        int getValue() const;
        Card(Face=Ace,Suit=Spades);
        bool operator==(const Card&);
        friend std::ostream& operator<<(std::ostream&, const Card&);
};
//overloaded comparison (equality) operator
bool Card::operator==(const Card& other)
{
    return (face == other.face && suit == other.suit);
}

//overloaded stream insertion
std::ostream& operator<<(std::ostream& out, const Card& c)
{
    std::string FACES[] = {"Two","Three","Four","Five","Six","Seven","Eight","Nine",
                               "Ten","Jack","Queen","King","Ace"};
    std::string SUITS[] = {"Hearts","Spades","Diamonds","Clubs"};
    //note that we started the values at 2, so we have to subtract 2 to get the proper index
    //for the face, suit is the proper index
    out << FACES[c.face-2] << " of " << SUITS[c.suit];
    return out;
}

//get methods *******
Face Card::getFace() const 
{ 
    return face;
}

Suit Card::getSuit() const
{
    return suit;
}

int Card::getValue() const
{
    return value;
}
//set method *******
void Card::setFace(Face f)
{
//no validation is really needed, as the compiler will catch invalid values
    face = f;
}

void Card::setSuit(Suit s)
{
//no validation is really needed, as the compiler will catch invalid values
    suit = s;
}

//constructor *******
Card::Card(Face f, Suit s)
{
    setFace(f);
    setSuit(s);
    if ( face == Jack || face == King || face == Queen )
        value = 10;
    else if ( face == Ace )
        value = 11;
    else
        value = face;
}

