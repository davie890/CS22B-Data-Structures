// lab 4:  Write a program that lets a user buy items from a store
// Written by:  Davie Truong
// Date:    April 30, 2015

#include<iostream>  //standard input output
#include<cstring>   //library for c string
#include<string>    //library for c++ strings
#include<fstream>   //used to work with files
#include<vector>	//used for vectors
#include<iomanip>	//used to setw

using namespace std;

struct Item
{
	string name;
	int num;
	double price;
	bool itemCheck;
};

struct Store
{
	Item * ptr;
	int itemCount;
};

void readFile(Store &);
void transaction(Store &shop);
bool search(Store shop, string itemchoice, int &index);
void productlist(Store &shop);
void finalReceipt(vector<Item> receipt, double total);
void calculation(Store shop, int index, double &total, vector<Item> &receipt);

int main()
{
	Store shop;
	//print a message to welcome the user to the store
	cout << "*****************************" << endl;
	cout << " Welcome To The General Store " << endl;
	cout << "*****************************" << endl << endl;

	//call a readFile function to read in data from an input file and fill the inventory array
	readFile(shop);
	//displays what the shop has to offer
	productlist(shop);
	//call a trasaction function to let the user purchase items from the store
	transaction(shop);
	//remove dyn memory
	delete[] shop.ptr;
	return 0;
}


