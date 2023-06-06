//2.5.2023
//Diya Tomar
//The program reads in and identifies the location of an x-y coordinate 
//in the Cartesian plane. 
//The user will input the x and y-values of a coordinate. 
//Based on the location of the coordinate, the program will
//indicate whether the point is the origin, located on the x-axis,
//located on the y-axis, or appears in a particular quadrant.

#include <iostream> //for input and output

using namespace std; //allows the usage of keywords such as cout and cin

int main() {//main function declaration
	
	double x; //declaring a variable for the x-value of the coordinate
	double y; //declaring a variable for the y-value of the coordinate
	
	//asking the user to input an x-value and storing the value
	cout << "Enter a value for the x-value of the coordinate: ";
	cin >> x;
	
	//asking the user to input a y-value and storing the value
	cout << "Enter a value for the y-value of the coordinate: ";
	cin >> y;
	
	//format for printing out coordinate to screen
	cout << "(" << x << "," << y  << ") ";
	
	if (x == 0 && y == 0) {//if the x and y-values of the coordinate are 0
		cout << "is the origin";//then print that the coordinate is the origin
	}
	else if (y == 0) {//else if the y-value is 0
		cout << "is on the x-axis";//then print that the coordinate is on the x-axis
	}
	else if (x == 0) {//else if the x-value is 0
		cout << "is on the y-axis";//then print that the coordinate is on the y-axis
	}
	else if (y > 0) {//else if the y-value is greater than 0
		
		if (x > 0) {//if the x-value is greater than 0
			cout << "is in quadrant I";//then print that the coordinate is in quadrant I
		}
		else {//else if the x-value is less than 0
			cout << "is in quadrant II";//then print that the coordinate is in quadrant II
		}
	}
	else {//else if the y-value is less than 0
		if (x > 0) {//if the x-value is greater than 0
			cout << "is in quadrant IV";//then print that the coordinate is in quadrant IV
		}
		else {//else if the x-value is less than 0
			cout << "is in quadrant III";//then print that the coordinate is in quadrant III
		}
	}
	
	return 0; //if everything works fine, return 0
	
}//end main

