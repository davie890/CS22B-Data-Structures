// lab 5: Simulate an online store with objects
// Written by: Davie Truong
// Date: 5/21/2015

#include <iostream>
#include <string>
#include "Item.h"
#include "Store.h"

using namespace std;

int main()
{
	Store myStore;
	if (myStore.getCount() == 0)
	{
		cout << "Error reading data\n";
		return 1;
	}
	myStore.transaction();
	return 0;
}
