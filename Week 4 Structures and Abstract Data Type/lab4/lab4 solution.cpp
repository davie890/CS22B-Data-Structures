//
//  Lab4.cpp
//  Lab 4 Spring 2015
//
//  Created by Ibrahim Elsakka on 4/30/15.
//  Copyright (c) 2015 Ibrahim Elsakka. All rights reserved.
//  Lab 4: This program lets users buy items from a store

// struct InStore that can have string Name of product, int number of product in store, double price, bool if count is 0, then don't show on product list
// struct Inventory with pointer to ^structure, and count to see how many different items are in the store

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct InStore
{
    string name;
    int num;
    double price;
    bool count;
};

struct Inventory
{
    InStore *ptr;
    int numItems;
};

bool readFile(Inventory &instore);
void transaction (Inventory &instore, string name);              ///////// pass struct by reference    -1/2pt
void product(InStore *array, int count);
bool search(InStore *array, string answer, int count, int &index);
void processing(Inventory &instore, int index, double &total, vector<InStore> &receipt, string name);     ///////// pass struct by reference
void printReceipt(vector<InStore> receipt, double total, string name); 


int main()
{
    Inventory instore;
    string name;
    cout << "Welcome to the Apple Store!" << endl;
    cout << "What's your name?" << endl;   /////////// user friendly.  Is that what they do at the Apple Store?
    getline(cin, name);
    if (readFile(instore)) ///////////// catch return value and end main if file open fails   -1/2pt
    {
        product(instore.ptr, instore.numItems);
        transaction(instore, name);
    }
    delete [] instore.ptr;
    return 0;
}

//////////// good documentation

// readFile to read in data from an input file and fill the inventory array
// Read in my input file
// Check for file open success
// Count number of lines to know how many products are sold, fields are separated by comma
// Dynamically allocate memory depending on the number of elements in the inventory array
// Use a while loop to fill the InStore structure array
// Use the information to fill the Inventory structure array

// This function reads input from a file and stores it in a structure
bool readFile(Inventory &instore)
{
    unsigned long pos1 = 0, posStart = 0;
    string tempString;
    ifstream in;
    in.open("lab4.txt");
    if (!in)
    {
        cout << "Error opening file." << endl;
        return false;
    }

	
    instore.numItems = 0;     ////////// initialize numItems to 0, otherwise you're counting up from garbage data    -1pt
    while (getline(in, tempString))
        instore.numItems++;
    in.clear();                                                                                 // Resets file pointer to beginning
    in.seekg(0, ios::beg);
    instore.ptr = new InStore[instore.numItems];
    for (int i = 0; i < instore.numItems; i++)
    {
        getline(in, tempString);                                                                // Read from where the pointer is
        pos1 =  tempString.find(",", posStart);                                                 // Starting from posStart (0) find a comma
        (instore.ptr + i)->name = tempString.substr(posStart, pos1 - posStart);                 // Using name of data type InStore being assigned the information up to the first comma
        pos1++;
        posStart = pos1;
        pos1 = tempString.find(",", posStart);
        (instore.ptr + i)->num = atoi(tempString.substr(posStart, pos1 - posStart).data());
        pos1++;
        posStart = pos1;
        pos1 = tempString.find(",", posStart);
        (instore.ptr + i)->price = atof(tempString.substr(posStart, pos1 - posStart).data());
        if((instore.ptr + i)->num > 0)
            (instore.ptr + i)->count = true;
        else (instore.ptr + i)->count = false;
        pos1 = 0, posStart = 0;
    }
    
    return true;
}

// transaction function
// create a vector called receipt that can hold store Item structures
// do while Loop until the user enters "done"
// Print the name and price of each item that has a count > 0 and print in column format with setw
// Print the count for the item afterwards
// do while loop to prompt them to enter a valid number of items they want
// Use a variable to store the total cost
// Create a new structure to store the name, number, and price of items the user purchased
// Add the structure to the receipt vector
// After loop ends, print Items in the receipt vector and total cost as well as a farewell message

//This function processes user input for purchases
void transaction (Inventory instore, string name)
{
    vector<InStore> receipt;
    string answer;
    int index = 0;
    double total = 0;
    bool success;
    do
    {
        cout << "Enter the name of an item or done to finish" << endl;
        getline(cin, answer);
        if (answer == "done")
        {
            printReceipt(receipt, total, name);
            return;
        }
        success = search(instore.ptr, answer, instore.numItems, index);
        if (success == false)
        {
            cout << "Item could not be found." << endl;
        }
        else     /////////// no need for another if, use else      -1/4pt
        {
            processing(instore, index, total, receipt, name);
        }

        index = 0;
        
    } while (answer != "done");
}

// This function searches for the item specified by the user
bool search(InStore *array, string answer, int count, int &index)
{

    for (index = 0; index < count; index++)
    {
        if (answer == (array+index)->name)          // If their answer is found in the structure
            return true;
    }
    
    return false;
}

// This function asks how many items the user wants to purchase of the specified name, and stores the data into a temporary structure then in a vector called receipt
void processing(Inventory instore, int index, double &total, vector<InStore> &receipt, string name)
{
    int num = 0;
    do
    {
        //Create temporary structure and store it in the receipt vector
        InStore tempStruct;
        if ((instore.ptr + index)->num > 0)
        {
            cout << "We have " << (instore.ptr + index)->num << " of them" << endl;            ////////// indent this true block of the if statement
            cout << "How many do you want to buy?" << endl;
            cin >> num;
            cin.ignore();
            while (((num > (instore.ptr + index)->num || num < 0) && (instore.ptr + index)->count == true))
                {
                    cout << "We have " << (instore.ptr + index)->num << " of them" << endl;
                    cout << "How many do you want to buy?" << endl;

{
	int userAmount;                     cin >> num;
                    cin.ignore();
                }
            if (num != 0)           //////////// only do this processing if num != 0, lab requirement is not to print 0 item purchase   -1pt
            {
                total += ((num) * ((instore.ptr + index)->price));
                tempStruct.name = (instore.ptr + index)->name;
                tempStruct.num = num;
                tempStruct.price = (instore.ptr + index)->price;
                tempStruct.count = (instore.ptr + index)->count;
                receipt.push_back(tempStruct);
                //////////// this block belongs with the processing block above, where tempStruct is created   -1/4pt
                (instore.ptr + index)->num -= num;
                if ((instore.ptr + index)->num == 0)
                    (instore.ptr + index)->count = false;
            }
        }
        else (cout << (instore.ptr + index)->name) << " is not available." << endl;

        
        product(instore.ptr, instore.numItems);
    } while (((instore.ptr + index)->num < 0) && num >0);
}

// This function prints the available products and their prices
void product(InStore *array, int count)
{
    cout << left << setw(15) << "Items"
         << right << setw(10) << "Price" << endl;
    for (int i = 0; i < count; i++)
    {
        if ((array +i)->count == true)
        {
        cout << left  << setw(15) << (array + i)->name;
        cout << right << setw(10) << (array + i)->price << endl;
        }
    }
}

// This function prints the receipt of the user purchase
void printReceipt(vector<InStore> receipt, double total, string name)
{
    cout << "Your receipt:" << endl;
    for (int i = 0; i < receipt.size(); i++)
    {
        cout << left << setw(15) << receipt[i].name
             << receipt[i].num << " at "
             << right << setw(10) << receipt[i].price << endl;
    }
    cout << "Your total is $";
    cout << setprecision(2) << fixed << total << endl;
    cout << "Welcome to the Apple Family, " << name << "!" << endl;
}