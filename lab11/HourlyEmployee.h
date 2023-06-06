//4.18.2023
//Diya Tomar
//In this file, there is a class that extends the Employee class to an
//HourlyEmployee. HourlyEmployees are Employees with a number of hours 
//worked and an hourly pay rate.

#pragma once //ensures that this file is only included one time  
#include <iostream> //for outputting the results to the screen
#include <string> //allows for usage of string data type
#include "Employee.h" //file including inherited class

const int OVERTIME = 40; //constant for max # of regular hours

//the HourlyEmployee class inherits the Employee class and models an
//employee that has a # of hours worked and an hourly pay rate
class HourlyEmployee : public Employee {
    
    private://access specifier, contains private class members
        double hWorked;//attribute of type double for hours worked
        double hRate;//attribute of type double for hourly rate
        
    public://access specifier, contains public class members
        
        HourlyEmployee();//default constructor
        
        //constructor with parameters
        HourlyEmployee(std::string, std::string, DateType, DateType, std::string, std::string, double, double);
        
        //get and set methods
        double getHWorked();
        double getHRate();
        void setHWorked(double);
        void setHRate(double);
        
        //overloading the getWeeklyPay method in the Employee class
        double getWeeklyPay() const;
        
        //overloaded stream insertion operator
        friend std::ostream& operator<<(std::ostream& out, const HourlyEmployee&);
    
};//end class definition

//----------------------------constructors------------------------------

//the default constructor sets the hours worked and hourly rate to 
//default values
HourlyEmployee::HourlyEmployee() : Employee() {
    //setting hours worked and hourly rate to 0
    setHWorked(0);
    setHRate(0);
}//end constructor

//this constructor takes in parameters and sets the hours worked and
//hourly rate to the values provided
HourlyEmployee::HourlyEmployee(std::string name, std::string ssn, DateType dob, DateType hireD,
                                std::string dept, std::string ID, double hw, double hr) 
    : Employee(name, ssn, dob, hireD, dept, ID) {
    
    //setting the hours worked and hourly rate
    setHWorked(hw);
    setHRate(hr);
}//end constructor


//---------------------------get/set methods----------------------------

//the setHWorked method sets the hours worked value
//h means hours worked
void HourlyEmployee::setHWorked(double h) {
    
    if (h < 0) {//if hours worked is less than 0
        //print error message
        std::cerr << "Invalid number of hours inputted. Setting hours worked to 0." << std::endl;
        //set hours worked to 0
        hWorked = 0;
    }
    else {
        //set hours worked to h
        hWorked = h;
    }
}//end setHWorked

//the setHRate method sets the hourly rate value
//r means hourly rate
void HourlyEmployee::setHRate(double r) {
    
    if (r < 0) {//if hourly rate is less than 0
        //print error message
        std::cerr << "Invalid hourly rate inputted. Setting hourly rate to 0." << std::endl;
        //set hourly rate to 0
        hRate = 0;
    }
    else {
        //set hourly rate to r
        hRate = r;
    }
}//end setHRate

//the getHWorked method returns the hours worked value
double HourlyEmployee::getHWorked() {
    return hWorked;
}//end getHWorked

//the getHWorked method returns the hours worked value
double HourlyEmployee::getHRate() {
    return hRate;
}//end getHRate


//-------------------------overloaded operators-------------------------

//the operation overloading function for << outputs the HourlyEmployee's 
//information
//out means output and hEmp means hourly employee
std::ostream& operator<<(std::ostream& out, const HourlyEmployee &hEmp) {
    
    //outputting the information
    //outputs the information part of the Employee class first
    out << (Employee) hEmp << std::endl 
        << "Hours Worked: " << hEmp.hWorked << std::endl
        << "Hourly Rate: " << hEmp.hRate << std::endl;
    
    //returning the output
    return out;
}


//--------------------------other methods-------------------------------

//the getWeeklyPay calculates the hourly employee's weekly pay
double HourlyEmployee::getWeeklyPay() const{
    
    double weeklyPay = 0;//initializing variable for weekly pay
    
    if (hWorked <= OVERTIME)//if the employee does not work overtime
        //calculate the pay by multiplying the hours worked by the hourly rate
        weeklyPay = hWorked * hRate;
    else //if employee works overtime
        //include the additional pay for overtime 
        weeklyPay = (OVERTIME * hRate) + ((hWorked - OVERTIME) * hRate * 1.5);
    
    //returning the weekly pay
    return weeklyPay;
}//end getWeeklyPay

