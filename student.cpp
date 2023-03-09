//
//  student.cpp
//  scripting
//
//  Created by Scott on 3/1/23.
//
#include "student.hpp"

// All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.

// Setter Functions
void Student::setID(string id) {
    stuID = id;
}
void Student::setFirst(string first) {
    this->first = first;
}
void Student::setLast(string last) {
    this->last = last;
}
void Student::setEmail (string email)  {
    this->email = email;
}
void Student::setAge (int num) {
    age = num;
}
void Student::setDurations (int num1, int num2, int num3){
    durations.at(0) = num1;
    durations.at(1) = num2;
    durations.at(2) = num3;
}
void Student::setProgram (DegreeProgram program){
    this->program = program;
}

// Getter Functions
string Student::getID() const {
    return stuID;
};
string Student::getFirst() const{
    return first;
};
string Student::getLast() const{
    return last;
};
string Student::getEmail() const{
    return email;
};
int Student::getAge() const{
    return age;
};
vector<int> Student::getDurations() const{
    return durations;
};
DegreeProgram Student::getProgram() const{
    return program;
};

// Constructors
Student::Student() {
    stuID = "undefined";
    first = "undefined";
    last = "undefined";
    email = "undefined";
    age = -1;
    durations = {-1,-1,-1};
    program = UNDEFINED;
}

// constructor using all of the input parameters provided in the table

Student::Student(string id, string first, string last, string email, int age, vector<int> durations, DegreeProgram program) {
    stuID = id;
    this->first = first;
    this->last = last;
    this->email = email;
    this->age = age;
    this->durations = durations;
    this->program = program;
    
    if (program == SECURITY) {programString = "Security";}
    if (program == SOFTWARE) {programString = "Software";}
    if (program == NETWORK) {programString = "Network";}
}

// to print specific student data
void Student::Print() {
    cout << "Student ID: " << stuID << "    First Name: " << first << "    Last Name: " << last << "    Email: " << email << "    Age: " << age << "    Days in Course: {" << durations.at(0) << ", " << durations.at(1) << ", " << durations.at(2) << "}" << "    Program: " << programString << endl;
}
// Implement the destructor to release the memory that was allocated dynamically in Roster
Student::~Student(){
    cout<< "Delete Student: " << this->getID() << endl;
}



