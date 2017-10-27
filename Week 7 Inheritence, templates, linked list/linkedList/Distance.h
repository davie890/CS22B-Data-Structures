#ifndef DISTANCE_H
#define DISTANCE_H

#include <iostream>
using namespace std;


// The Distance class holds a distance in feet and inches
class Distance
{
private:
	int feet;        
	int inches;      
public:
	// Constructor
	Distance(int f = 0, int i = 0);

};

#endif