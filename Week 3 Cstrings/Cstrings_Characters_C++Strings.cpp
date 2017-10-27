// This program demonstrates characters, c strings, and c++ Strings
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
// explain these include files:
#include <cctype>     // library for character functions
#include <cstring>    // library for c strings
#include <string>     // library for c++ strings

using namespace std;

const int MAX = 81;   // max C string size, commonly used
					  // for input from keyboard because
					  // the traditional size of the screen
					  // is 80 characters wide

// what kind of functions are these?
bool validate(char input[]);    // input: array of chars or C string
bool validate(string input);    // input: C++ string
bool uppercase(char input[]);   // input C string
bool uppercase(string input[]);            //C++ string

int main()
{
	//////////// Part 1. C strings ////////////
	// define 3 C strings of MAX size called idC, nameC, titleC
char idC[MAX];
char nameC[MAX];
char titleC[MAX];

	cout << "C strings\n";
	do
	{
		cout << "Enter your student id: ";
		// read in 80 chars max
		cin >> idC;

	} while (!validate(idC));

	do
	{
		cout << "Enter your full name: ";
		// read in 80 chars max
		cin.getline(nameC, MAX);

	} while (!uppercase(nameC));

	do
	{
		cout << "Enter your title: ";
		// read in 80 chars max
		cin.getline(titleC, MAX);

	} while (!uppercase(titleC));

	// convert the idC string into a long data type called ID
    int num;
    num = atoi(idC);
	cout << "the ID as a number is " << num << endl;

	// allocate for the exact size of a C string, exactName,
	// that can hold the user name and fill the new C string with data
    char * exactName = new char [strlen(nameC)+1];//creates an array in the heap(after the program has started)
                                                    // +1 is extra room for the \0
    // exactName = nameC; //this means pointer exactName = pointer nameC
                            // or eactName poijnts to the same place as nameC
    ////to copy the slow ad painful way:
    //for(int i = 0; i < (strlen(nameC)))
    strcpy(exactName, nameC);
	cout << "exact aized name is: " << exactName << endl << endl;

	////////// C++ String class //////////
	string id, name, title;   // same data, but using C++ Strings

	cout << "\nC++ Strings\n";
	do
	{
		cout << "Enter your student id: ";
		// read in id

	} while (!validate(id));

	do
	{
		cout << "Enter your full name: ";
		// read in name

	} while (!uppercase(name));

	do
	{
		cout << "Enter your title: ";
		// read in title

	} while (!uppercase(title));

	// compare name and exactName and print them
	// in alphabetical order
	// If they're the same, then print only one copy

	// any last step that needs to be done?

	return 0;
}

// write the validate function that receives a C string
// as input argument, and returns true if the string has
// 8 characters and all the characters are digits.
// Print an error statement if there are not 8 characters.
// Print a different error statement indicating the first
// location of a character that's not a digit.
// Return false if there is an error.
bool validate(char id[])
{
    // 1. check if there are 8 characters
    if(strlen(id) != 8)
    {
        cout << "must be 8 characters" << endl;
        return false;
    }

    // 2. check that all characters are digits
    for(int i = 0; i < 8; i++)
    {
        if(!isdigit(id[i]))
        {
        cout << "Character " << i + 1 << "is not a digit" << endl;
        return false;
        }
    }
    return true;
}


// write the same validate function for a C++ string
// as input argument
bool validate (string id)
{
    // 1. check if there are 8 characters
    if(id.length() != 8)
    {
        cout << "must be 8 characters" << endl;
        return false;
    }

    // 2. check that all characters are digits
    for(int i = 0; i < 8; i++)
    {
        if(!isdigit(id[i]))
        {
        cout << "Character " << i + 1 << "is not a digit" << endl;
        return false;
        }
    }
    return true;
}

// write the uppercase function that receives a C string
// as input argument, and returns true if all characters
// are alphabet characters or - or . or space characters.
// The function also converts the first character of each
// word to uppercase, and converts subsequent characters
// to lowercase.
// If there is an invalid character, the function prints
// an error message indicating the position of the first
// invalid character, and returns false.
bool uppercase (char input[])
{
    // 1. Test for all calid characters
    for(unsigned int i = 0; i < strlen(input) ;i++)
    {
        if(!(isalpha(input[i]) || input[i] == '-' || input[i] == '.' || isspace(input[i])))
        {
            cout << "invalid Character at position " << i+1 << endl;
            return false;
        }

    }

    // 2. conver to correct case
    input[0] = toupper(input[0);    //always uppercase first char
    for(int i = 1; i < strlen(input); i++)  //loop from 2nd character
    {
        if(isspace(input[i]) || input[i] == '-')
        {
            input[i+1] = toupper(input[i+1]);   //convert to uppercase and overwite the old character
        }
        else
        {
            input[i+1] = tolower(input[i+1]);   //conver to lowercase and overwrite the old character
        }
    }
    return true;
}

// write the same uppercase function for a C++ String
// as input argument
bool uppercase(string input)
{
    // 1. Test for all calid characters
    for(int i = 0; i < input.length() ;i++)
    {
        if(!(isalpha(input[i]) || input[i] == '-' || input[i] == '.' || isspace(input[i])))
        {
            cout << "invalid Character at position " << i+1 << endl;
            return false;
        }

    }

    // 2. conver to correct case
    input[0] = toupper(input[0);    //always uppercase first char
    for(int i = 1; i < input.length(); i++)  //loop from 2nd character
    {
        if(isspace(input[i]) || input[i] == '-')
        {
            input[i+1] = toupper(input[i+1]);   //convert to uppercase and overwite the old character
        }
        else
        {
            input[i+1] = tolower(input[i+1]);   //conver to lowercase and overwrite the old character
        }
    }
}
