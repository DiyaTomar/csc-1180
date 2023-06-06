//2.21.2023
//Diya Tomar
//The program processes the payroll for a small family owned business.
//The program reads information from a file called 'weeklyHours.txt'
//that has information on everyone who gets paid weekly
//including their name, ID, hours worked, and hourly rate.
//The program processes this file and create a summary listing that 
//shows the relevant information and a total, all of which is both 
//printed to the screen and written to an output file 
//called 'weeklyPay.txt'.
//If an employee works overtime (more than 40 hours), the extra
//hours are factored into their total pay calculation and an asterisk
//will appear beside their total pay to indicate overtime. 

#include <iostream>//for outputting the results to the screen
#include <string>//for names and ID numbers
#include <fstream> //for file input and output
#include <iomanip> //for output manipulation

using namespace std;//allows the usage of keywords such as cout and cin

const int OVERTIME = 40; //constant for max # of regular hours

//the getWeeklyPay function calculates the weekly pay for each employee
double getWeeklyPay(double hours, double rate) {//getWeeklyPay function declaration
    if (hours <= OVERTIME)//if the employee does not work overtime
        //calculate the pay by multiplying the hours by the hourly rate
        return hours * rate;
    else //if employee works overtime
        //include the additional pay for overtime 
        return (OVERTIME * rate) + ((hours - OVERTIME) * rate * 1.5);
}//end getWeeklyPay

//the printHeader prints the header of the weekly pay analysis
void printHeader(ostream &output) {//printHeader function declaration
    
    //set precision for hours, rate, and pay values 
    output << setprecision(2) << fixed; 
    
    output << "Weekly Pay Analysis" << endl;
    output << "---------------------------------------------------------------------------------" << endl;
    output << "Name           ID          Hours Worked            Hourly Rate         Weekly Pay" << endl; 
}//end printHeader

//the printInfo function outputs the information of each employee's pay analysis to the screen and output file
void printInfo(ostream &output, string name, string ID, double hours, double rate, double pay) {//printInfo function declaration
    //outputs the employee's information to the file
    output << left << setw(10) << name
           << right << setw(7) << ID
           << setw(22) << hours
           << setw(23) << rate 
           << setw(19) << pay;
    
    //if the employee works overtime
    if (hours > OVERTIME)
        //adds an asterisk beside the weekly pay to indicate overtime
        output << "*" << endl;
    else //if the employee works regular hours
        //output blank line
        output << endl;
}//end printInfo

//the printOutlay function outputs the total outlay to the screen and output file
void printOutlay(ostream &output, double totalOutlay) {//printOutlay function declaration
    output << "---------------------------------------------------------------------------------" << endl;
    output << right << setw(50) << "Total Outlay" << setw(31) << totalOutlay;
}//end printOutlay


int main() {//main function declaration 
    //open file for input
    ifstream input;
    //open the 'weeklyHours.txt' file
    input.open("weeklyHours.txt");
    if (!input) {//if input file didn't open
        //error message
		cerr << "Error opening input file. Exiting program." << endl;
		return 1; //returns 1 as error code
	}

    //open file for output
    ofstream output;
    //open the 'weeklyPay.txt' file
    output.open("weeklyPay.txt");
    if (!output) {//if output file didn't open
        //error message
		cerr << "Error opening output file. Exiting program." << endl; 
		return 2; //returns 2 as error code
	}
    
    
    //printing the header to the output file
    printHeader(output);
    //printing the header to the screen
    printHeader(cout);
    
    
    //declaring variables for the employee name, ID, hours worked, and hourly rate
    string name, ID;
    double hours, rate;
    //initializing variable for the total outlay
    double totalOutlay = 0.0;
    
    //reading in the information about the first employee
    input >> name >> ID >> hours >> rate;
        
    while (input) {//while there is still information to be read from input file
        double pay = getWeeklyPay(hours, rate);//calculate the weekly pay (calling the getWeeklyPay function)
        //adding the weekly pay of an employee to the total outlay
        totalOutlay += pay;
        //print the information to the screen
        printInfo(cout, name, ID, hours, rate, pay);
        //print the information to the output file
        printInfo(output, name, ID, hours, rate, pay);
        //read the next employee's information
        input >> name >> ID >> hours >> rate;
    }
    
    //printing the total outlay to the output file
    printOutlay(output, totalOutlay);
    //printing the total outlay to the screen
    printOutlay(cout, totalOutlay);
    

    //closing the file streams when finished
    input.close();
    output.close();
    
    return 0; //if everything works fine, return 0
}//end main


