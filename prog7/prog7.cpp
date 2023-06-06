//3.6.2023
//Diya Tomar
//This program analyzes the frequencies and probabilities of rolling the
//various possible numbers when throwing two fair 6-sided dice. The program
//simulates 1000 dice rolls, calculates the frequency of occurrence for 
//each possible outcome, and then prints a nice summary of the results 
//using a histogram approach.

#include <iostream>//for outputting the results to the screen
#include <iomanip>//for output manipulation
#include <cstdlib>//for random generation
#include <ctime>//for time

using namespace std;//allows the usage of keywords such as cout and cin

const int SIZE = 13; //constant for the size of the array
const int numRolls = 1000; //constant for # of dice rolls


//the simulate function simulates 1000 dice rolls (2 dices per roll),
//calculates the sum of the values from each roll, and calculates and
//stores the frequency of the occurence of each dice roll sum in the
//frequencies array
void simulate(int frequencies[]) {//simulate function declaration
    
    int dice1; //declaring variable for the first dice roll
    int dice2; //declaring variable for the second dice roll
    
    
    //this for loops runs 1000 times to simulate 1000 dice rolls
    for (int index = 0; index < numRolls; index++) {
        int sum = 0; //initializing variable for the sum of the dice rolls (resets every iteration)
        //the remainder of the random number generated will represent
        //the dice roll (adding 1 in case there is no remainder (so roll
        //will be 1))
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;//second dice roll
        sum = dice1 + dice2;//adding dice roll values to the sum
        //adding 1 to the value stored at the index (the sum value
        //is the index position at which the # of times the sum is 
        //rolled is stored)
        frequencies[sum] += 1;
    }

}//end simulate


//the printHistogram function prints out a histogram that summarizes
//the results of the dice simulation
void printHistogram(int frequencies[]) {//printHistogram function declaration
    
    //setting precision for probability value
    cout << setprecision(1) << fixed;
    
    //initializing variable for the probability 
    double probability = 0.0;
    //initializing variable that determines the # of * to print for each
    //histogram bar
    int numAsterisks = 0;
    
    
    //printing the # of rolls
    cout << "[" << numRolls << " rolls]" << endl;
    
    //printing titles for histogram columns (note: considering the setw
    //values and length of each column title, the header has a width of 
    //61, this value impacts the formatting of the columns)
    cout << left << setw(6) << "Num" 
         << left << setw(1) << "Count" 
         << right << setw(50) << "Probability" << endl;
    
    //this for loop prints a row for each sum and its frequency 
    for (int index = 2; index < SIZE; index++) {
        //printing out the sum and its frequency
        cout << right << setw(2) << index << ":" 
             << right << setw(4) << "(" << setw(3) << frequencies[index] 
             << ") ";
        
        //calculating the probability by dividing the sum frequency by 10
        probability = frequencies[index] / 10.0;
        //the # of asterisks that will be printed out is determined
        //by the probability (ex. if probability is 10.2, then 10
        //asterisks will be printed)
        numAsterisks = probability;
        
        //this for loop runs 38 times (number established by setw values) 
        //and prints out the number of asterisks established by the 
        //probability. Once the # of asterisks are printed, the rest of 
        //the bar is filled with whitespace to assist with formatting
        for (int format = 0; format < 38; format++) {
            //if the total number of asterisks that need to be printed
            //to represent probability are not printed
            if (numAsterisks > 0) {
                cout << "*";//print an asterisks
                numAsterisks--;//reduce value of numAsterisks by 1
            }
            //if the # of asterisks that need to be printed for the bar
            //have been printed
            else {
                cout << " ";//print whitespace
            }
        }
        
        //print the probability for each sum 
        cout << right << setw(11) << probability;
        
        //print blank line to print the next sum's information on the 
        //next line
        cout << endl;
        
    }
}//end printHistogram


int main() {//main function declaration
    
    srand(time(0));//seed random number generator
    
    //tells user that the dice simulation is occurring
    cout << "Simulating..." << endl;
    
    //initializing array to hold frequency of occurrence for each sum
    int frequencies[SIZE] = {0};
    
    //calling the simulate function
    simulate(frequencies);
    
    //calling the printHistogram function
    printHistogram(frequencies);
    
    //tell user that results have been printed and simulation is complete
    cout << "...done." << endl;
    
    return 0;//if everything works, return 0;
    
}//end main 
