//1.24.2023
//Diya Tomar
//Program that calculates the area and volume of a rectangular box

#include <iostream>//for input and output
#include <iomanip>//for output manipulation

using namespace std;//allows the usage of keywords such as cout and cin

int main() {//main function declaration
	
	//declaring the length, width, and height variables
	double length;
	double width;
	double height;
	
	
	cout << "Enter the length: ";//prints "Enter the length" to the screen
	cin >> length;//asks user to input a value for the length
	cout << "Enter the width: ";//prints "Enter the width" to the screen
	cin >> width;//asks user to input a value for the width
	cout << "Enter the height: ";//prints "Enter the height" to the screen
	cin >> height;//asks user to input a value for the height
	
	
	//variables for volume and surface area calculations
	double volume = length*width*height;
	double surfaceArea = 2*length*width + 2*length*height + 2*width*height;
	
	
	//printing out the volume of the rectangular box to 4 decimal points
	cout << "The volume of the rectangular box is: " 
		 << fixed << setprecision(4) << volume << endl;
		 
	//printing out the surface area of the rectangular box to 4 decimal points
	cout << "The surface area of the rectangular box is: "
	     << setprecision(4) << surfaceArea << endl;
	     
	return 0; //if everything works fine, return 0

}//end main
