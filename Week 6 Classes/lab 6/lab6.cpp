// Lab 6:  driver for Course class, create several Course objects to test the Course class
// Name:	Davie Truong
// Date:	5/28/15

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "Course.h"

using namespace std;


int main()
{
	// 1. Create 3 Courses
	Course class1("lab6.txt");		// input from file, file has: name of class (1st line), max number of students (2nd line), student names (1 name per line)

	vector<string> v = { "Lovelace, Ada", "Babbage, Charles", "Shannon, Claude" };
	Course class2("CIS 22B", 4, v.size(), v);     // input from user: name of class, max number of students, actual number of students, vector of student names
	
	Course class3;    // no input

	//// 2. Print each course
	cout << "\n== List of classes ==\n\n";
	cout << class1;
	cout << class2;
	cout << class3;
	cout << "====================\n\n";

	//// 3. Add and drop students from course
	cout << "Adding student to class 2\n";
	class2 += "von Neumann, John";            // add student name at the next available space in the names array
	cout << class2;
	cout << "Adding student to class 2\n";
	class2 += "Ritchie, Dennis";
	cout << class2;
	cout << "Dropping student from class 2\n";
	class2 -= "Babbage, Charles";       // remove student name from the array, then shift left remaining student names
	cout << class2;
	cout << "Dropping student from class 2\n";
	class2 -= "abc, xyz";
	cout << class2;
	cout << "Adding student to class 2\n";
	class2 += "Ritchie, Dennis";
	cout << class2;

	//// 4. Summary of courses
	cout << "All classes\n";
	Course myTotal = class1;
	myTotal = myTotal + class2;    // myTotal's name is a concatenation of the 2 input names, and myTotal's names array is a concatenation of the 2 input arrays

	cout << myTotal;

	//// 5. Add more students
	cout << "Addding student to class 1\n";
	class1 += "Berners-Lee, Tim";
	cout << class1;

	cout << "Adding students to class 3\n";
	class3 += "Borg, Anita";
	class3 += "Boole, George";
	cout << class3;
	return 0;
}