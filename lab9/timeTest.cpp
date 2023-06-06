#include "TimeType.h"

#include <iostream>
using namespace std;

int main() {

    TimeType aTime;//uses default constructor (no arguments)
    TimeType bTime(13);//uses one argument (the hour)
    TimeType cTime(29,72);//uses two arguments (note the invalid values)
                          //should default to valid values with error messages
    TimeType dTime(5,5,5);//uses three arguments

    //now printing
    cout << "Illustrating the TimeType class" << endl;
    cout << "a Time: " << aTime.military() << endl;
    cout << "c Time: " << cTime.standard() << endl;
    cout << "b Time: " << bTime.military() << endl;
    cout << "d Time: " << dTime.standard() << endl;

    return 0;

}//end main
