//
//  ShortCourse.h
//  lab7
//
//  Created by Ibrahim Elsakka on 6/14/15.
//  Copyright (c) 2015 Ibrahim Elsakka. All rights reserved.
//  ShortCourse header file

#ifndef __lab7__ShortCourse__
#define __lab7__ShortCourse__

#include "Course.h"
#include <vector>
// Class definition
class ShortCourse : public Course   // public or protected? why?
{
protected:
    int maxStudents;
    bool open;

public:
    // Constructor with a single string argument
    ShortCourse(string input = "", int maxStudents = 2, bool open = true) : Course(input){this->maxStudents = maxStudents; this->open = open;}    // bugfix later

    // Constructor with a string and a vector argument, copy vector then print class is full before listing students in class
    ShortCourse(string input, vector<string> v);
    // add function         bool or void?
    void add(string input);
    // drop function        bool or void?
    void drop(string input);
    // << operator overload should print: "Name" << className << size: << num << "status" << status
    friend ostream & operator<<(ostream & ostr, const ShortCourse & object);
    // Public Speaking class list (should be a function)    || in Course.cpp?

    // destructor
    // ~ShortCourse(){}; don't have empty destructor because inefficient
};

#endif /* defined(__lab7__ShortCourse__) */
