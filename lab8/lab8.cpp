//3.21.2023
//Diya Tomar
//This program calculates the quiz average, homework average, and test 
//average for each student. The program processes a file containing 
//student grades for some course. The program calculates the overall 
//numeric grade using the following weights: Quiz = 30%, Homework = 30%, 
//Tests = 40%.

#include <iostream>//for outputting results to the screen
#include <iomanip>//for output manipulation
#include <fstream>//for file input
#include <string>//for file names

using namespace std;//allows the usage of keywords such as cout and cin

//constants for the quiz, homework, and test weight in the overall average
const double QUIZ_WEIGHT = 0.3, HW_WEIGHT = 0.3, TEST_WEIGHT = 0.4;

//the openFiles function asks the user for the name of the 
//input file and opens the input file
//parameter is the input stream
void openFiles(ifstream &input) {//openFiles function declaration
    string fileName;//declaring variable for the name of the input file
    
    //asking user to enter name of file
    cout << "Enter the name of the file containing student grades: ";
    cin >> fileName;
    
    //opening input file
    input.open(fileName);
}//end openFiles


//the printHeader function prints out a header that indicates the course
//for which grades are being presented and indicates what information
//is being presented in each column
//parameter is the input stream
void printHeader(ifstream &input) {//printHeader function declaration
    string courseName;//declaring variable that will store course name
    
    getline(input, courseName);//reading in course name from input file
    
    //printing out header indicating the course for which grades are being presented
    cout << "Grades for " << courseName << endl;
    
    //header indicating columns of information
    cout << "Student ID    Quiz Average    Homework Average    Test Average    Numeric    Letter" << endl;
}//end printHeader


//the letterGrade function takes the numeric grade for each student
//and returns the corresponding letter grade (numeric grade is assumed to be 100% or less)
//parameter is the overall grade of the student
string letterGrade(double grade) {//letterGrade function declaration
    
    //if the overall grade is less than or equal to 100% and greater than or equal to 93%
    if (grade <= 100 and grade >= 93) {
        return "A ";//the letter grade is A
    }
    //else if the overall grade is less than 93% and greater than or equal to 90%
    else if (grade < 93 and grade >= 90) {
        return "A-";//the letter grade is A-
    }
    //else if the overall grade is less than 90% and greater than or equal to 88%
    else if (grade < 90 and grade >= 88) {
        return "B+";//the letter grade is B+
    }
    //else if the overall grade is less than 88% and greater than or equal to 83%
    else if (grade < 88 and grade >= 83) {
        return "B ";//the letter grade is B
    }
    //else if the overall grade is less than 83% and greater than or equal to 80%
    else if (grade < 83 and grade >= 80) {
        return "B-";//the letter grade is B-
    }
    //else if the overall grade is less than 80% and greater than or equal to 78%
    else if (grade < 80 and grade >= 78) {
        return "C+";//the letter grade is C+
    }
    //else if the overall grade is less than 78% and greater than or equal to 73%
    else if (grade < 78 and grade >= 73) {
        return "C ";//the letter grade is C
    }
    //else if the overall grade is less than 73% and greater than or equal to 70%
    else if (grade < 73 and grade >= 70) {
        return "C-";//the letter grade is C-
    }
    //else if the overall grade is less than 70% and greater than or equal to 68%
    else if (grade < 70 and grade >= 68) {
        return "D+";//the letter grade is D+
    }
    //else if the overall grade is less than 68% and greater than or equal to 63%
    else if (grade < 68 and grade >= 63) {
        return "D ";//the letter grade is D
    }
    //else if the overall grade is less than 63% and greater than or equal to 60%
    else if (grade < 63 and grade >= 60) {
        return "D-";//the letter grade is D-
    }
    //else if the overall grade is less than 60%
    else {
        return "F ";//the letter grade is F
    }
}//end letterGrade


//the gradeCalc function reads in 5 grades and calculates the sum 
//and average of the grades (referencing average to change the actual 
//parameter's value, which is used to calculate the overall average)
//parameters are the input stream and the average of the grades
void gradeCalc(ifstream &input, double &average) {//gradeCalc function declaration
    double grade;//declaring variable for the grade being read from the input file
    double sum = 0;//initializing variable for the sum of the grades
    
    //a for loop that keeps going till it has read in 5 grade values
    for (int value = 1; value < 6; value++) {
        //reads in a grade value
        input >> grade;
        //adds grade value to sum
        sum += grade;
    }
    //calculates average of the 5 grades (dividing sum by 5)
    average = sum / 5;
        
}//end gradeCalc


//the studentGrades function presents each student's quiz, test, homework, and
//overall average
//parameter is the input stream
void studentGrades(ifstream &input) {//studentGrades function declaration
    
    string studentID;//declaring variable for the student ID
    double quizAverage = 0;//initializing variable for average of quiz grades
    double homeworkAverage = 0;//initializing variable for average of homework grades
    double testAverage = 0;//initializing variable for average of test grades
    
    input >> studentID;//reading in first student's ID
        
    //calling gradeCalc function to calculate quiz sum and average
    gradeCalc(input, quizAverage);
    //calling gradeCalc function to calculate test sum and average
    gradeCalc(input, homeworkAverage);
    //calling gradeCalc function to calculate test sum and average
    gradeCalc(input, testAverage);
    
    //calculating numeric value of overall grade by adding the quiz, homework, and test averages
    //multiplied by their respected weight in the overall average    
    double numeric = (quizAverage * QUIZ_WEIGHT) + (homeworkAverage * HW_WEIGHT) + (testAverage * TEST_WEIGHT);
    
    
    while (input) {//while there is still information about student grades in the file

        cout << right << setw(10) << studentID;//printing previous student's ID
        //printing out previous student's quiz average
        cout << right << setw(16) << setprecision(1) << fixed << quizAverage;
        //printing out previous student's homework average
        cout << right << setw(20) << homeworkAverage;
        //printing out previous student's test average
        cout << right << setw(16) << testAverage;
        
        //printing the previous student's numeric grade
        cout << right << setw(11) << numeric;
        //calling the letterGrade function to print out the letter grade equivalent
        cout << right << setw(10) << letterGrade(numeric) << endl;
        
        //resetting values to 0 for next student
        quizAverage = 0;
        homeworkAverage = 0;
        testAverage = 0;
        
        input >> studentID;//reading in next student's ID
        
        //calling gradeCalc function to calculate quiz sum and average
        gradeCalc(input, quizAverage);
        //calling gradeCalc function to calculate test sum and average
        gradeCalc(input, homeworkAverage);
        //calling gradeCalc function to calculate test sum and average
        gradeCalc(input, testAverage);
        
        //calculating numeric value of overall grade by adding the quiz, homework, and test averages
        //multiplied by their respected weight in the overall average   
        numeric = (quizAverage * QUIZ_WEIGHT) + (homeworkAverage * HW_WEIGHT) + (testAverage * TEST_WEIGHT);

    }
}//end studentGrades


int main() {//main function declaration
    
    ifstream input;//opening input file
    openFiles(input);//calling openFiles function
    
    if (!input) {//if file failed to open
        //tell user there's an error with opening the file
        cerr << "Error opening file. Terminating program." << endl;
        return -1;//error code
    }
    
    printHeader(input);//calling the printHeader function
    
    studentGrades(input);//calling the studentGrades function
    
    return 0;//if everything works, return 0
}//end main

