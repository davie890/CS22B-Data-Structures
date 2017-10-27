//Davie Truong
// 5/21/2015
//Item.cpp: impelentatation file for the Food Class

#include "Item.h"
#include "Store.h"

//default constructor to initialize data to a "safe" value
Item::Item()
{
	name = "none";
	count = 0;
	price = 0;
	show = false;
}

//pulls data from the input and seperates it to replace the default values
Item::Item(string input)
{
	int posStart = 0;
	int pos1 = 0;

	pos1 = input.find(",", posStart);
	name = input.substr(posStart, pos1 - posStart);
	pos1++;
	posStart = pos1;
	pos1 = input.find(",", posStart);
	count = atoi(input.substr(posStart, pos1 - posStart).data());
	pos1++;
	posStart = pos1;
	pos1 = input.find(",", posStart);
	price = atof(input.substr(posStart, pos1 - posStart).data());
	if (count > 0)
		show = true;
	else
		show = false;

}

//print function for the menu
void Item::print()
{

	if (show == true)
	{
		cout << left << setw(15) << name << right << setw(12)  << price << endl;
	}

}

//prints the reciept in desired format
void Item::printReciept()             ////////////// these 2 print functions should be combined into 1 print function. Use show to determine
										//////////// if the count should be printed or not      -1/2pt
{
	if (show == true)
	{
		cout << left << setw(12) << name << right << count << "   at " << setw(5) << price << endl;
	}

}

//compares the userinput with the name to check if we have the item
bool Item::isAvailable(string userInput)
{
	if (name == userInput && count > 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

double Item::sell(Item & i)
//sell function returns the total price for the one item the user bought 
{
	int userAmount = 0;

	if (count > 0 || cin.fail())
	{
		cin.clear();
		cout << "We have " << count << " of them" << endl;
		cout << "How many do you want to buy? ";
		cin >> userAmount;
		cout << endl;
		cin.ignore();

		while (((userAmount > count || userAmount < 0) && show == true) || cin.fail())
		{
			cin.clear();
			cout << "We have " << count << " of them" << endl;
			cout << "How many do you want to buy? ";
			cin >> userAmount;
			cout << endl;
			cin.ignore();
		}

		//adjust the count 
		count -= userAmount;
		if (count == 0)
		{
			show = false;
		}
		//assigning data to the refrence for use at store class 
		i.name = name;
		i.price = price;
		i.count = userAmount;
		i.show = true;
		return (price * userAmount);
		
	}
	return 0;

}