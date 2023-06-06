//2.24.2023
//Diya Tomar
//This program determines which of the integers from 1 to N are 
//perfect numbers, where the sum of its factors (including 1 but not 
//the number) sum up to that number.

#include <iostream>//for outputting the results to the screen

using namespace std;//allows the usage of keywords such as cout and cin

//the userInput function asks the user for the upper limit value
//and checks to see if the value is valid (> 0)
void userInput(int &N) {//userInput function declaration
    //ask the user to input the upper limit
    cout << "Enter your upper limit: ";
    cin >> N;
    
    //while the upper limit value is less than 1
    while (N < 1) {
        //tell the user to input a new upper limit value
        cerr << "You did not enter an integer greater or equal to 1. Enter another integer: ";    
        cin >> N;
    }
}//end userInput

//the checkInteger function checks to see which integers below
//the upper limit are perfect numbers. 
bool checkInteger(int integer) {//checkInteger function declaration
    
    //initializing the variable for the sum of the factors
    int sum = 0;

    //this for loop goes through all values below the integer
    for (int integer2 = 1; integer2 < integer; integer2++) {
        //if the remainder of the integer divided by integer2 is 0
        //this means that integer2 is a factor of the integer
        if (integer % integer2 == 0)
            //add the factor to the sum
            sum += integer2;
    }
    //if the sum is equal to the integer
    if (sum == integer) {
        //it is a perfect number, so return true
        return true;
    }
    //else if the sum is not equal to the integer
    else
        //return false
        return false;
}//end checkInteger
    

int main() {//main function declaration
    
    //initializing variable for the upper limit
    int N = 0;
    
    //calling the userInput function
    userInput(N);
    
    //header for list of perfect numbers
    cout << "The perfect numbers are:" << endl;
    
    //this for loop goes through all integers below the upper limit
    for (int integer = 1; integer < N; integer++) {
        //the perfectNumber variable will be true or false
        //depending on what the checkInteger function returns
        bool perfectNumber = checkInteger(integer);
        //if the integer is a perfect number
        if (perfectNumber == true) {
            //print the integer
            cout << integer << endl;
        }
    }
    
    return 0;//if everything works, return 0
}//end main
