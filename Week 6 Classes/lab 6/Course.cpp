// Lab 6:  functions for the course header file
// Name:	Davie Truong
// Date:	5/28/2015

#include "Course.h"

Course::Course()	//default constructor
{
	name = "none";
	maxStudents = 0;
	numStudents = 0;
	names = nullptr;
	
}

//constructor for 4 values with names being a vector
Course::Course(string name, int maxStudents, int numStudents, vector <string> names)
{
	//stores the inputed data into the current course object we are in
	this->name = name;
	this->maxStudents = maxStudents;
	this->numStudents = numStudents;
	this->names = new string[maxStudents];	//create a dyn array of strings

	//send the names of students from vector into the arrray names 
	for (int i = 0; i < numStudents; i++)
	{
		this->names[i] = names[i];
	}
}

//constructor for filenames
Course::Course(string fileName)
{
	int count = 0;
	string tempString = "";

	ifstream in;
	in.open(fileName);
	if (!in)
	{
		cout << "Error opening file." << endl;
		cout << "creating object with default values" << endl;
		
		name = "none";
		maxStudents = 0;
		numStudents = 0;
		
	}
	else
	{
		getline(in, name);
		in >> maxStudents;
		in.ignore(256, '\n');
		this->names = new string[maxStudents];	//create a dyn array of strings
		while (getline(in, tempString))
		{
		names[count] = tempString;	//stores the names from temp strings into the array
		count++;					//increments the count to figure out the number of students
		}
		numStudents = count; 
	}
	in.close();
}

//overloads the << operator so user can cout the course object
ostream & operator<< (ostream & ostr, const Course & object)
{
	ostr << object.name << ": max students = " << object.maxStudents <<
		", number of students = " << object.numStudents << endl; 
	for (int i = 0; i < object.numStudents; i++)
	{
		ostr << "  " << object.names[i] << endl;
	}
	cout << endl;
	return ostr;
}
Course Course::operator+= (string right)
{	
	if (names == nullptr)
	{
		cout << "Class Name: ";
		getline(cin,this->name);
		cout << "Max number of students: ";
		cin >> this->maxStudents;
		this->names = new string[maxStudents];
	}
	if (numStudents == maxStudents)	//checks to see if there is space 
	{
		cout << "No More Room to Add" << endl;
	}
	else//adds the student into the array
	{
		//adds names to the array
		names[numStudents] = right;
		numStudents++;
		cout << "Add Success" << endl;
	}
	return *this;	//returns the object 
}
//delete names from the array
Course Course::operator-= (string right)
{
	int index = 0; 
	bool found = false;

	//loop used to find the index of the name we are trying to remove
	for (int i = 0; i < numStudents && !found; i++)
	{
		if (names[i] == right)
		{
			index = i;
			found = true;
		}
	}	
	//If the name matches with one in the array we go through this loop to overwrite the data 
	//and to remove the student at the same time
	if (found)
	{
		for (int i = index; i < numStudents - 1; i++)
		{
			names[i] = names[i + 1];	//starting from where we want to remove the student 
										//overWrite it with every element right of it
		}
		numStudents--;		//remove the number of students because we jsut deleted one
	}
	else
	{
		cout << right << " Is not in the class" << endl;
	}
		return *this;
}

//deep copies the object upon creation
Course::Course(const Course & right)
{
	this->name = right.name;
	this->maxStudents = right.maxStudents;
	this->numStudents = right.numStudents;

		names = new string[maxStudents];
	for (int i = 0; i < numStudents; i++)
	{
		this->names[i] = right.names[i];
	}
}

//deep copies the object that is already created
Course Course::operator= (const Course & right)
{
	this->name = right.name;
	this->maxStudents = right.maxStudents;
	this->numStudents = right.numStudents;
	
	if (names)		//check to see if names is pointing to an array or not
	{
		delete[] names;	//delete existing array
	}
	names = new string[maxStudents]; //create new arry
	for (int i = 0; i < numStudents; i++)
	{
		this->names[i] = right.names[i];
	}
	return *this;
}

//concatinates 2 course objects together 
Course Course::operator+ (const Course & right)
{
	Course temp;	//creates new objects to store the contatination data
	int count = 0;
	temp.name = this->name + "_" + right.name;
	temp.maxStudents = this->maxStudents + right.maxStudents;
	temp.numStudents = this->numStudents + right.numStudents;

	temp.names = new string[temp.maxStudents];	//creates new array of strings for temp

	for (int i = 0; i < this->numStudents; i++)
	{
		temp.names[i] = this->names[i];	//stores left side data to the new array
		count++;	//keeps count to know where temp.names array was left off
	}
	for (int i = 0; i < right.numStudents; i++)
	{
		temp.names[count + i] = right.names[i];	//stores right side data to the new array
	}
	return temp;
}
