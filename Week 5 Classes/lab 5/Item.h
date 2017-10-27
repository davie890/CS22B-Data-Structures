//Davie Truong
// 5/21/2015
//Item.h header file for the Item class

#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using namespace std;

class Item
{
private:
	string name;
	int count;
	double price;
	bool show;


public:
	//constructor
	Item();								//used to store safe values
	Item(string input);					//changes the defualt value
	void print();						//prints the menu
	void printReciept();				//prints reciept
	bool isAvailable(string userInput);	//checks if the item is avaialable
	double sell(Item & i);				//determins how much the user wants to buy
};

#endif