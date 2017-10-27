// Course.h: header file for Course abstract class
// Name: C. Nguyen
// Date: June 2015

#ifndef _COURSE_H
#define _COURSE_H

#include <iostream>
#include <vector>
#include <string>
#include "LinkedList.h"

using namespace std;

// base class for all courses at De Anza
class Course
{
	/////// member data ///////////
protected:
	string name;						// class name
	LinkedList<string> classList;		// linked list of registered student names
	static const int maxWaitList = 15;  // max count for wait list

private:
	int waitListFront;					// data to maintain the wait list queue
	int waitListBack;
	int waitListCount;
	string waitList[maxWaitList];		// waitlist is an array which serves as a queue (First In, First Out order)
		// the array is private, and the only way to access the array is with the public enqueue and dequeue functions,
		// thus forcing the derived classes to "see" the array as a queue data structure, and not just an array
		
	//////// member functions ////////
protected:
	// constructor to initialize member data to safe values
	Course(string name) : name(name) , waitListFront(-1), waitListBack(-1), waitListCount(0) {}

	// enqueueWaitList: add student to the wait list
	// input: name of student
	// return: true - student is added 
	//         false - no more room to add
	bool enqueueWaitList(string name);

	// dequeueWaitList: remove student from wait list
	// input: reference to student name, the removed name will be passed back through this reference
	// return: true - student name is removed
	//         false - name not found or wait list is empty
	bool dequeueWaitList(string & outputStr);

	// print student info: class list if available, wait list if available
	void printStudents() const;

	// virtual add and drop functions
	virtual void add(string name) = 0;
	virtual void drop(string name) = 0;
};

#endif