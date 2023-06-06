//3.3.2023
//Diya Tomar
//The following code contains different functions used by the 
//dataProcessor.cpp file. The overall purpose served by these functions 
//is to calculate the sum and averages of the rows and columns of values
//provided by the input file. 

//constant for the number of columns (will always have 10 columns)
const int COLUMNS = 10;

#include <fstream>//for file input and output
#include <iostream> //for cout and endl
#include <iomanip>//for setprecision and setw


//the openFiles function opens the input file to read in its data and
//and output file to store the results
void    openFiles(std::ifstream &input, std::ofstream& output)
{//openFiles function declaration
    
    input.open("numbers.dat");//opening the input file "numbers.dat"
    output.open("sum.txt"); //opening an output file called "sum.txt"
    
}//end openFiles


//the getRows function reads in the number of rows in the input file,
//which is the first value provided in the file
void    getRows(std::ifstream &input, int& rows) 
{//getRows function declaration
    
    //reading in the # of rows in the input file 
    input >> rows;
    
}//end getRows


//the fillArray function fills the theData array with the values from 
//the input file
void    fillArray(std::ifstream& input, double theData[][COLUMNS], int rows)
{//fillArray function declaration
    
    //this for loop goes through each row
    for (int rowCount = 0; rowCount < rows; rowCount++) {
        //this for loop goes through each column
        for (int columnCount = 0; columnCount < COLUMNS; columnCount++) {
            //the theData array reads in a value from the input file
            //and stores it in the corresponding place in the array
            //determined by the row and column indices
            input >> theData[rowCount][columnCount];
        }
    }
}//end fillArray


//the printRowInfo function calculates the sum and average of each row 
//and prints it to the output file and screen
void    printRowInfo(std::ofstream &output, double theData[][COLUMNS], int rows)
{//printRowInfo function declaration  
    
    //setting the precision of the values to 2 decimal places
    output << std::setprecision(2) << std::fixed;
    std::cout << std::setprecision(2) << std::fixed;
    
    //initializing the sum and average variables
    double sum = 0.0;
    double average = 0.0;
    
    //this for loop goes through each row of data
    for (int rowCount = 0; rowCount < rows; rowCount++) {
        //this for loop goes through each column in the row
        for (int columnCount = 0; columnCount < COLUMNS; columnCount++) {
            //adds each value in the row to the sum
            sum += theData[rowCount][columnCount];
        }
        //calculates the average by dividing the sum by the # of columns
        average = sum / COLUMNS;
        
        //outputting the sum and average of each row to the file (adding
        //1 to the rowCount to print out row # and not the index value) 
        output << "row " << rowCount + 1 << " - sum: " << sum 
               << ", average: " << average << std::endl;
        //outputting the sum and average of each row to the screen (adding
        //1 to the rowCount to print out row # and not the index value) 
        std::cout << "row " << rowCount + 1 << " - sum: " << sum 
                  << ", average: " << average << std::endl;
         
        //resetting the sum and average values to 0 
        sum = 0.0;
        average = 0.0;
        
    }
    //printing blank line to file and screen to print next row's
    //information on the next line
    output << std::endl;
    std::cout << std::endl;
    
}//end printRowInfo


//the printColInfo function calculates the sum and average of each column 
//and prints it to the output file and screen 
void    printColInfo(std::ofstream &output, double theData[][COLUMNS], int rows)
{//printColInfo function declaration
    
    //initializing the sum and average variables
    double sum = 0.0;
    double average = 0.0;
    
    //this for loop goes through each column of data
    for (int columnCount = 0; columnCount < COLUMNS; columnCount++) {
        //this for loop goes through each row in the column
        for (int rowCount = 0; rowCount < rows; rowCount++) {
            //adds each value in the column to the sum
            sum += theData[rowCount][columnCount];
        }
        //calculates the average by dividing the sum by the # of rows
        average = sum / rows;
        //outputting the sum and average of each column to the file (adding
        //1 to the columnCount to print out column # and not the index value) 
        output << "column " << columnCount + 1 << " - sum: " << sum 
               << ", average: " << average << std::endl;
        //outputting the sum and average of each column to the screen (adding
        //1 to the columnCount to print out column # and not the index value) 
        std::cout << "column " << columnCount + 1 << " - sum: " << sum 
                  << ", average: " << average << std::endl;
        
        //resetting the sum and average values to 0 
        sum = 0.0;
        average = 0.0;
    } 
    
    //printing blank line to file and screen to print next column's
    //information on the next line
    output << std::endl;
    std::cout << std::endl;
}//end printColInfo


//the printSummary function prints the overall sum and average of the 
//data to the output file and screen
void    printSummary(std::ofstream &output, double theData[][COLUMNS], int rows)
{//printSummary function declaration
    
    //initializing the overall sum and overall average variables
    double overallSum = 0.0;
    double overallAverage = 0.0;
    
    //this for loop goes through each row of data
    for (int rowCount = 0; rowCount < rows; rowCount++) {
        //this for loop goes through each column of data
        for (int columnCount = 0; columnCount < COLUMNS; columnCount++) {
            //adds the value at the current row and column position
            //(specified by the indices) to the overall sum 
            overallSum += theData[rowCount][columnCount];
        }
    }
    
    //calculates the overall average by dividing the overall sum by the
    //the # of rows multiplied by the # of columns
    overallAverage = overallSum / (rows * COLUMNS);
    
    
    //outputting the overall sum and overall average to the output file
    output << "overall - sum: " << overallSum << ", average: " << overallAverage;
    //outputting the overall sum and overall average to the screen
    std::cout << "overall - sum: " << overallSum << ", average: " << overallAverage;
    
}//end printSummary

