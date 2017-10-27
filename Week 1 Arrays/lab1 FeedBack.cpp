// lab 1: This program creates a seating chart, sorts the student names, and provides a search for a name
// Written by: Davie Truong
// Date : April 9, 2015

// include the appropriate header files
#include<fstream>
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

const int ROW = 3;
const int COL = 4;
const int MAX = ROW*COL;
int foundRow = 0;                    /////////////////// do not use global variables
int foundCol = 0;


bool readFile(string arr[][COL]);
void print(string arr[][COL]);
void search(string arr[][COL]);
void sort(string arr[][COL]);
void insertionSort(string temparray[]);
bool binarySearch(string arr[][COL], string target, int row, int col);


int main()
{
	// create an array of strings called arr that is ROW x COL size
    string arr[ROW][COL];
	if (!readFile(arr))		// read names into the array
		return 1;
	cout << "Original seating chart:\n";
	print(arr);				// print the seating chart
	sort(arr);				// sort the names
	cout << endl;
	cout << "Reverse sorted names:\n";
	print(arr);
	search(arr);			// search for a name
	return 0;
}

// readFile: read all the names from file lab1.txt
// input: 2D array
// return: false if file can't be opened
//		   true if names are read in
bool readFile(string arr[][COL])
{
    ifstream in;
    in.open("lab1.txt");
    if(!in)
        {
        cout << "Error Openning the file \n";
        return false;
        }
    for(int s=0; s < ROW; s++)  //traverse through the rows
        {
            for(int i=0; i<COL; i++)    //traverse through the columns
                {
                getline(in, arr[s][i]);    //gets the name and puts it in the array
                }
        }
        in.close();
        return true;
}

// print: prints the 2D array as a ROW x COl matrix
//		  the names should be lined up in column format
// input: array
// return: nothing
void print(string arr[][COL])
{
        for(int s=0; s < ROW; s++)  //traverse through the rows
        {
            for(int i=0; i<COL; i++)    //traverse through the columns
            {
            cout << left << setw(13) << arr[s][i]; //prints the names according to the columns and rows
            }
            cout << endl;
        }
}


// sort: copy the 2D array into a 1D array, call the insertionSort function to sort the 1D array
//		 copy the 1D array back to the 2D array
// insert: 2D array
// return: nothing
void sort(string arr[][COL])
{
        int SIZE=0;
        int l=0;
        string temparray[MAX];

        for(int s=0; s < ROW; s++)  //traverse through the rows
        {
            for(int i=0; i<COL; i++)    //traverse through the columns
            {
               temparray[SIZE] = arr[s][i]; // sends that value of the 2D array into the 1D array
               SIZE++;  //increments the index of the 1D array
            }
        }

insertionSort(temparray);        ///////////// indent this


            for(int j=0; j < ROW; j++)  //traverse through the rows
            {
                for(int p=0; p < COL; p++)    //traverse through the columns
                {

                    arr[j][p] = temparray[l];   //sends data from the indexes of temparray to arr indexes while going through each loop to change the index location
                    l++;
                }
            }

}

// insertionSort: use the insertion sort algorithm to do a reverse alphabetical sort of the names
// input: array
// return: nothing
void insertionSort(string temparray[])
{
	int current = 1;				// start at index 1
	int last = MAX - 1;				// last index
    string temp;						// storage for current element
	int walker;						// index to walk and compare

	while (current <= last)
	{
		temp = temparray[current];		// copy current element to temp
		walker = current - 1;		// start walking from element in front of current
        while (walker >= 0			// not past front of array yet
			&& temp > temparray[walker])	// and current element > element in front
		{
			temparray[walker+1] = temparray[walker];  // shift element in front to the right
			walker = walker - 1;    // walk to next element in front
		}
		// when loop stops
		temparray[walker+1] = temp;		// insert current element to the proper location in the array
		current = current + 1;		// get next element
	}
}


// search: loop to let the user keep searching for a name
//         call the binary search function
// input: array
// return nothing

void search(string arr[][COL])
{
	string target;
	int row = 0, col = 0;
	do
	{
		cout << "Enter name to search (none to finish): ";
		getline(cin, target);
		if (target != "none")
		{
			if (binarySearch(arr, target, row, col))
                {
                row= foundRow;
                col= foundCol;
				cout << target << " is at row " << row+1 << " column " << col+1 << endl;
                }
			else
				cout << "There's no " << target << " in the class\n";
		}
	} while (target != "none");
}

// binarySearch: uses the binary search algorithm to find a name in the array
// input: array, target, found row, found col
// return: true for found
//         false for not found

bool binarySearch(string arr[][COL], string target, int row, int col)    //////////// need to pass by reference row and col so the search function can get
																		///////////// get the change in value         -1pt
{

        int first = 0;
        int last = MAX-1;
        int mid = 0;
		//position = -1;    //MYSTERY
		bool found = false;			// not found yet

		////////////// remove this prompt and data reading.  They should be done (and are already done) in the search function    -1pt
		////////////// The user shouldn't have to enter a name twice
	cout << "Target: "; //asked the user for the person they are looking for
	getline(cin,target);    //reads that data in from what the person typed into target

	while (!found && first <= last) //while found is false and the value of the first index is less than or equal to last do...
	{
        mid = (first+last)/2;
        row = mid / COL;
        col = mid % COL;
		if (arr[row][col] == target)    //compares the value of the target with the value of the array at the given index
		{
			cout << "found at index " << mid << endl;       /////////// remove debugging print
			foundRow = row;
			foundCol = col;
			found = true;
			return true;
		}
		else if (arr[row][col] > target)
			first = mid + 1;
		else
			last = mid - 1;
	}
	if (!found)
    {
 		cout << "Not found\n";      //////////////// remove debugging print
 		return false;
    }
}


