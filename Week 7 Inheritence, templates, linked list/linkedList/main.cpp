// This program demonstrates the linked list template.
#include <iostream>
#include "LinkedList.h"
#include "Distance.h"
using namespace std;

int main()
{
	

	LinkedList<int> list;  //constructor of linked list

	list.insertNode(1);    // insertNode of linked list, allocate mem for listNode
	list.insertNode(6);
	list.insertNode(3);
	list.insertNode(4);

	cout << "Initial list:\n";
	list.displayList();

	cout << "Deleting 3\n";
	list.deleteNode(3);  // deleteNOde of linked list, release mem for listNode
	cout << "Updated list:\n";
	list.displayList();
	
	/*
	LinkedList<Distance> list;   // define a list of Distance objects

	Distance d3(8, 9);		// 8 feet 9 inches
	Distance d1(5, 4);		// 5 feet 4 inches
	Distance d2(6, 8);		// 6 feet 8 inches

	list.insertNode(d1);		
	list.insertNode(d2);		
	list.insertNode(d3);		

	cout << "List:\n";
	list.displayList();
	cout << endl;

	cout << "Inserting the value 7 feet 2 inches.\n";
	Distance d4(7, 2);
	list.insertNode(d4);

	cout << "Updated list:\n";
	list.displayList();
	cout << endl;
	
	cout << "Deleting the last node.\n";
	Distance d5(8, 9);
	list.deleteNode(d5);
	
	cout << "Updated list:\n";
	list.displayList();
	


	*/
	return 0;
}