/*

Open the file lab4.txt and count the number of lines.
Each line is the name, count, and price of an item that the store sells, and the 3 fields are separated by comma.
Dynamically allocate the inventory array so it is the same size as the number of items in the input file.
Loop to fill the inventory array.
The name, count, and price in each line of the input file should be stored in one element of the inventory array.

*/
void readFile(Store &shop)		
{
	string linesOfTxt;
	int lineCount = 0;

	unsigned long pos1 = 0, posStart = 0;

	ifstream in;
	in.open("lab4.txt");
	//checks for file open sucesss 
	if (!in)
	{
		cout << "Error Openning the file \n";
		return;
	}

	//used to find the amount of unique items in txt 
	while (getline(in, linesOfTxt))
	{
		lineCount++;
	}

	shop.itemCount = lineCount;

//sets the the pointer for the index at 0
in.clear();
in.seekg(0, ios::beg);

shop.ptr = new Item[shop.itemCount];	//creates a pointer with dynam memory for inventory

for (int i = 0; i < lineCount; i++)	//loops through the amount of lines in the txt files
{
	getline(in, linesOfTxt);	// pulls the data from in and puts it into the string linesOfTxt
	// for further manipulation
	pos1 = linesOfTxt.find(",", posStart);
	(shop.ptr + i)->price = atof(linesOfTxt.substr(posStart, pos1 - posStart).data());	//same as above //atof to change from string to double

	if ((shop.ptr + i)->num > 0)				//derefence num to check if it is greater than 0
		(shop.ptr + i)->itemCheck = true;		//if num > 0 then assign count true
	else
	pos1 += 1;			//gives pos1 the next index location for the next search
	posStart = pos1;	//assigns the value of pos1 to posStart to change thexzt search
	//Inputs the cost of the product from linesOfTxt into the array price

/*
The transaction function:

Create a vector called receipt, ready to store Item structures
Loop until the user enters "done"
In the loop:
a. print the name and price of each item that has a non-zero count
Print in column format as shown in the sample output
b. keep prompting the user for an item to purchase until you get a valid item name
c. print the count for the item
d. keep prompting the user for the number of items to purchase until you get a valid number
e. process the purchase:
- create a new Item structure to store the name, the number, and the price of the item that the user purchased
- add the new Item structure to the receipt vector
When the loop ends, print the Items in the receipt vector and print the total cost
The receipt should be printed in column format as shown in the sample output

- reduce the item count in the inventory
The transaction function involves a lot of steps so it's your job to break it down into smaller functions that the transaction function can call.
Some example sub-functions are: a print functio
- calculate the total cost as a running sum (keep adding to the sum with every item purchased)n, a search function, a process purchase function, a print receipt function
*/

void transaction(Store &shop)
{
	vector<Item> receipt;	//creates the vector for reciept
	string itemchoice;
	int itemamount;
	bool valid;
	double total = 0;
	int index = 0;

	do
	{
		cout << endl << "Enter the name of what you want to buy." << endl;
		cout << "Enter in: 'done' to finish" << endl;
		getline(cin, itemchoice);													//gets in what the user wants to buy 
		valid = search(shop, itemchoice, index);									//sends it to a function to return a bool to decide what to do next
		if (itemchoice == "done")													//if the user decides to stop prints out the receipt and exits
		{
			finalReceipt(receipt, total);
			return;
		}		
		
		if (valid == false)														
		{
			cout << "Item not available" << endl;
		}
		else if (valid)
		{
			calculation(shop, index, total, receipt);								//if the word is acceptable run though the calculation function
		}

		do 
		{
			cout << "item could not be found" << endl;
			cout << "Enter the name of what you want to buy." << endl;
			cout << "Enter in: 'done' to finish" << endl;
			getline(cin, itemchoice);
		} while (valid == false);												//if the word is not accaptable reprompts the user until it is correct

		index = 0;

	} while (itemchoice != "done");
}

bool search(Store shop, string itemchoice, int &index)			//checks to see if what the user enters is on the item list
{
	for (int index = 0; index < shop.itemCount; index++)
	{
		if (itemchoice == (shop.ptr + index)->name)
			return true;										//returns true or false for further manipulation
	}

	return false;
}


void productlist(Store &shop)									//prints out the items in the store and the cost
{
	cout << left << setw(16) << "Items" << right << setw(11) << "Price" << endl;	//sets with for item and price to look pretty
	for (int i = 0; i < shop.itemCount; i++)										//loops through the amount of items in the txt
	{
		if ((shop.ptr + i)->itemCheck == true)										//checks to see if there are items in the store
		{																			//uses previous setting
			cout << left << setw(16) << (shop.ptr + i)->name;						// prints the name of the item
			cout << right << setw(11) << (shop.ptr + i)->price << endl;				//prints the price of the item
		}
	}
}

void finalReceipt(vector<Item> receipt, double total)								//the final reciept for the customer to see their price
{
	cout << "Receipt" << endl;
	for (int i = 0; i < receipt.size(); i++)
	{
		cout << left << setw(15) << receipt[i].name << receipt[i].num << " at " <<		//couts the name depending on the index
			 right << setw(10) << receipt[i].price << endl;								//couts the price depending on the index
	}
	cout << "SubTotal: " << setprecision(2) << fixed << total << endl;					//prints out the total charge
}

void calculation(Store shop, int index, double &total, vector<Item> &receipt)
{
	int num = 0;
	do
	{
		Item tempStruct;																//creates a structer to store temp data for manipulation
		if ((shop.ptr + index)->num > 0)												//sets condition to occure when the number of item is > 0
		{
			cout << "We have " << (shop.ptr + index)->num << " of them" << endl;		//tells the user how much of the item we have
			cout << "How many do you want to buy?" << endl;
			cin >> num;
			cin.ignore();																//takes the user input 

			while (((num >(shop.ptr + index)->num || num < 0) && (shop.ptr + index)->itemCheck == true))	//checks to see if the user imput is valid
			{
				cout << "We have " << (shop.ptr + index)->num << " of them" << endl;
				cout << "How many do you want to buy?" << endl;
				cin >> num;
				cin.ignore();
				while (!(cin >> num))																	//setting to make sure the user enters the correct value
				{                                             
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input.  Try again: ";
				}
			}

			total += ((num)* ((shop.ptr + index)->price));								//sets the total to how much the user wants to buy and the price of the item
			tempStruct.name = (shop.ptr + index)->name;									//uses the temp struct to store what the user bought
			tempStruct.num = num;
			tempStruct.price = (shop.ptr + index)->price;
			tempStruct.itemCheck = (shop.ptr + index)->itemCheck;

			receipt.push_back(tempStruct);												//sends the information of the temp struct to receipt
		}
		else (cout << (shop.ptr + index)->name) << " is not available." << endl;		//tells the user the item is not available
		if ((shop.ptr + index)->num >= num)           
		{
		(shop.ptr + index)->num -= num;

			if ((shop.ptr + index)->num == 0)
			{
				(shop.ptr + index)->itemCheck = false;
			}
		}

		productlist(shop);
	} while (((shop.ptr + index)->num < 0) && num > 0);
}