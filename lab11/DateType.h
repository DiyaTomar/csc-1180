#pragma once
#include <string>
#include <iostream>
#include <cstdlib>

class DateType
{
    private:
        int month;
        int day;
        int year;
        std::string id;

    public:
        DateType& operator=(const DateType&);
        bool isLeapYear() const;
        
        DateType(int=1,int=1,int=1900);
        DateType(const DateType&);//copy constructor
        ~DateType();//deconstructor
        
        int getMonth() const;
        int getDay() const;
        int getYear() const;
        
        void setMonth(int);
        void setDay(int);
        void setYear(int);
        
        std::string formatted() const;
};//end class definition
DateType& DateType::operator=(const DateType& other)
{
    if ( this == &other ) return *this;
  //  std::cout << "Assignment operator called. ";
  //  std::cout << other.id << " copied to " << id << std::endl;
    id = other.id;
    month = other.month;
    day = other.day;
    year = other.year;
    return *this;
}

DateType::~DateType()
{
  //  std::cout << "Destroying the " << id << " DateType object." << std::endl;
}

DateType::DateType(const DateType& other)
{
    if ( this == &other) return;//no need to copy to self
    id = std::to_string(rand());
  //  std::cout << "Copy constructor of " << other.id << " to " << id << std::endl;
    setMonth(other.month);
    setYear(other.year);
    setDay(other.day);
}
    

DateType::DateType(int m, int d, int y)
{
    id = std::to_string(rand());
  //  std::cout << "Creating the " << id << " DateType object." << std::endl;
    setYear(y);
    setMonth(m);
    setDay(d);
}//end constructor

int DateType::getMonth() const
{
    return month;
}

int DateType::getYear() const
{
    return year;
}

int DateType::getDay() const
{
    return day;
}
void DateType::setYear(int y)
{
    if ( y < 1 ) {
        std::cerr << "Invalid year. Using default 1900." << std::endl;
        year = 1900;
    } else
        year = y;
}
void DateType::setMonth(int m)
{
    if ( m < 1 or m > 12 ) {
        std::cerr << "Invalid month. Using default 1." << std::endl;
        month = 1;
    } else
        month = m;
}
bool DateType::isLeapYear() const
{
    if ( year % 4 == 0 and year % 100 != 0 )
        return true;
    else if ( year % 400 == 0 )
        return true;
    else
        return false;
}
void DateType::setDay(int d)
{
    bool invalid = false;
    if ( d < 1 ) {
        invalid = true;
    } else {
            switch ( month ) {
                case 1: case 3: case 5: case 7: case 8: case 10: 
                case 12: if ( d > 31 ) invalid = true; 
                         break;
                
                case 4: case 6: case 9: 
                case 11: if ( d > 30 ) invalid = true; 
                         break;
                
                default: //catches february
                    if ( isLeapYear() ) {
                        if ( d > 29 ) invalid = true;
                    } else
                        if ( d > 28 ) invalid = true;
            };//end switch
    }//end if/else
    if ( invalid ) {
        std::cerr << "Invalid day. Using default 1." << std::endl;
        day = 1;
    } else
        day = d;
}//end set Day
std::string DateType::formatted() const
{
    const std::string MONTHS[] = {"", "January","February","March","April","May",
                               "June","July","August","September","October",
                               "November","December"};
    return MONTHS[month] + " " + std::to_string(day) + ", " + std::to_string(year);
}
