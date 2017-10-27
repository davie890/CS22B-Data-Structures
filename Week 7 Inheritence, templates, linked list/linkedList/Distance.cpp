// Implementation file for the Distance class
#include <cstdlib>       // Needed for abs()
#include "Distance.h"
#include <cstring>
#include <string>

// constructor
Distance::Distance(int f, int i)
{ 
	if (f < 0) 
		f = 0; 
	feet = f;
	if (i < 0) 
		i = 0;
    inches = i;
}



