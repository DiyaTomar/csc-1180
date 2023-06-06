//2.28.2023
//Diya Tomar
//This program generates a row of 150 lockers, with 0 representing
//closed lockers and 1 representing open lockers. The program starts
//with opening every 2nd locker. The process is repeated with every
//3rd locker (opening closed lockers and closing open lockers), and so on.
//At the end, the program prints out which lockers are closed.

#include <iostream>//for outputting the results to the screen

using namespace std;//allows the usage of keywords such as cout and cin

//constant representing # of lockers (size of array)
const int numLockers = 150; 

//the lockerStatus function goes through the lockers being checked
//and changes their status from open to closed and vice versa 
void lockerStatus(int lockers[]) {
    //variable that checks every 2nd locker (this value increases as
    //Jill continues going through the process)
    int increment = 2;
    
    //this for loop starts at the 2nd locker and goes up a locker
    //once each round of opening/closing lockers is complete
    for (int index = 1; index < numLockers; index++) {
        //this for loop checks every locker being checked in that round
        //(every 2nd locker, every 3rd locker, etc.)
        for (int currentLocker = index; currentLocker < numLockers; currentLocker += increment) {
            //if the locker being checked is closed
            if (lockers[currentLocker] == 0) {
                lockers[currentLocker] = 1;//open the locker
            }
            //if the locker being checked is open
            else {
                lockers[currentLocker] = 0;//close the locker
            }
        }
    //increase increment value by 1 (this switches from checking every
    //2nd locker to every 3rd locker, every 3rd locker to every 4th
    //locker, etc.)
    increment++;
    }
}

int main() {//main function declaration
    
    //creating an array with 150 closed lockers (represented by 0's)
    int lockers[numLockers] = {0}; 
    
    //calls the lockerStatus function
    lockerStatus(lockers);
    
    //prints header for closed lockers
    cout << "The closed lockers are: " << endl;
    
    //this for loop goes through every locker in the array
    for (int index = 0; index < numLockers; index++) {
        if (lockers[index] == 0) {//if a locker is closed
            //print the index of the locker (adding 1 to print
            //locker position and not index value)
            cout << index + 1 << " ";
        }
    }
    
    return 0;//if everything works fine, return 0

}//end main
