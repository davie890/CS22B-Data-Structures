//Davie Truong
// 5/21/2015
//Store.h header file for the store class

#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
#include "Item.h"

using namespace std;

class Store
{
private:
	int count;
	Item * inventory;	//dynamically allocated array of items

public:
	Store();														//sets default values and reads in the file data
	int getCount(){ return count; }									//gets the count 
	void print();													// wil have a loop that calls the print function from item class
	void transaction();												//prints the reciept and adds the running total
	int search(string userInput);									//checks if the item is available
	double sellItem(vector<Item> & v, int index, Item purchase);	//updates items in the inventory
	~Store();														//destroys allocated memory
};

#endif