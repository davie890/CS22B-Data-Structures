//Davie Truong 
// 5/21/2015
//Store.cpp: implementation file for the Store CLass

#include "Store.h"
#include "Item.h"

//default constructor initializes all data to a "safe" value
Store::Store()
{
	//safe values
	count = 0;
	inventory = NULL;

	string tempString = "";
	ifstream in;
	in.open("lab4.txt");
	if (!in)
	{
		cout << "Error opening file." << endl;
	}
	else
	{
		while (getline(in, tempString))
			count++;								//determins how many lines are in the file
		in.clear();                                // Resets file pointer to beginning
		in.seekg(0, ios::beg);

		inventory = new Item[count];				//creates an array for the invetory
		int i = 0;

		//create for loop to send all lines to array of inventory
		while (getline(in, tempString))			//reads in the line to tempstring
		{
			inventory[i] = Item(tempString);		//send data from the temp string so that it can be alterered with each iteration
			i++;
		}
	}
	in.close();
}

//print function to print the items in the store
void Store::print()
{
	cout << "The Shick Shack" << endl << endl;
	cout << left << setw(15) << "Items" << right << setw(12) << "Price" << endl;

	for (int i = 0; i < count; i++)
	{
		inventory[i].print();
	}
	cout << endl;
}

//processes the sale transaction
void Store::transaction()
{
	Item purchase ; 
	//print();			//calls the print function to print the menu
	vector <Item> v;
	string userInput;
	int index = 0;
	double runningTotal = 0;

	do
	{
		print();	//calls the print function to print until the user enters done
		cout << "Enter item or done: ";
		getline(cin, userInput);
		if (userInput == "done")
		{
			cout << endl << "Your Receipt: " << endl;
			for (int i = 0; i < v.size(); i++)
			{
				 v[i].printReciept();		//calls the print reciept function for correct syntax
			}
			
			cout << endl<< "Your total is $";
			cout << setprecision(2) << fixed << runningTotal << endl;
			cout << "Thank You for your purchase" << endl;
			return;
		}
		index = search(userInput);	//checks for valid item name and returns the index 
		if (index >= 0)
		{
			runningTotal += sellItem(v, index, purchase);
		}
	} while (userInput != "done" );
}

//returns an index value of the item 
//also calls the isAvailable function to check if we have the item
int Store::search(string userInput)
{
	for (int i = 0; i < count; i++)
	{
		if (inventory[i].isAvailable(userInput))
			return i;
	}
	return -1;
}

//calls the sell function to update the item in the inventory
double Store::sellItem(vector<Item> & v, int index, Item purchase)
{
	double singlePrice = inventory[index].sell(purchase);
	if (singlePrice != 0)								
	{
	//adds the purchased item to the reciept vector
		v.push_back(purchase);
	}
	return singlePrice;
}

//destructor to delete allocated memory
Store::~Store()
{
	delete[] inventory;
}