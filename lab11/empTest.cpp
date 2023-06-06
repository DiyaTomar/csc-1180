#include "HourlyEmployee.h"
#include "DateType.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    HourlyEmployee joe("Joe","1234",DateType(4,29,1977),
                       DateType(3,20,2000),"Accounting","jps5a",
                       40, 17.92);

    cout << joe << endl;

    cout << joe.getName() << "'s weekly pay: " << joe.getWeeklyPay() << endl;
    return 0;
}//end main
