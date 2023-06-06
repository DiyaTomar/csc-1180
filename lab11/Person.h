//Person class
#pragma once
#include "DateType.h"
#include <iostream>
#include <string>

class Person 
{
    private:
        //static variable
        static int count;
        std::string name; //this is composition
        std::string SSN; //this is composition
        DateType DOB; //this is composition
    
    public:
        //operator overloading
        friend std::ostream& operator<<(std::ostream&, const Person&);
        ~Person();//the only destructor we have!
        Person(std::string, std::string, DateType);
        Person(std::string, std::string);
        Person(std::string);
        Person();//a constructor, no return type specified
        std::string getName() const;
        std::string getSSN() const;
        void setName(std::string);
        void setSSN(std::string);
        static int getCount();
        void setDOB(DateType);
        
};//end person class definition
void Person::setDOB(DateType d)
{
    DOB = d;
}
int Person::count = 0;//must initialize static data members!

int Person::getCount()
{
    return count;
}

//steam insertion operator
std::ostream& operator<<(std::ostream& out, const Person& p)
{
    out << p.name << " " << p.SSN << " " << p.DOB.formatted();
    return out;
}

Person::~Person() //destructor
{
  //  std::cout << "Destroying the " << count << " object." << std::endl;
    count--;
}//end destructor

Person::Person(std::string n, std::string ssn) 
{
    count++;
 //   std::cout << "Creating person object with two parameters." << std::endl;
    setName(n);
    setSSN(ssn);
}//end constructor

Person::Person(std::string n, std::string ssn, DateType d) 
{
    count++;
  //  std::cout << "Creating person object with three parameters." << std::endl;
    setName(n);
    setSSN(ssn);
    setDOB(d);
}//end constructor
Person::Person(std::string n) 
{
    count++;
   // std::cout << "Creating person object with one parameter." << std::endl;
    setName(n);
    SSN = "xxxxxxxxx";
}//end constructor

Person::Person() 
{
    count++;
  //  std::cout << "Creating person object. Default Constructor." << count << std::endl;
    setName("not set");
    SSN = "xxxxxxxxx";
}//end constructor

//implementation of methods
std::string Person::getName() const
{
    return name;
}//end getName

std::string Person::getSSN() const
{
    return SSN;
}//end getSSN method

void Person::setName(std::string n)
{
    //verification code goes here
    name = n;
}//end setName

void Person::setSSN(std::string ssn)
{
    //verification code goes here
    SSN = ssn;
}
