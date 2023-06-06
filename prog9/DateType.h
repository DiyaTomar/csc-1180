//3.27.2023
//Diya Tomar
//This program contains a class that models a date, consisting of three 
//integer values, representing the month, day, and year.
//The class has get and set methods, as well as a method called 
//“formatted” that returns a string representation of the date in 
//long format.

#include <iostream>//for outputting the results to the screen
#include <string>//allows for usage of string data type

//--------------------------CLASS DEFINITION----------------------------

//the class DateType models a Date using month, day, and year
class DateType {//DateType class definition
    
    private://access specifier, contains private class members
        int month;//attribute of type int for month
        int day;//attribute of type int for day
        int year;//attribute of type int for year
        
        int numDays() const;//numDays method
        bool leapYear() const;//leapYear method
        
    public://access specifier, contains public class members
        
        //constructor with default parameters (fills in       
        //values not provided with 1)
        DateType(int = 1, int = 1, int = 1);
        
        //set methods (mutators)
        void setMonth(int);//setMonth method
        void setDay(int);//setDay method
        void setYear(int);//setYear method
        
        //get methods (accessors)
        //const because they should not modify object
        int getMonth() const;//getMonth method
        int getDay() const;//getDay method
        int getYear() const;//getYear method
        
        //formatted method
        //const because it should not modify object
        std::string formatted() const;
        
};//end class definition


//-----------------------------CONSTRUCTOR------------------------------

//the DateType constructor initializes objects and sets the object's       
//month, day, and year
//m means month, d means day, y means year
DateType::DateType(int m, int d, int y) {//DateType constructor implementation
    //calling the set methods to set the month, day and year values
    setYear(y);
    setMonth(m);
    setDay(d);
}//end DateType constructor

//---------------------------IMPLEMENTATION-----------------------------


//-----------------------------get methods------------------------------

//the getMonth method returns the month value 
int DateType::getMonth() const {
    return month;
}//end getMonth

//the getDay method returns the day value
int DateType::getDay() const {
    return day;
}//end getDay

//the getYear method returns the year value
int DateType::getYear() const {
    return year;
}//end getYear


//---------------------------set methods--------------------------------

//the setMonth method checks whether the month value provided by the 
//actual parameter is valid and sets the month value accordingly.
void DateType::setMonth(int m) {
    if (m <= 12 and m >= 1) {//if parameter value is less than or equal to 12 and greater than or equal to 1
        month = m;//set month's value to m
    }
    else {//else if value does not fit the requirement
        //print error message
        std::cerr << "Invalid month value provided (must be between 1-12). Setting to 1." << std::endl;
        month = 1;//set month's value to default value of 1
    }
}//end setMonth

//the setDay method checks whether the day value provided by the 
//actual parameter is valid and sets the day value accordingly.
void DateType::setDay(int d) {
    //if parameter value is greater than or equal to 1 
    //and less than or equal to the number of days in the month
    if (d >= 1 and d <= numDays()) {
        day = d;//set day's value to d
    }
    else {//else if value does not fit the requirement
        //print error message
        std::cerr << "Invalid day value provided (must be between 1-31, depending on month). Setting to 1." << std::endl;
        day = 1; //set day's value to default value of 1
    }
}//end setDay

//the setYear method checks whether the year value provided by the 
//actual parameter is valid and sets the year value accordingly.
void DateType::setYear(int y) {
    if (y > 0) {//if parameter is greater than 0
        year = y;//set year's value to y 
    }
    else {//else if value does not fit the requirement
        //print error message
        std::cerr << "Invalid year value provided (must be greater than 0). Setting to 1." << std::endl;
        year = 1;//set year's value to default value of 1
    }
}//end setYear


//--------------------------other methods-------------------------------

//the numDays function returns the number of days based on the month
int DateType::numDays() const {
    
    //a switch expression that returns the number of days depending on the month
    switch(month) {
        case 2: //if month is February
            if (leapYear()) {//if it is a leap year (calls leapYear method)
                return 29;//there are 29 days
                break;
            }
            else {//else if not a leap year
                return 28;//there are 28 days
                break;
            }
        //if the month is January, March, May, July, August, October, or December
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: 
            return 31;//there are 31 days
            break;
        default://if the month is April, June, September, or November
            return 30;//there are 30 days
            break;
        
    }
}//end numDays

//the leapYear method checks whether or not the year is a leap year
bool DateType::leapYear() const {
    //if the year is divisible by 4 and not divisible by 100 OR if year is divisible by 400
    //(calculations based on Gregorian calendar) 
    if ((year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)) {
        return true;//it is a leap year
    }
    else {//else if year value does not satisfy the requirement
        return false;//it is not a leap year
    }

}//end leapYear

//the formatted method uses the month, day, and year value to print the date
std::string DateType::formatted() const {
    
    //creating an array to store the name of each month
    std::string monthNames[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    //storing the month's name in fMonth (ex. 2nd month --> 2 - 1 = index 1 --> February)
    std::string fMonth = monthNames[month - 1];
    std::string fDay = std::to_string(day);//storing the day value in fDay as a string
    std::string fYear = std::to_string(year);//storing the year value in fYear as a string
    std::string fDate = "";//initializing string for the date
    
    if (fYear.length() == 1) {//if the year value is 1 digit
        fYear = "000" + fYear;//fill in empty spaces with 3 leading 0's
    }
    else if (fYear.length() == 2) {//else if the year value is 2 digits
        fYear = "00" + fYear;//fill in empty spaces with 2 leading 0's
    }
    else if (fYear.length() == 3) {//else if the year value is 3 digits
        fYear = "0" + fYear;//fill in empty spaces with 1 leading 0
    }
    
    //putting together the month, day, and value into a formatted date 
    fDate = fMonth + " " + fDay + ", " + fYear; 
    
    //returning the date
    return fDate;

}//end formatted



