//2.14.2023
//Diya Tomar
//This program performs a loan amortization for a given loan amount.
//The program asks the user for the loan amount, 
//the yearly interest rate (as a percent), and the monthly payment.
//It will print an amortization schedule for the loan at those terms by
//printing the initial loan amount, the interest rate, and a 
//monthly schedule showing the month start balance, 
//the interest for that month, the monthly payment, 
//and the remaining balance.
//It will also print the total amount paid, the total interest paid
//on the loan, and determine the time required to pay off the loan 
//in years and months.

#include <iostream>//for outputting the results to the screen
#include <iomanip>//for output manipulation

using namespace std;//allows the usage of keywords such as cout and cin

int main() {//main function declaration
    
    //set up output precision for money amounts
    cout << setprecision(2) << fixed; 
    
    //declaring variables for the loan amount, yearly interest rate,
    //and the monthly payment (used double to account for decimal values)
    double loanAmount, yearlyInterestRate, monthlyPayment;
    
    //declaring variables for:
    double monthlyInterestRate;//the monthly interest rate
    double monthlyInterest;//the monthly interest
    double remainingBalance;//remaining balance
    
    //initializing variables for:
    double totalPaid = 0.0;//the total amount paid
    double totalInterest = 0.0;//the total interest paid (cost of loan)
    
    //initializing variable for # of months and years to pay off loan
    int months = 1;
    int years = 0;
    
    
    //asking the user to input the loan amount
    do {
        cout << "Enter the loan amount: ";
        cin >> loanAmount;
        //if the loan amount is less than 0, tell the user to enter
        //a new value greater than 0
        if (loanAmount < 0) {
            cerr << "Invalid output. Please enter a loan > 0." << endl;
        }
    //while the loan amount is less than 0
    } while (loanAmount < 0);
    
    
    //asking the user to input the yearly interest rate
    do {
        cout << "Enter the yearly interest rate (%): ";
        cin >> yearlyInterestRate;
        //if the yearly interest rate is less than 0, tell the user to
        //enter a new value greater or equal to 0
        if (yearlyInterestRate < 0) {
            cerr << "Invalid output. Please enter a yearly interest rate >= 0." << endl;
        }
    //while the yearly interest rate is less than 0
    } while (yearlyInterestRate < 0);
       
        
    //asking the user to enter the monthly payment
    cout << "Enter the monthly payment: ";
    cin >> monthlyPayment;
    //checking to see if monthly payment is enough to pay off the loan
    //calculating the monthly interest rate
    monthlyInterestRate = yearlyInterestRate / 12 / 100;
    //calculating the value for the monthly interest on the loan amount
    monthlyInterest = loanAmount * monthlyInterestRate;
    //if the monthlyInterest is greater or equal to the monthly payment
    if (monthlyInterest >= monthlyPayment) {
        //print error message indicating monthly payment is not
        //sufficient to pay off loan and terminate program.
        cerr << "The monthly payment is not sufficient to pay off loan. Terminating." 
             << endl;
        return 1;//returning error code
    }
    
    
    //Printing out the header for the amortization schedule, which
    //includes the initial loan amount, yearly interest rate, 
    //and monthly payment.
    cout << endl;//blank line
    cout << "Amortization Schedule" << endl;
    cout << "Initial loan amount: $" << loanAmount << endl;
    cout << "Yearly Interest Rate: " << yearlyInterestRate << left
         << setw(5) << "%" << "Monthly Payment: $" << monthlyPayment << endl; 
    
    cout << endl;//blank line
    //prints out header for the month, start balance, interest, amount
    //paid, and remaining balance
    cout << "Month      Start Balance        Interest           Paid        Remaining" << endl;
    

    remainingBalance = loanAmount;//copying loan amount
    
    //while the remaining balance is greater than the monthly payment,
    //meaning that the loan hasn't been paid off
    while (remainingBalance > monthlyPayment) {
        //print the month #
        cout << left << setw(5) << months;
        //print the remaining balance
        cout << right << setw(19) << remainingBalance;
        //print the monthly interest
        cout << setw(16) << monthlyInterest;
        //print the monthly payment
        cout << setw(15) << monthlyPayment;
        //recalculating the remaining balance by adding the monthly interest
        //and subtracting the monthly payment
        remainingBalance = remainingBalance + monthlyInterest - monthlyPayment;
        //print the remaining balance
        cout << setw(17) << remainingBalance;
        //add the monthly payment to the total amount paid
        totalPaid += monthlyPayment;
        //adding the monthly interest paid to the total interest paid
        totalInterest += monthlyInterest;
        //recalculating the monthly interest by multiplying the 
        //remaining balance by the monthly interest rate
        monthlyInterest = remainingBalance * monthlyInterestRate;
        //incrementing the # of months by 1
        months++;
        //printing blank line to print next month's data on a new line
        cout << endl;
    }
    
    //add the final monthly payment to the total amount paid
    totalPaid += (remainingBalance + monthlyInterest);
    //adding the final monthly interest paid to the total interest paid
    totalInterest += monthlyInterest;
    
    //printing out the final month's information
    cout << left << setw(5) << months << right
         << setw(19) << remainingBalance
         << setw(16) << monthlyInterest
         << setw(15) << monthlyInterest + remainingBalance
         << setw(17) << 0.00 << endl; 
    
    //calculating the # of years by dividing # of months by 12
    years = months / 12;
    //the remainder of the # of months divided by 12 gives the additional
    //months spent to pay off the loan
    months = months % 12;
    
    cout << endl;//blank line
    
    //printing out the total paid, cost of loan, and the time required
    //to pay off the loan
    cout << "Total Paid:    $" << right << setw(15) << totalPaid << endl;
    cout << "Cost of loan:  $" << right << setw(15) << totalInterest << endl;
    cout << "Time to pay off: " << right << setw(5)
         << years << " years and " << months << " months";
    
    
    return 0;//if everything works fine, return 0

}//end main
