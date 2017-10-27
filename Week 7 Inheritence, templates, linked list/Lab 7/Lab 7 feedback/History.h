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
		this->maxStudents = maxStudents;     ///////////// use initialization list
		this->units = units;               ///////////// use initialization list
	}
	//constructor with vectors
	History(string name, int maxStudents, double units, vector<string> v);
	//add name to the LinkedList function
	void add(string name);
	//drop function
	void drop(string name);
	//copy construcor
	History(History & right);           /////////////// don't need
	//operator = overload				
	History operator= (History & right);   ///////////////// don't need
	//operator << ovlerload
	friend ostream & operator<< (ostream & ostr,History & object);
};
#endif