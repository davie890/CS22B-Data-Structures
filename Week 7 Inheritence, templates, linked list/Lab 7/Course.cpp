// Course.cpp: implementation of Course class
// Name: C. Nguyen
// Date: June 2015

#include "Course.h"

// enqueueWaitList: add student name to the end of the wait list
bool Course::enqueueWaitList(string name)
{
	if (waitListCount == maxWaitList)   // if list count is at max
		return false;
	
	waitListBack++;						// otherwise add name to the back of the queue
	if (waitListBack == maxWaitList)   
		waitListBack = 0;
	waitList[waitListBack] = name;
	waitListCount++;					// and increment count of students on wait list
	return true;
}

// dequeueWaitList: remove student name at the front of the wait list and pass the name back by reference
// return: true if there is student to remove, false if list is empty
bool Course::dequeueWaitList(string & outputStr)
{
	if (waitListCount == 0)				// if there is no student, return false
		return false;

	waitListFront++;					// otherwise remove name from the front of the queue and pass back by reference
	if (waitListFront == maxWaitList)   
		waitListFront = 0;
	outputStr = waitList[waitListFront];
	waitListCount--;					// decrement student count on wait list
	if (waitListCount == 0)
		waitListFront = waitListBack = -1;		// if list is empty, reset front and back index of queue
	return true;						// return true because student was removed from queue
}

// printStudents: print student info: class list if available, wait list if available
void Course::printStudents() const
{
	// if there are students in the class, print class list
	if (classList.getCount() > 0)
	{
		cout << name << " class list:\n";
		classList.displayList();

		// if there is a wait list, print wait list 
		if (waitListCount > 0)
		{
			cout << name << " wait list:\n";
			int k = 1;
			int i = waitListFront;     // print from front of queue
			while (i < waitListBack)   // to back of queue
			{
				i++;
				if (i == maxWaitList)
					i = 0;
				cout << k++ << ". " << waitList[i] << endl;
			}
		}
	}
	cout << endl;
}