//
//  roster.cpp
//  scripting
//
//  Created by Scott on 3/1/23.
//

#include "roster.hpp"
#include <numeric>

// Parse each set of data identified in the “studentData Table.”
void Roster::parse(const string studentData[]) {
    for (int i=0; i<5; i++){
        string input = studentData[i];
        istringstream inSS(input);
        string id;
        string firstName;
        string lastName;
        string email;
        int age;
        int d1;
        int d2;
        int d3;
        string program;
        DegreeProgram programType;
    
        // E.2.a Parse values from input string
        inSS >> id;
        inSS >> firstName;
        inSS >> lastName;
        inSS >> email;
        inSS >> age;
        inSS >> d1;
        inSS >> d2;
        inSS >> d3;
        inSS >> program;

        vector<int> durations = {d1, d2, d3};
        if (program == "SOFTWARE") {programType = SOFTWARE;};
        if (program == "NETWORK") {programType = NETWORK;};
        if (program == "SECURITY") {programType = SECURITY;};

        // E.2.b Write values to object
        Student* student = new Student(id, firstName, lastName, email, age, durations, programType);
        classRosterArray.push_back(student);
    };
};

// sets the instance variables from part D1 and updates the roster.
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram){
    
    vector<int> durations = {daysInCourse1, daysInCourse2, daysInCourse3};
    Student* student = new Student(studentID, firstName, lastName, emailAddress, age, durations, degreeprogram);
    classRosterArray.push_back(student);
    
};

// removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
void Roster::remove(string studentID){
    cout << "Removing Student..." << endl;
    bool flag = false;
    for (int i=0; i<classRosterArray.size(); i++){
        if (classRosterArray.at(i)->getID() == studentID) {
            delete classRosterArray.at(i);
            classRosterArray.erase(classRosterArray.begin()+i);
            flag = true;
            break;
        }
    }
    if (flag == false) {cout << "A student with this ID was not found" << endl;}
};

//  prints a complete tab-separated list of student data. loops through all the students in classRosterArray and calls the print() function for each student.
void Roster::printAll(){
    cout << "The following students are in the roster: " << endl;
    for (int i=0; i<classRosterArray.size(); i++){
        classRosterArray.at(i)->Print();
    };
};

// prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
void Roster::printAverageDaysInCourse(string studentID){
    cout << "Average Course Durations" << endl;
    for (int i=0; i<classRosterArray.size(); i++){
        int average = 0;
        string ID = classRosterArray.at(i)->getID();
        if (ID == studentID) {
            vector<int> durations = classRosterArray.at(i)->getDurations();
            average = accumulate(durations.begin(), durations.end(), 0.0)/durations.size();
            cout << "ID: " << ID << "| Average course duration : " << average << endl;
          };
    };
};

// verifies student email addresses and displays all invalid email addresses to the user.
void Roster::printInvalidEmails(){
    cout << "Invalid Emails" << endl;
    int count = 0;
    vector<string> invalid(0);
    
    for (int i=0; i<classRosterArray.size(); i++){
        string email = classRosterArray.at(i)->getEmail();
        int n = email.length();
        int atCount = 0;
        int dotCount = 0;
        int spaceCount = 0;
        
        // Iterate through letters in email string.
        for (int j=0; j<n; j++){
            if (email[j] == '@') {atCount += 1;};
            if (email[j] == '.' && atCount >0) {dotCount += 1;};
            if (email[j] == ' ') {spaceCount += 1;};
        };
        
        // If criteria aren't met, add email to array.
        if (atCount != 1 || dotCount == 0 || spaceCount != 0) {
            invalid.push_back(email);
            count +=1; };
    };
    // If there are invalid emails, print them.
    if (count > 0) {
        cout << "The following email address(es) are invalid:" << endl;
        for (int i=0; i<count; i++) {
            cout << invalid.at(i) << endl;
        };
        cout << endl;
    };
};

// prints out student information for a degree program specified by an enumerated type.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    cout << "Students: " << endl;
    for (int i=0; i<classRosterArray.size(); i++){
        vector<string> members(0);
        DegreeProgram program = classRosterArray.at(i)->getProgram();
        string first;
        string last;
        if (program == degreeProgram) {
            first = classRosterArray.at(i)->getFirst();
            last = classRosterArray.at(i)->getLast();
            string full = first + ' ' + last;
            members.push_back(full);
        }
        for (int i=0; i<members.size(); i++) {
            cout << members.at(i) << endl;
        }
    }
};

// Implement the destructor to release the memory that was allocated dynamically in Roster
void Roster::destroyContents(){
    cout << "Destroying Roster Contents..." << endl;
    for (int i=0; i<classRosterArray.size(); i++){
        delete classRosterArray.at(i);
    }
}
