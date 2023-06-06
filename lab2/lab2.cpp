//1.31.2023
//Diya Tomar
//This program counts the number of vowels in a text file.
//It only counts the vowels A, E, I, O, and U.
//Includes both upper and lowercase versions of the vowels in the counts.

#include <iostream> //for outputting the results to the screen
#include <fstream> //for file input
#include <string> //for the string type
#include <cstdio> //for the EOF definition

using namespace std;//allows the usage of keywords such as cout and cin

int main() {//main function declaration

    //declare variable storage for counts here
    int aCount = 0;//variable for counting A's
    int eCount = 0;//variable for counting E's
    int iCount = 0;//variable for counting I's
    int oCount = 0;//variable for counting O's
    int uCount = 0;//variable for counting U's

	//Lets the user know that the program will count the number of vowels in the given input file
    cout << "This program will count the number of vowels in a given input file." << endl;

    string fileName;//this variable holds a sequence of characters (string)
    cout << "Enter the file name: ";
    cin >> fileName;//remember, this ignores whitespace

    ifstream input;//this declares an input file stream called 'input'
    input.open(fileName);//this opens the file given by the user
    //the input file MUST be in the same directory as the program executable

    //this section checks that the opening of the file was successful    
    if ( !input ) { // ! means NOT, so this is asking if the input stream is NOT okay
        cerr << "Error opening file. Check file name. Make sure file is in directory. Terminating." << endl;
        return 1;
    }

    char ch; //ch stores one character
    ch = input.get();//get first character
    //the get function returns one character from the stream

    while ( ch != EOF ) {//loop to continue getting characters, one at a time
    //EOF stands for End Of File and is a defined constant in the cstdio header
        
        //if the character is an upper or lowercase A
        if (ch == 'a' or ch == 'A') {
			aCount += 1;//add a value of 1 to the a-counter
		}
		//if the character is an upper or lowercase E
		else if (ch == 'e' or ch == 'E') {
			eCount += 1;//add a value of 1 to the e-counter
		}
		//if the character is an upper or lowercase I
		else if (ch == 'i' or ch == 'I') {
			iCount += 1;//add a value of 1 to the i-counter
		}
		//if the character is an upper or lowercase O
		else if (ch == 'o' or ch == 'O') {
			oCount += 1;//add a value of 1 to the o-counter
		}
		//if the character is an upper or lowercase U
		else if (ch == 'u' or ch == 'U') {
			uCount += 1;//add a value of 1 to the u-counter
		}

        ch = input.get();//get the next character from the file

    }//end while loop

    //output the results
    cout << "The number of A's is: " << aCount << endl;//outputting the count for A's    
    cout << "The number of E's is: " << eCount << endl;//outputting the count for E's 
    cout << "The number of I's is: " << iCount << endl;//outputting the count for I's  
    cout << "The number of O's is: " << oCount << endl;//outputting the count for O's 
    cout << "The number of U's is: " << uCount << endl;//outputting the count for U's 

    return 0;//if everything works fine, return 0
}//end main
