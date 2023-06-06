//testing file
#include "DateType.h"

#include <iostream>
using namespace std;

int main() {
    
    DateType newDate;//empty so use default values

    DateType myBDay(1,1,1950);//a valid date

    DateType aDate(15,15,-200);//note invalid values

    cout << newDate.formatted() << endl;
    cout << myBDay.formatted() << endl;
    cout << aDate.formatted() << endl;

    return 0;
}//end main


