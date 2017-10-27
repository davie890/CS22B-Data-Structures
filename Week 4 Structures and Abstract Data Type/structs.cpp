// This program demonstrates structs

#include <iostream>
#include <string>

using namespace std;

//struct declaration, this is the blue print and doesn't take up sapce in memory
struct Contact      //contact must come first
{
	string email;
	string phone;
};

struct Employee         //because the compiler has to "see" the contact declation
{                       //before it gets here
    string name;
    Contact contactInfo;
    double pay;
};


int main()
{
/*
	///////// Part 1: structs ///////////
	// define and initialize a myContact struct
    Contact myContact = {"deanza.edu", "1234"};

	// define a yourContact
    Contact yourContact;

	// store data into yourContact: the fastest way is to copy from myContact to yourContact
    yourContact.email = myContact.email;
    yourContact.phone = myContact.phone;

    //or a faster way:
    yourContact = myContact;    //can only do this if there is no dynamic memory in the struct

	// print myContact
    cout << "Email: " << myContact.email << " Phone: " << myContact.phone << endl;
*/


	///////// Part 2: nested structs and array of structs  ///////////////
	// create a new struct called Employee with:
	// name, Contact, pay
	//It is above main

	// create a newEmployee struct and initialize with a name and email
	// Is this possible?
	Employee newEmployee = {"e1", "deanza.edu"};

    cout << newEmployee.name << endl;
    cout << newEmployee.contactInfo.email << endl;
    cout << newEmployee.contactInfo.phone << endl;
    cout << newEmployee.pay << endl;

	// Is it possible to initialize with name, email, and salary?
   // Employee newEmployee2 = {"e2", "deanza.edu", , 12.50};    //cannot skip fields during initializaion


	// create an array of 3 Employees, initialize with 3 names
	// and 3 email addresses.  Is this possible?
    Employee arr[3] = {{"e1", "m1"}, {"e2", "m2"}, {"e3", "m13"}};


	// print the names and addresses
    for(int i = 1; i < 3; i++)
    {
        cout << arr[i].name << " " << arr[i].contactInfo.email << endl;
    }


	///////// Part 3: struct with pointers and functions ///////////
	// create a dynamically allocated employee struct
    Employee * ptr = new Employee;


	// store "new employee" for name, 1000 for salary, 1234 for phone
    (*ptr).name = "new employee";
    (*ptr).pay = 1000;
    (*ptr).contactInfo.phone = "1234";


	// call the print function to print the name, phone and salary
    print(ptr);


	// give the employee a 50% raise, and print the new yearly salary
    ptr->pay = ptr->pay * 1.5;
    cout << ptr->pay;

	// last step?
    delete ptr;

	return 0;
}

void print(Employee * ptr)
{
    cout << ptr->name << " " << ptr->contactInfo.phone << endl;
}




