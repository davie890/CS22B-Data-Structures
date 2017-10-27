// This program works with dynamically allocated memory

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int * createArr(int & numscores);
void display(int arr[], int numscores);

int main()
{
	// Part 1: allocate memory for a single variable
	// Dynamically allocate memory for a double and initialize it with the
	// normal human body temperature

	//another way of doing it
	/*
    double * tempPtr = new double;
    *tempPtr = 98.6;
    */

    double * tempPtr = new double(98.6);

	// Print the normal body temperature
	cout << "Normal temp: " <<   *tempPtr  << endl;

	// change the temperature to 99.5 and print

	*tempPtr = 99.5;
	cout << "Fever temp: " << *tempPtr << endl;

	// Release the memory
	delete tempPtr;

	// Part 2: allocate memory for an array
	// Create a pointer to an array of integers called pScores

    int * pScores;
	int numscores;

	// call the function createArr to create the array from the
	// scores in a text file. The function returns the array and
	// pass back the number of scores
	pScores = createArr(numscores);

	// call the display function to print the all the scores
	//if createArr is successful
	if (pScores)    //if pScores is 0, don't do anything
	{               //if pScores is an adress, then call display
		display(pScores, numscores);
    }
	// what's the last step before returning from main?
    delete [] pScores;  //use [] to tell delete to clear out the entire array
                        //without square bracket delete will clear out only the first element
                        //because pScores is the adress of the first element

	return 0;
}

// write a function called createArr to open the file scores.txt,
// if successful, count the number of lines (scores) in the file,
//                allocate memory for an exact size array,
//                read in from the file to fill the array,
//                then return the array
// if not successful, return 0
int * createArr(int &numScores)
{
// open file and check for success
	ifstream infile;
	infile.open("scores.txt");
	if (!infile)
	{
		cout << "Error opening file\n";
		return 0;   // fail to open, return 0
	}

	// read from file and count how many scores
	int count = 0;
    int score;
    while(infile >> score)
        {
        count++;
        }

    numScores = count;
	// create an array of the exact size to store the scores
    int * arr = new int[count];

	// reset file pointer to beginning of file
	infile.clear();
	infile.seekg(0, ios::beg);

	// walk the array and store data
	for (int i = 0; i < count; i++)
	{
		//infile >> arr[i];
		infile >> *(arr + i);
	}

	// last step before return array?
    infile.close();

	// return array
	return arr; //actually returning the adress
}

// write a function called display to print the scores in the array
void display(int arr[], int numscores)
{
	for (int i = 0; i < numscores; i++)
		cout << arr[i] << " ";
	cout << endl;
}
