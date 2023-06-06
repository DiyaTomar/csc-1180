//3.28.2023
//Diya Tomar
//This header file contains a class to model a Time. The class consists 
//of three integer values representing the hour, minute, and second, and
//stores the Time in a 24-hour format. The class has two methods that 
//allow for representing the time as military and standard. 

#include <iostream>//for outputting the results to the screen
#include <string>//allows for usage of string data type

//-------------------------CLASS DEFINITION-----------------------------

//the class TimeType models a Time using hour, minute, and second
class TimeType {//TimeType class definition                                  
    
    private://access specifier, contains private class members
        int hour;//attribute of type int for hour
        int minute;//attribute of type int for minute
        int second;//attribute of type int for second 
        
    public://access specifier, contains public class members
        
        //constructor with default parameters (fills in       
        //values not provided with 0)
        TimeType(int = 0, int = 0, int = 0);
        
        //set methods (mutators)
        void setHour(int);//setHour method                                  
        void setMinute(int);//setMinute method
        void setSecond(int);//setSecond method
        
        //get methods (accessors)
        int getHour() const;//getHour method
        int getMinute() const;//getMinute method
        int getSecond() const;//getSecond method
        
        std::string military() const;//military method
        std::string standard() const;//standard method
        
};//end class definition     
                                               


//----------------------------GET METHODS-------------------------------

//the getHour method returns the hour value                              
int TimeType::getHour() const {//getHour method declaration
    return hour;
}//end getHour

//the getHour method returns the minute value
int TimeType::getMinute() const{//getMinute method declaration
    return minute;
}//end getMinute

//the getHour method returns the second value
int TimeType::getSecond() const{//getSecond method declaration
    return second;
}//end getSecond


//-----------------------------SET METHODS------------------------------

//The setHour method checks whether the hour value provided by the         
//actual parameter is valid and sets the hour value accordingly.
//h means hour
void TimeType::setHour(int h) {//setHour method declaration                
    //validation code for data coming in
    if (h >= 0 and h <= 23) {//if parameter value is greater than or equal to 0 and less than or equal to 23
        hour = h;//set hour's value to h
    }
    else {//else if value does not fit the requirement
        //print error message
        std::cerr << "Invalid hour value provided (must be between 0-23). Setting to 0." << std::endl;
        hour = 0;//set hour's value to default value of 0
    }
}//end setHour


//The setMinute method checks whether the minute value provided by the    
//actual parameter is valid and sets the minute value accordingly.
//m means minute
void TimeType::setMinute(int m) {//setMinute method declaration           
    //validation code for data coming in
    if (m >= 0 and m <= 59) {//if parameter value is greater than or equal to 0 and less than or equal to 59
        minute = m;//set minute's value to m
    }
    else {//else if value does not fit the requirement
        //print error message
        std::cerr << "Invalid minute value provided (must be between 0-59). Setting to 0." << std::endl;
        minute = 0;//set minute's value to default value of 0
    }
}//end setMinute


//The setSecond method checks whether the second value provided by the    
//actual parameter is valid and sets the second value accordingly.
//s means second
void TimeType::setSecond(int s) {//setSecond method declaration
    //validation code for data coming in
    if (s >= 0 and s <= 59) {//if parameter value is greater than or equal to 0 and less than or equal to 59
        second = s;//set second's value to s
    }
    else {//else if value does not fit the requirement
        //print error message
        std::cerr << "Invalid second value provided (must be between 0-59). Setting to 0." << std::endl;
        second = 0;//set second's value to default value of 0
    }
}//end setSecond


//----------------------------CONSTRUCTORS------------------------------

//the TimeType constructor initializes objects and sets the object's       
//hour, minute, and second values
//h means hour, m means minute, s means second
TimeType::TimeType(int h, int m, int s) {//TimeType constructor implementation
    //calling the set methods to set the hour, minute and second values
    setHour(h);
    setMinute(m);
    setSecond(s);
}//end TimeType constructor


//--------------------------STRING METHODS------------------------------

//the military method returns a string representing the time in military time
std::string TimeType::military() const {//military method declaration
    
    //initializing variables to store hour, minute and second values as strings
    std::string mHour = std::to_string(hour);
    std::string mMinute = std::to_string(minute);
    std::string mSecond = std::to_string(second);
    std::string mTime = "";//initializing variable of type string to store military time
    
    
    if (mHour.length() == 1) {//if the string length of the hour value is 1
        mHour = "0" + mHour;//add a leading zero to the string
    }
    if (mMinute.length() == 1) {//if the string length of the minute value is 1
        mMinute = "0" + mMinute;//add a leading zero to the string
    }
    if (mSecond.length() == 1) {//if the string length of the second value is 1
        mSecond = "0" + mSecond;//add a leading zero to the string
    }
    
    //storing string with hour, minute, and second values in military time
    mTime = mHour + ":" + mMinute + ":" + mSecond;
    
    //returing the mTime string (time in military)
    return mTime;
    
}//end military

//the standard method returns a string representing the time in standard time
std::string TimeType::standard () const {//standard method declaration
    
    std::string timePeriod = "";//initializing variable for the time period (AM or PM)
    int newHour = hour;//initializing variable for the hour value in standard time (setting to hour value)
    std::string sTime = "";//initializing variable of type string to store standard time
    
    if (hour >= 12) {//if hour value is greater or equal to 12
        timePeriod = "PM";//it is PM
    }
    else {//else if hour value is less than 12
        timePeriod = "AM";//it is AM
    }
    
    
    if (hour == 0) {//if hour value is 0
        newHour = 12;//set newHour to 12 (0 is 12 in standard time )
    }
    if (hour > 12) {//if hour value is greater than 12
        newHour = hour - 12;//set newHour to the hour value subtracted by 12 (ex. 13 --> 13 - 12 = 1 in standard time)
    }
    
    //initializing variables to store hour, minute, and second values as strings
    std::string sHour = std::to_string(newHour);
    std::string sMinute = std::to_string(minute);
    std::string sSecond = std::to_string(second);
    
    if (sHour.length() == 1) {//if the string length of the hour value is 1
        sHour = "0" + sHour;//add a leading zero to the string
    }
    if (sMinute.length() == 1) {//if the string length of the minute value is 1
        sMinute = "0" + sMinute;//add a leading zero to the string
    }
    if (sSecond.length() == 1) {//if the string length of the second value is 1
        sSecond = "0" + sSecond;//add a leading zero to the string
    }
    
    //storing string with hour, minute, and second values in standard time
    sTime = sHour + ":" + sMinute + ":" + sSecond + " " + timePeriod;
    
    //returing the sTime string (time in standard)
    return sTime;
    
}//end standard
