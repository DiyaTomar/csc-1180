//2.7.2023
//Diya Tomar
//This program reads a data file containing rows and columns of numbers
//and determines the row sums and averages 
//and the overall sum and average of all numbers in the file

#include <iostream>//for outputting the results to the screen
#include <fstream>//for file input

using namespace std;//allows the usage of keywords such as cout and cin

int main() {//main function declaration
    
    //set up input file first
    ifstream input;//declares an input file stream called 'input'
    input.open("numbers.dat");//attempts to open file for reading

    //checks that the opening of the file was successful    
    if ( !input ) { //asking if the input stream is not okay
        //outputs error message
        cerr << "Error opening input file. Check file existence." << endl;
        return -1;//terminate program with error code -1
    }
    
    //declaring variables for the # of rows and columns
    int row;
    int column;
    
    //reading the # of rows and columns from the file
    input >> row;
    input >> column;
    
    //declaring and initializing variables for:
    int rowCount = 0;//counting the number of rows
    int columnCount = 0;//counting the number of columns
    float value = 0.0;//a value read from the file
    float sum = 0.0;//the sum of the values in each row
    float average = 0.0;//the average of the values in each row
    float overallSum = 0.0;//the overall sum of all values in the file
    float overallAverage = 0.0;//the overall average of all sums
    
    
    //while the number of rows read in
    //is less than the number of rows in the file 
    while (rowCount < row) {
        columnCount = 0;//resets the column count value
        //while the number of values read from a row
        //is less than the number of values in the row
        while (columnCount < column) {
            input >> value;//read a value from the file
            sum += value;//add the value to the sum
            //calculate the average by dividing the sum
            //by the numbers of values in the row
            average = sum / column;
            columnCount++;//add 1 to the column counter
        }
        rowCount++;//add 1 to the row counter
        //outputting the sum and average of each row
        cout << "row " << rowCount << " - sum: " << sum 
             << ", average: " << average << endl;
        overallSum += sum;//adding the sum of each row to the overall sum
        sum = 0.0; //resetting the sum value
        average = 0.0; //resetting the average value
    }
    
    //calculating the overall average by dividing the overall sum
    //by the number of values in the file (found by multiplying the
    //number of rows by the number of columns)
    overallAverage = overallSum / (row * column);
    
    //printing the overall sum and average
    cout << "overall - sum: " << overallSum << ", average: " << overallAverage;
    
    
    return 0;//if everything works fine, return 0
    
}//end main
