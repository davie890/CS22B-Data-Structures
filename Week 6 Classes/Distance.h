// Distance.h: header file for Distance class
#ifndef DISTANCE_H
#define DISTANCE_H

#include <iostream>
#include <string>
using namespace std;

// The Distance class holds a distance in feet and inches
class Distance
{
private:
	string name;
	int * d;          // d for distance, array of 2 integers: d[0] = ft, d[1] = inches   
	void format();    // formatting inches to between 0 and 12
public:
	Distance(string name = "default", int ft = 0, int in = 0) : name(name)
	{
		d = new int[2];
		d[0] = ft;
		d[1] = in;
		if (d[1] > 11 || d[1] < 0 )
			format();
	}

	//copy constructor
	Distance(const Distance & right);

	// 1. copy the function prototype of the operator<< into the header file
	// 2. grant it friend status
		///always pass structs/classes/OBJECTS by reference &!!!
	friend ostream & operator<< (ostream & ostr, const Distance & object);	//friend function cannot be a member function
	friend istream & operator>> (istream & istr, Distance & object);

	//overload + operator
	Distance operator+ (const Distance & right);

	//overload [] operator
	int & operator[] (int index) { return d[index]; }

	//overload < operator
	bool operator< (const Distance & right);

	//overload = operator
	Distance operator= (const Distance & source);

	//overload prefix --
	Distance operator-- ();

	//overload postfix--
	Distance operator-- (int );

	//overload converstion to int
	operator int() { return d[0] * 12 + d[1]; }	//convert distance to total inches

	//destructor
	~Distance() { delete [] d; }
};

#endif