//
//  main.cpp
//  scripting
//
//  Created by Scott on 3/1/23.
//

#include <stdio.h>
#include "student.hpp"
#include "roster.hpp"

int main() {
    //  Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
    cout << "Scripting and Programming - Applications C687" << endl;
    cout << "Language used: C++" << endl;
    cout << "WGU Student ID: 010591927" << endl;
    cout << "Scott Hurwitz" << endl;
    cout << endl;

    // Input Student Data Table (Preprocessed to change delim to whitespace)
    const string studentData[] =
    {"A1 John Smith John1989@gmail.com 20 30 35 40 SECURITY", "A2 Suzan Erickson Erickson_1990@gmailcom 19 50 30 40 NETWORK", "A3 Jack Napoli The_lawyer99yahoo.com 19 20 40 33 SOFTWARE", "A4 Erin Black Erin.black@comcast.net 22 50 58 40 SECURITY", "A5 Scott Hurwitz Shurwi1@wgu.edu 28 35 7 14 SOFTWARE"};
    
    // Create a student object for each student in the data table and populate classRosterArray.
    //a.  Parse each set of data identified in the “studentData Table.”
    //b.  Add each student object to classRosterArray.
    Roster classRoster1;
    classRoster1.parse(studentData);
    cout << "Roster from parsed data:" << endl;
    classRoster1.printAll();
    cout << endl;
    
    // Create array of pointers
    Roster classRoster;
    
    // Add each student to classRoster
    classRoster.add("A1", "John", "Smith", "John1989@gmail.com", 20, 30, 35, 40, SECURITY);
    classRoster.add("A2", "Suzan", "Erickson", "Erickson_1990@gmailcom", 19, 50, 30, 40, NETWORK);
    classRoster.add("A3", "Jack", "Napoli", "The_lawyer99yahoo.com", 19, 20, 40, 33, SOFTWARE);
    classRoster.add("A4", "Erin", "Black", "Erin.black@comcast.net", 22, 50, 58, 40, SECURITY);
    classRoster.add("A5", "Scott", "Hurwitz", "shurwi1@wgu.edu", 28, 35, 7, 14, SOFTWARE);
    
    // Print roster entries
    cout << "Roster from manually entered data:" << endl;
    classRoster.printAll();
    cout << endl;
    // Print invalid emails
    classRoster.printInvalidEmails();
    // Print each students' average days to complete a course
    for (int i=0; i<classRoster.classRosterArray.size(); i++){
        string ID = classRoster.classRosterArray.at(i)->getID();
        classRoster.printAverageDaysInCourse(ID); }
    cout << endl;
    // Print students in the Software degree program
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;
    // Remove entry A3 from the roster
    classRoster.remove("A3");
    cout << endl;
    // Print entries to show updated roster
    classRoster.printAll();
    cout << endl;
    // Handles the case where the object asked to remove is not present
    classRoster.remove("A3");
    cout << endl;
    // Implement the destructor to release the memory that was allocated dynamically in Roster
    classRoster.destroyContents();
    cout << endl;
    // same for parsed Roster
    classRoster1.destroyContents();
    cout << endl;
}
