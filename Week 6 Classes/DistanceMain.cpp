// DistanceMain.cpp: driver for Distance class
#include <iostream>
#include "Distance.h"
using namespace std;

int main()
{
	// 1. creating objects and using standard IO for objects
	Distance one("one", 3, 5);			//need constructor
	Distance two("two");
	cin >> two;					//need 
	cout << one;
	cout << two;
	
	// 2. Adding distance and assign to new object, index new object
	Distance total; //= one + two; //total is getting created
								//therefore the copy constructor is run

	total = total + one + two;	//total already exist(big difference), therefore the
								//member function operator= will run
	cout << total;
	cout << "\nTotal is " << total[0] << " feet, " << total[1] << " inches\n";
	
	
	// 3. Comparing distance
	cout << "\nComparing: \n";
	if (one < two)
		cout << "one is shorter\n";
	else
	   cout << "one is not shorter\n";

	// 4. Prefix decrementing distance
	cout << "\nPrefix --\n";
	Distance oneDec = --one;
	cout << "original one: " <<  one;
	cout << "prefix one: " << oneDec;

	// 5. Postfix decrementing distance 
	cout << "\nPostfix --\n";
	Distance twoDec = two--;
	cout << "original two: " << two;
	cout << "postfix two: " << twoDec;

	// 6. Converting distance
	int totalInches = total;
	cout << "\nconverting total to total inches: " << totalInches << " inches" << endl;

	return 0;
}

ostream & operator<< (ostream & ostr, const Distance & object)
{
	ostr << object.name << ": " << object.d[0] << "ft, " << object.d[1] << "in" << endl;
	return ostr;		
	//return the ostream object so function chaining can occur
}

istream & operator>> (istream & istr, Distance & object)
{
	cout << "What is the name?" << endl;
	istr >> object.name;
	
	cout << "What is the distance in feet?" << endl;
	istr >> object.d[0];

	cout << "What is the distance in inches?" << endl;
	istr >> object.d[1];
	if (object.d[1] > 11 || object.d[1] < 0)
		object.format();
	
	return istr;
}