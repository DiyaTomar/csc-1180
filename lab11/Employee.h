#pragma once
#include "Person.h"
#include "DateType.h"
#include <string>
#include <iostream>

class Employee : public Person {
	private:
        DateType hireDate;      //date of hiring
        std::string department; //department assigned
        std::string empID;      //employee id number (not the ssn)       

	public:
        double getWeeklyPay() const;
        
        friend std::ostream& operator<<(std::ostream& out, const Employee&);

        DateType getHireDate() const;
        std::string getDept() const;
        std::string getEmpID() const;
        void setHireDate(DateType);
        void setDept(std::string);
        void setEmpID(std::string);
        Employee();            //default constructor
        Employee(std::string, std::string, DateType, DateType, std::string, std::string);

};//end class Employee
double Employee::getWeeklyPay() const
{
    return 0;//base employees don't have a weekly pay
}

std::ostream& operator<<(std::ostream& out, const Employee &emp)
{
    out << (Person) emp << std::endl
        << "Hired on: " << emp.hireDate.formatted() << std::endl
        << "Department: " << emp.department << std::endl
        << "Employee ID: " << emp.empID;

    return out;
}

DateType Employee::getHireDate() const
{
    return hireDate;
}

std::string Employee::getDept() const
{
    return department;
}

std::string Employee::getEmpID() const
{
    return empID;
}

void Employee::setHireDate(DateType d)
{
    hireDate = d;
}

void Employee::setDept(std::string dept)
{
    department = dept;
}

void Employee::setEmpID(std::string id)
{
    empID = id;
}
Employee::Employee()
    : Person()
{
   setHireDate(DateType(1,1,2000));
   setDept("none");
   setEmpID("not set");
}
Employee::Employee(std::string name, std::string ssn, DateType dob, DateType hireD,
                   std::string dept, std::string eID)
    : Person(name,ssn,dob)
{
   setHireDate(hireD);
   setDept(dept);
   setEmpID(eID);
}
