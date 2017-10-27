//History header file for lab 7
//Davie Truong

#ifndef History_H
#define History_H

#include "Course.h"

using namespace std;

class History : public Course
{
protected:
	int maxStudents;
	double units;
public:
	//default constructor
	History(string name = "New Class", int maxStudents = 0, double units = 0) : Course(name)
	{
		this->maxStudents = maxStudents;
		this->units = units;
	}
	//constructor with vectors
	History(string name, int maxStudents, double units, vector<string> v);
	//add name to the LinkedList function
	void add(string name);
	//drop function
	void drop(string name);
	//copy construcor
	History(History & right);
	//operator = overload
	History operator= (History & right);
	//operator << ovlerload
	friend ostream & operator<< (ostream & ostr,History & object);
};
#endif