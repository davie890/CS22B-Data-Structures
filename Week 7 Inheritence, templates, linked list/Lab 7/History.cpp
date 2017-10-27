//Davie Truong
//History Cpp file for History H functions

#include "History.h"

//add funbction to add names to the waitlist or class depending on its size
void History::add(string name)
{	
	if (classList.getCount() < maxStudents)	//checks to see if there is space in the class
	{
		classList.insertNode(name);			//calls the insertNode function to add the name
		cout << "Adding " << name << endl;
	}
	else
	{
		enqueueWaitList(name);	//adds the student to the waitlist if there is no space
		cout << "Class is full: " << name << " goes in wait list " << endl;
	}
}

//drop function to drop student from the class and add the first student in the wait list
void History::drop(string name)
{
	string waitlistName;

	if (classList.getCount() == 0 )	//checks to see if the class is empty or not
	{
		cout << "No Students In the Class" << endl;
	}
	else
	{
		//search for the student in the linked list and remove the node
		bool status = classList.deleteNode(name);

		if (status == false)	//checks to see if the person is in the list to remove
		{
			cout << name << " is not found in the class" << endl;
		}
		else         //if the person is found, the delete processs is ran
		{
			cout << name << " is dropped" << endl;
			//call deqeueWaitlist to remove the first student from the waitlist
			//add the dequeued student to the linklist
			if (dequeueWaitList(waitlistName) != false)
			{
				classList.insertNode(waitlistName);			//calls the insertNode function to add the name
				cout << "Adding " << waitlistName << " from wait list" << endl;
			}
		}
	}
}

ostream & operator<< (ostream & ostr, History & object)	//print function
{
	ostr << "Name: " << object.name << ", units: " << object.units << ", size: " <<
	object.classList.getCount() << ", max size: " << object.maxStudents << endl;
	object.printStudents();	//calls the prinstStudents function from the object to return the class and waitlist names
	return ostr;
}

//constructor when needed to input 4 arguments
History::History(string name, int maxStudents, double units, vector<string> v) : Course(name)
{
	int loopNum = 0;
	this->maxStudents = maxStudents;
	this->units = units;

	//if-else to determine how many people to add
	if (v.size() < maxStudents || v.size() == maxStudents)
	{
		loopNum = v.size();
	}
	else
	{
		loopNum = maxStudents;
	}
	//inserts the conetents of the vectors in to the linkedlist node
	for (int i = 0; i < loopNum; i++)
	{
		classList.insertNode(v[i]);
	}
}

//copy constructor for the waitlist
History::History(History & right) : Course(right.name)
{ 
	string waitListName;

	this->maxStudents = right.maxStudents;
	this->units = right.units;
	this->classList = right.classList;
	
	string temp[maxWaitList];			//creates a temp waitlist to store the deque, during the deque process people are removed
	int i = 0;							//therefore we must store them in a temp and re-enque them so nothing changes

	while (right.dequeueWaitList(waitListName) == true)		//while there are still people on the waitlist
	{
		this->enqueueWaitList(waitListName);	//store waitlistName into the enque waitlist
		temp[i] = waitListName;					//and an array of temp to restore it back
		i++;
	}
	for (int j = 0; j < i; j++)
	{
		right.enqueueWaitList(temp[j]);	//restores the name back to the "right" waitlist
	}
}

//operator = overload for the waitlist
//basically same as the waitlist copy construcor, expect returns the pointer to the current object
History History::operator= (History & right)
{
	string waitListName;

	this->name = right.name;
	this->maxStudents = right.maxStudents;
	this->units = right.units;
	this->classList = right.classList;

	string temp[maxWaitList];
	int i = 0;

	while (right.dequeueWaitList(waitListName) == true)
	{

		this->enqueueWaitList(waitListName);
		temp[i] = waitListName;
		i++;
		
	}
	for (int j = 0; j < i; j++)
	{
		right.enqueueWaitList(temp[j]);
	}

	return *this;
}