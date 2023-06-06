//3.7.2023
//Diya Tomar
//This program reads a text file and outputs the letters, together with 
//their counts and percentages. The work done in this program is mainly
//completed inside functions, and the main function merely consists of 
//function calls and variable declarations.

#include <iostream>//for outputting the results to the screen
#include <fstream> //for file input and output
#include <iomanip> //for output manipulation
#include <string> //for file names
#include <cctype> //for toupper function

using namespace std;//allows the usage of keywords such as cout and cin

const int SIZE = 27;//constant for the size of the alphabetCount array

//constant that represents the ASCII value of 'A'. This value will
//be useful when storing the frequency of each letter in the correct 
//index of the alphabetCount array
const int CONVERSION = 65;

//the openFiles function asks the user for the names of the 
//input and output files and opens the input and output files.
//parameters are the input and output streams
void openFiles(ifstream &input, ofstream &output) {//openFiles function declaration
    
    //declaring variables for the names of the input and output files
    string iName, oName; 
    
    //asking user to enter the name of the input file
    cout << "Enter input file name: ";
    cin >> iName;
    
    //asking user to enter the name of the output file
    cout << "Enter output file name: ";
    cin >> oName;
    
    //opens the input and output files
    input.open(iName);
    output.open(oName);
    
    //prints the name of the file being analyzed (input file)
    output << "Analysis of file " << iName << ":" << endl;
    
}//end openFiles


//the countFrequencies function checks each letter in the input file
//and stores the frequency of each alphabet in the appropriate
//index of the alphabetCount array
//parameters are the input stream and the array storing the frequency
//for each alphabet
void countFrequencies(ifstream &input, int alphabetCount[]) {//countFrequencies function declaration
    
    //declaring variable that will store each letter read in from the
    //input file
    char letter;
    //variable for the total # of letters in the input file
    int totalLetters = 0; 
    //variable representing an index value in the alphabetCount array
    int index = 0;
    
    //reads in the first character in the input file
    input >> letter;
    
    while (input) {//while there are characters to be read from the input file
        
        if (isalpha(letter)) {//if the character is an alphabet
            //calculating the index value by subtracting the letter's
            //ASCII value by the ASCII value of 'A' (ex. if letter is 'A',
            //the index value will be 0, meaning that the frequency of 
            //'A' will be stored at index 0) 
            index = toupper(letter) - CONVERSION;
            //increasing value stored in that index by 1 (to account for 
            //the occurence of the alphabet in the input file)
            alphabetCount[index]++;
            //incrementing the total letters in the input file by 1
            totalLetters++;
        }
        //reading in the next letter in the input file
        input >> letter;
    }
    
    //storing the total # of letters in the last index of the
    //alphabetCount array (which is why it is SIZE - 1, since SIZE = 27)
    alphabetCount[SIZE - 1] = totalLetters;

}//end countFrequencies

//the printResult function outputs the total occurence of each alphabet
//and the percentage of the text that occupied by each alphabet
//parameters are the output stream and the array storing the frequency
//for each alphabet
void printResult(ofstream &output, int alphabetCount[]) {//printResult function declaration
    
    //printing header for the results
    output << "Letter     Count        %" << endl;
    output << "-------------------------" << endl;
    
    //variable for the total # of alphabets (value stored in 26th index
    //of alphabetCount
    double total = alphabetCount[SIZE - 1];
    
    //setting precision of percentages to 0
    output << setprecision(0) << fixed;
    
    //this for loop goes through each index of the array to print out
    //the results for each alphabet (excluding the last index since that
    //is storing the total # of letters, hence the SIZE - 1)
    for (int index = 0; index < SIZE - 1; index++) {
        //adding the CONVERSION value and the index value to get the 
        //ASCII value of each alphabet (ex. 65 + 0 = 65, which is 'A')
        //and then output the corresponding character
        output << char(CONVERSION + index);
        //outputting the frequency of each alphabet
        output << right << setw(15) << alphabetCount[index];
        //outputting the percentage of each alphabet (calculated by
        //dividing the frequency of each alphabet by the total number of
        //alphabets, which is multiplied by 100 to get percentage)
        output << right << setw(8) << (alphabetCount[index] / total) * 100 << "%";
        //outputting blank line to print next alphabet's information
        output << endl;
    }
    
    //outputting the total # of letters in the input file
    output << "Total letters: " << total << endl; 
    
}//end printResult


int main() {//main function declaration
    
    //opening input and output files
    ifstream input;
    ofstream output;
    
    //calling the openFiles function
    openFiles(input, output);
    
    if (!input || !output) {//if either file failed to open
        //tell user there's an error with opening the files
        cerr << "Error opening files. Terminating program." << endl;
        return -1;//error code
    }
    
    //the alphabetCount array stores the frequency of each letter in the
    //input file and the total # of letters in the file
    int alphabetCount[SIZE] = {0};
    
    //calling the countFrequencies function
    countFrequencies(input, alphabetCount);
    
    //calling the printResult function
    printResult(output, alphabetCount);

    return 0;//if everything works, return 0
    
}//end main
