//
//  ShortCourse.cpp
//  lab7
//
//  Created by Ibrahim Elsakka on 6/14/15.
//  Copyright (c) 2015 Ibrahim Elsakka. All rights reserved.
//  ShortCourse implementation file

#include "ShortCourse.h"

// constructor with input vector
// class is full, can't join:
// cout students past size

// Constructor with vector input
ShortCourse::ShortCourse(string name, vector<string> v) : Course(name)
{
    maxStudents = 2;
    for (int i = 0; i < maxStudents; i++)
    {
        classList.insertNode(v[i]);
    }
    cout << "Class is full. These students cannot register:" << endl;
    for (int i = maxStudents; i < v.size(); i++)
        cout << v[i] << endl;
}

// add function
void ShortCourse::add(string name)
{
    if (classList.getCount() < maxStudents)
    {
        classList.insertNode(name);
        cout << "Adding " << name << endl;
        if (classList.getCount() == maxStudents)
            open = false;
    }
    else
    {
        cout << "Class is full" << endl;
        open = false;
    }
}

// drop function
void ShortCourse::drop (string name)
{
    if(classList.deleteNode(name))
    {
        cout << name << " is dropped" << endl;
        open = true;
    }
    else
        cout << "This doesn't happen" << endl;
    
}


// overloaded output operator
ostream & operator<< (ostream & ostr, const ShortCourse & object)
{
    ostr << "Name: " << object.name << ", size: " << object.classList.getCount() << ", status: ";
    if(object.open)
        cout << "open";
    else
        cout << "closed";
    cout << endl;
    cout << object.name << " class list: " << endl;
    object.classList.displayList();
    return ostr;
}