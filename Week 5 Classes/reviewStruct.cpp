// This program is a review of structs

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


// Declare a Food structure
struct Food
{
	string name;
	int numIngredients;
	string * list;
};


int main()
{
	// Create a Food item and fill it with data from the user
	Food snack;

	// prompt and store name
	cout << "Name: ";
	getline(cin, snack.name);  

	// prompt and store ingredients
	cout << "Num of ingredients: ";
	cin >> snack.numIngredients; 
	cin.ignore();

	snack.list = new string[snack.numIngredients];
	for (int i = 0; i < snack.numIngredients; i++)
	{
		cout << "Enter ingredient: ";
		getline(cin, snack.list[i]);
	}

	// show food item's data
	cout << "Name: " <<  snack.name  << endl;
	cout << "Ingredients: ";

	for (int i = 0; i < snack.numIngredients; i++)
	{
		cout << snack.list[i] << " ";
	}
	cout << endl;

	// Create a food called "french fries" with an ingredient list of "potatoes","oil","salt"
	Food ff;
	ff.name = "French Fries";
	ff.numIngredients = 3;
	ff.list = new string[ff.numIngredients];
	ff.list[0] = "potatoes";
	ff.list[1] = "oil";
	ff.list[2] = "salt";

	//if main ends here, would there be a memory leak?
	//yes

	delete[] snack.list;
	delete[] ff.list;

	return 0;
} 