//
//  student.hpp
//  scripting
//
//  Created by Scott on 3/1/23.
//

#ifndef student_hpp
#define student_hpp
#include "degree.h"

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

    // Create each of the following functions in the Student class:
    //a.  an accessor (i.e., getter) for each instance variable from part D1
    //b.  a mutator (i.e., setter) for each instance variable from part D1
    //c.  All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
    //d.  constructor using all of the input parameters provided in the table
    //e.  print() to print specific student data

class Student {
    public:
        // Setter Functions
        void setID(string id);
        void setFirst(string first);
        void setLast(string last);
        void setEmail (string email);
        void setAge (int num);
        void setDurations (int num1, int num2, int num3);
        void setProgram (DegreeProgram program);
        
        // Getter Functions
        string getID() const;
        string getFirst() const;
        string getLast() const;
        string getEmail() const;
        int getAge() const;
        vector<int> getDurations() const;
        DegreeProgram getProgram() const;
        
        // D.2.d Constructors
        Student();
        Student(string id, string first, string last, string email, int age, vector<int> durations, DegreeProgram program);
        
        // D.2.e Print
        void Print();
        // Implement the destructor to release the memory that was allocated dynamically in Roster
        ~Student();
        
        
    // Create the class Student  in the files student.h and student.cpp, which includes each of the following variables:
    //•  student ID
    //•  first name
    //•   last name
    //•  email address
    //•  age
    //•  array of number of days to complete each course
    //•  degree program
    
    private:
        string stuID;
        string first;
        string last;
        string email;
        int age;
        vector<int> durations;
        DegreeProgram program;
        string programString;
    
};


#endif /* student_hpp */
