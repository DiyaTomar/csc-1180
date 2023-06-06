//2.17.2023
//Diya Tomar
//This program determines all pairs of integers from 1 to 1000 where 
//the sum of the numbers is equal to the sum of the digits in the
//product.

#include <iostream>//for outputting the results to the screen
#include <iomanip>//for output manipulation

using namespace std;//allows the usage of keywords such as cout and cin

//function prototype for sumDigits
int sumDigits(int);

int main() {//main function declaration
    
    //initializing variables for the sum and product of the two integers
    int sum = 0;
    int product = 0;
    
    //printing the headers for each column
    cout << "Number 1 " << "Number 2 " << "Sum  " << "Product " 
         << "Sum of digits in product" << endl; 
    
    //this for loop checks all cases where integer 1 is between 1-1000
    for (int integer1 = 1; integer1 <= 1000; integer1++) {
        //this for loop checks all cases where integer 2 is between 1-1000
        //setting integer2 = integer1 to remove repeating integer pairs
        for (int integer2 = integer1; integer2 <= 1000; integer2++) {
            sum = integer1 + integer2;//calculates sum of the integers
            product = integer1 * integer2;//calculates product of the integers
            //if the sum of the two integers is equal to the
            //sum of the digits in the product (calling the
            //sumDigits function)
            if (sum == sumDigits(product)) {
                //print out the two integers, sum, product,
                //and sum of the digits in the product
                cout << left << setw(9) << integer1 
                     << setw(9) << integer2  
                     << setw(5) << sum << setw(8) << product 
                     << setw(24) << sumDigits(sum) << endl;
            }
            
        }
    }
    
    
    return 0;//if everything works fine, return 0

}//end main

//the sumDigits function calculates the sum of the digits in the product
int sumDigits(int product) {//sumDigits function declaration
    //initializing variable for the sum of digits in the product
    int productSum = 0;
    //while the product is greater than 0
    while (product > 0) {
        //adding the remainder of the product divided by 10 adds the
        //last digit in the product to the product sum
        productSum += product % 10;
        //removes the last digit of the product
        product /= 10;
    }
    //returns the value of the sum of the digits in the product
    return productSum;
}//end sumDigits
