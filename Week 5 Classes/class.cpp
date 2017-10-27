// This program works with a class

#include <iostream>
#include <string>
#include <iomanip>
#include "Food.h"
#include <vector>
using namespace std;


// Part 1: Declare a Food class with:
// + data:  name, number of ingredients, dynamically allocated array of ingredients
// + functions: 
//   - mutators to store name, number of ingredients and ingredients
//   - accessors for each member data 
//   - constructors: default, with name arg.
// Is a destructor needed? 

// Part 2: Implement the Food class


int main()
{
	string name;
	string * list;
	int num;

	/*
	// Part 3: instantiate a Food item and fill it with data from the user
	Food myFood;	////whenever a Food object is created(instantiated) the constructor runs

	// prompt and store name
	cout << "Name: ";
	getline(cin, name);  
	myFood.setName(name);	//setName is a function that changes the default value
	

	// prompt and store ingredients
	cout << "Num of ingredients: ";
	cin >> num; 
	cin.ignore();
	myFood.setNum(num);

	list = new string[num];
	for (int i = 0; i < num; i++)
	{
		cout << "Enter ingredient: ";
		getline(cin, list[i]);
	}
	myFood.setIngredients(list);

	// show food item's data
	cout << "Name: " << myFood.getName() << endl;
	cout << "Ingredients: ";

	for (int i = 0; i <  myFood.getNum()  ; i++)
	{
		cout << myFood.getIngredients(i) << endl;
	}



	// Create a food with default values, show the name and number of ingredients
	Food defaultFood;		//creating a default food pbject
							//no input argument needed

	cout << "Name: " << defaultFood.getName() << endl;
	cout << "Ingredients: ";

	for (int i = 0; i < defaultFood.getNum(); i++)
	{
		cout << defaultFood.getIngredients(i) << endl;
	}

	// Create a food called "french fries" with an ingredient list of "potatoes","oil","salt"
	// 1. create a vector for all the ingredientes 
	vector<string> v;
	v.push_back("potatoes");
	v.push_back("oil");
	v.push_back("salt");

	Food moreFood("french fries", v);	//create and initialize moreFood with my data
										//input argument is needed

	moreFood.print(); 



	//if main ends here, would there be a memory leak?
	//no memory leak if there is a destuctor written for the class
	*/

	// Part 4:
	// Create an array of 3 foods: pizza, chips, cupcake
	//first way is slower way:
	Food arr[3]; 
	arr[0].setname("pizza");
	arr[1].setname("chips");
	arr[2].setname("cupcakes"); 

	// which constructor runs?
	//default constructor ran on the first line

	//second way is faster if you know the data ahead of time
	//however this way doesn't work 
	//   Food arr3[3] = { "pizza", "chips", "cupcakes" };
	//because there is no constructor wirh 1 argument 
	// 2 ways to fix this:
	// 1. the user initialize with 2 arguments so that the compiler can find
	//	  a match using the constructorr with 2 arguments 
	// 2. the class provides a new constructor with 1 argument


	// Create an array of 2 dynamically allocated food: the first one has default name,
	//  and the second name is "salad"
	Food * arr2 = new Food[2];  // arr2 is created here with default constructor



	return 0;
} 