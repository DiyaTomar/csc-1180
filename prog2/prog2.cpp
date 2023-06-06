//1.29.2023
//Diya Tomar
//This program calculates individual income tax. 
//The user will input their yearly income and the program
//will use the corresponding tax rate to calculate and print 
//the income tax of the user. 


#include <iostream>//for input and output
#include <iomanip>//for output manipulation

using namespace std;//allows the usage of keywords such as cout and cin

int main() {//main function declaration
	
	//declaring and initializing the different income tax rates 
	//the rates are declared as constant
	const int rate1 = 10;
	const int rate2 = 12;
	const int rate3 = 22;
	const int rate4 = 24;
	const int rate5 = 32;
	const int rate6 = 35;
	const int rate7 = 37;
	
	//declaring variables for the user's yearly income and corresponding tax rate
	double yearlyIncome; 
	double taxRate; 
	
	//prints "Enter your yearly income: " to the screen
	cout << "Enter your yearly income: ";
	//asks the user to input their yearly income
	cin >> yearlyIncome;
	
	
	//determining which tax rate corresponds with the user's yearly income
	
	//if the user's yearly income is greater than $0 and less than or equal to $9525
	if (yearlyIncome > 0 && yearlyIncome <= 9525) {
		taxRate = rate1;//then the tax rate is 10%
	}
	//else if the user's yearly income is greater than $9525 and less than or equal to $38700
	else if (yearlyIncome > 9525 && yearlyIncome <= 38700) {
		taxRate = rate2;//then the tax rate is 12%
	}
	//else if the user's yearly income is greater than $38700 and less than or equal to $82500
	else if (yearlyIncome > 38700 && yearlyIncome <= 82500) {
		taxRate = rate3;//then the tax rate is 22%
	}
	//else if the user's yearly income is greater than $82500 and less than or equal to $157500
	else if (yearlyIncome > 82500 && yearlyIncome <= 157500) {
		taxRate = rate4;//then the tax rate is 24%
	}
	//else if the user's yearly income is greater than $157500 and less than or equal to $200000
	else if (yearlyIncome > 157500 && yearlyIncome <= 200000) {
		taxRate = rate5;//then the tax rate is 32%
	}
	//else if the user's yearly income is greater than $200000 and less than or equal to $500000
	else if (yearlyIncome > 200000 && yearlyIncome <= 500000) {
		taxRate = rate6;//then the tax rate is 35%
	}
	//else if the user's yearly income is greater than $500000
	else {
		taxRate = rate7;//then the tax rate is 37%
	}
	
	
	//calculating the income tax by multiplying the tax rate (percent value * 0.01) by the yearly income
	double incomeTax = taxRate * 0.01 * yearlyIncome;
	
	//printing out the yearly income (left column is left adjusted, and yearly income is right adjusted)
	//setw for yearly income, tax rate, and income tax is set to 12 
	//This will allow the values to be aligned together for an income of up to $999999999.99
	cout << left << setfill('.') << setw(20) << "Yearly Income:" << '$';
	cout << right << setfill(' ') << setw(12) << fixed << setprecision(2) << yearlyIncome << endl;
	
	//printing out the tax rate (left column is left adjusted, and tax rate is right adjusted)
	cout << left << setfill('.') << setw(20) << "Tax rate:" << '%';
	cout << right << setfill(' ') << setw(12) << setprecision(0) << taxRate << endl;
	
	//printing out the income tax (left column is left adjusted, and income tax is right adjusted)
	cout << left << setfill('.') << setw(20) << "Income tax:" << '$';
	cout << right << setfill(' ') << setw(12) << setprecision(2) << incomeTax << endl;
	
	return 0; //if everything works fine, return 0

}//end main
