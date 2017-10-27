//Course header file
//Davie Truong

#ifndef Course_H
#define Course_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Course
{
private:
	//name(a string) : the name of the course(such as "CIS 22B")
	string name;

	//maxStudents(an int) : the maximum number of students in the course
	int maxStudents; 

	//numStudents(an int) : the actual number of students registered in the course
	int numStudents;

	//names(a dynamically allocated array of string) : all student names that are in the class.The array should be the size of maxStudents.
	string * names;
	
public: 
	//default constructor
	Course();
	Course(string name, int maxStudents, int numStudents, vector <string> names);
	Course(string fileName);

	//overloaded function defininition
	//  << print function
	friend ostream & operator<< (ostream & ostr, const Course & object);	

	//  += adding student to nexzt avaialbe space in class    
	Course operator+= (string right);

	// -= remove student name from the array, then shift left	
	Course operator-= (string right);

	//copy constructor
	Course(const Course & right);
	
	//copy operator overload =, 
	Course operator= (const Course & right);
	
	// + name is concaendated, array is concatendated to the current array
	Course operator+ (const Course & right);
	
	//destructor
	~Course() { delete[] names; }

};
#endif