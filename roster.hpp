//
//  roster.hpp
//  scripting
//
//  Created by Scott on 3/1/23.
//

#ifndef roster_hpp
#define roster_hpp

#include "student.hpp"

// E.  Create a Roster class (roster.cpp) by doing the following:
class Roster {
    public:
        // Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
        vector<Student*> classRosterArray;
        void parse(const string studentData[]);
        
        //sets the instance variables from part D1 and updates the roster.
        void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
        
        // removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
        void remove(string studentID);
        
        // prints a complete tab-separated list of student data. loops through all the students in classRosterArray and calls the print() function for each student.
        void printAll();
        
        //prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
        void printAverageDaysInCourse(string studentID);
        
        // verifies student email addresses and displays all invalid email addresses to the user.
        void printInvalidEmails();
        
        // prints out student information for a degree program specified by an enumerated type.
        void printByDegreeProgram(DegreeProgram degreeProgram);
        
        // Implement the destructor to release the memory that was allocated dynamically in Roster
        void destroyContents();
        
};

#endif /* roster_hpp */
