//2.28.2023
//Diya Tomar
//This program asks the user for a non-negative integer and produces
//a "diamond" of that size to the screen. If the integer is even, 
//the program will convert it to an odd number (by adding 1)

#include <iostream>//for outputting the results to the screen

using namespace std;//allows the usage of keywords such as cout and cin

int main() {//main function declaration
    
    //initializing the variable for the 
    //non-negative integer (the size of the diamond)
    int positiveInt = 0;
    
    //asks user for the size of the diamond
    cout << "Enter the size of the diamond (> 0): ";
    cin >> positiveInt;
    
    //if inputted value is less than 0
    while (positiveInt < 0) {
        //tell user to enter a positive value
        cerr << "Only positive values accepted!" << endl;                
        //ask user to input a non-negative integer (size of diamond)
        cout << "Enter the size of the diamond (> 0): ";
        cin >> positiveInt;
    }
    
    //if the integer is even
    if (positiveInt % 2 == 0) {
        //tell the user the even number will be converted to an odd number
        cout << positiveInt << " is even, converting it to odd: ";
        //add 1 to the integer
        positiveInt++;
        //print the new size of the diamond
        cout << positiveInt << endl; 
    }
    
    //initializing variables for the # of spaces and stars to start with
    int spaces = positiveInt / 2;
    int stars = 1;
    
    //a for loop that runs the amount of times specified by the size
    //of the diamond to print out the diamond
    for(int size = 0; size < positiveInt; size++) {
        //a for loop that continues till the number of spaces required
        //on the left side of the star(s) are printed
        for (int blank = 0; blank < spaces; blank++) {
            cout << " ";
        }
        //a for loop that prints the # of stars required in the row
        for (int asterisk = 0; asterisk < stars; asterisk++) {
            cout << "*";
        }
        
        //printing a blank line moves on to the next row of spaces & stars to be printed
        cout << endl;
        

        //if the # of stars printed in the row is not equal to the 
        //value of the size of the diamond (not at the halfway point)
        if (size < positiveInt / 2) {
            //print one less space in the next row
            spaces--;
            //increase the # of stars being printed by two
            //since each row will have an odd number of stars
            stars += 2;
        } 
        //else if the # of stars printed in the row is equal
        //to the value of the size of the diamond (you're at the
        //halfway point)
        else {
            //print an extra space in the next row
            spaces++;
            //decrease the # of stars being printed by two
            stars -= 2;
        }
        
        
    }
    
    return 0; //if everything works, return 0
}//end main
