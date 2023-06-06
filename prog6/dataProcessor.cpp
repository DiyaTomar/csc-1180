//Program 6, main program

#include "yourHeader.h" //put your functions in a header file

#include <iostream>//for outputting the results to the screen
#include <fstream>//for file input

using namespace std;//allows the usage of keywords such as cout and cin

int main() {//main function declaration
    
    //open files first
    ifstream input;
    ofstream output;

    //function that opens the files
    openFiles(input,output);

    if ( !input || !output ) {//if either file failed to open
        cerr << "Error opening files. Terminating program." << endl;
        return -1;
    }//end if

    int rows;//holds the number of rows
   
    getRows(input, rows);//pass by reference

    //declare array
    //NOTE: COLUMNS is defined in the header file!
    double theData[rows][COLUMNS] = {0};//all zeros!

    //get the data into the array
    fillArray(input, theData, rows);

    //print Row sums
    printRowInfo(output, theData, rows);

    //print Column sums
    printColInfo(output, theData, rows);

    //print Summary
    printSummary(output, theData, rows);
    
    //close files
    input.close();
    output.close();
    
    return 0;//if everything works fine, return 0
    
}//end main
