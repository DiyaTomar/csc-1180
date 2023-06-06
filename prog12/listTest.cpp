//4.25.2023
//Diya Tomar
//This program reads in a set of data from a file called "data.txt", 
//which contains one number per line. This data is put into a linked list.
//This program calls the print function. After printing, an item is deleted
//from the list and the list is printed again. Finally, the list is
//cleared and checked to make sure it is empty.

#include "LinkedList.h" //including contents of "LinkedList.h" file                         
#include <iostream> //for outputting the results to the screen
#include <fstream> //for file input

using namespace std;//allows the usage of keywords such as cout and cin

int main() {//main function declaration
    
    //create a linked list of type double
    LinkedList<double> mylist;
    
    //input file stream
    ifstream input;
    
    input.open("data.txt");//opening "data.txt" file
    
    if (!input) {//if error opening file
        //print error message
        cerr << "Error opening file. Terminating." << endl;
        return 1;//error code
    }
    
    double value;//declaring variable of type double to represent a value from the file
    
    input >> value;//reading in 1st value from file
    
    while (input) {//while there are still values in the file
        mylist.insert(value);//add the value to the list
        input >> value;//read in the next value
    }
    
    //printing the list
    cout << "List contains: " << endl;
    mylist.print();
    
    double removeVal = 3.14;//double value to remove
    
    //removing specified value from list
    cout << "Removing " << removeVal << " from the list." << endl;
    mylist.remove(removeVal);
    
    //printing the list
    cout << "List contains: " << endl;
    mylist.print();

    //clearing the linked list
    cout << "Clearing the list." << endl;
    mylist.clear();
    
    //printing the list
    cout << "List contains: " << endl;
    mylist.print();
    
    //checking to see if linked list is empty
    if (mylist.isEmpty()) {//if list is empty
        //print that it is empty
        cout << "List is empty." << endl;
    }
    else {//if not empty
        //print that the clear method called previously didn't work
        cout << "Clear method did not work." << endl;
    }

    return 0;//if everything works fine, return 0
    
}//end main

