// Distance.cpp: Implementation file for the Distance class

#include "Distance.h"


// private function to format inches to be between 0 and 12
void Distance::format()
{
   if (d[1] >= 12)				// if inches >= 12
   {
      d[0] += d[1] / 12;		// add to feet
      d[1] = d[1] % 12;			// keep remainder in inches
   }
   else if (d[1] < 0)			// if inches < 0
   {
	   d[0]--;					// subtract from feet
	   d[1] += 12;				// add 12 to inches
   }
}

Distance Distance::operator+ (const Distance & right)
{
	Distance sum;
	
	sum.d[0] = d[0] + right.d[0];
	sum.d[1] = d[1] + right.d[1];
	if (sum.d[1] > 11)
		sum.format();
	return sum;
}

bool Distance::operator< (const Distance & right)
{
	if (d[0] < right.d[0])
	{
		return true;
	}
	else if (d[0] == right.d[0] && d[1] < right.d[1])
	{
		return true;
	}
	return false;

}

Distance Distance::operator= (const Distance & source)
{
	name = source.name;
	if (d)				//check to see if names is pointing to an array or not
	{
		delete[] d;		//delete existing array
	}
	d = new int[2];		//create new arry
	d[0] = source.d[0];
	d[1] = source.d[1];
	return *this;
}


Distance::Distance(const Distance & right)
{
	name = right.name;
	d = new int[2];
	d[0] = right.d[0];
	d[1] = right.d[1];
}

Distance Distance::operator-- ()
{
	d[1] = d[1] - 1;	//subtract 1 from d[1]
	if (d[1] < 0)
		format();
	return *this;
}

Distance Distance::operator-- (int)
{
	// 1. copy current object
	Distance copy = *this;
	// 2. decrement current object
	d[1] = d[1] - 1;	//subtract 1 from d[1]
	if (d[1] < 0)
		format();
	// 3. return copy
	return copy;
}