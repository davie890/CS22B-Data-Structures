// This program demonstrates pointers for a single variable
// and for an array

#include <iostream>
using namespace std;

const int MAX = 10;

void display(int * p);
void zero(int * ptr, int startIndex, int endIndex);


int main()
{
	//////////// Part 1: pointer to a single variable /////////
	int x = 25;

	cout << "The address of x is " <<  &x  << endl; //cout the adress
	cout << "The value of x is " << x << endl;  // cout the value

	// create a variable xPtr to store the address of x
	// then print the variable xPtr

    int * xPtr; //int * means adress of an integer
    xPtr = &x;  //the adress of x is stored in xptr
	cout << "The value of xPtr is " <<   xPtr  << endl; //cout the adress

	// change the value of x to 10 by using xPtr
	// print the value of x, using xPtr to see the change
	// x = 10;   easiest way to get to x

    *xPtr = 10; // changes the value of xPtr to 10
	cout << "The value in x is " <<  *xPtr  << endl;    //cout the value

	// Create a new integer y
	// Create a new yPtr variable that points to y
	// Assign -3 to y, using yPtr
	// Print the value of y, using yPtr

	int y;
    int * yPtr = &y;    //creates the pointer yPtr and stores the adress of y into yPtr
    *yPtr = -3;
	cout << "The value in y is " <<  *yPtr   << endl;

	// Using only xPtr and yPtr, do the multiplication: x = x * y
	// Print the x value, using xPtr

    *xPtr = *xPtr * *yPtr;
	cout << "The value in x is " <<  *xPtr   << endl;


	//////////// Part 2 /////////////////
	int nums[MAX] = {10,20,30,40,50,60,70,80,90,100};

	// Create a pointer variable p to point to nums
	int * p = nums; //nums is data type int *
                    //p is data type int *

	// Using nums and indexing, print the 2nd element
	cout << "Print 2nd elem using array name and indexing: " << nums[1] << endl;

	// Using p and indexing, print the 2nd element
	cout << "Print 2nd elem using p and indexing: " << p[1]  << endl;
	            //the [] is the same as the * dereferencing operator

	// Using p and pointer arithmetic, print the 4th elem
	cout << "Print 4th elem using pointer arithmetic: " << *(p+3) << endl;
                                                        //p[3]

	// Set p to point to the 5th elem
	// print the to see that it's at 50

    p = p + 4;      //or p += 4;
	cout << "Print 50 by moving p to 50: " <<  *p  << endl;

	// Set p back to the beginning of the array
	// and call the display function to display the array

    p = nums; // or p = p - 4;
	display(p);

	// Call a function named zero, pass to it the array
	// and the indexes 2 and 8
	zero(p, 2, 8);

	// Call the display function to display nums
	display(p);

    //////////ptr is a pointer to an array of integers
    //////////zero is a function that zeros out parts of the array
	// Would the zero function work if we pass a const ptr?
            // void zero(int * const p) yes because the data type doesnt have a const

	// Would the zero function work if we pass a ptr to const?
            //void zero(const int * p)  no

	// Would the zero function work if we pass a const ptr to const?
            //  void zero(const int * const p)  no

	return 0;
}

// Write a function, display, that accepts a pointer to an array
// and uses pointer arithmetic to display all elements of the array
void display(int * ptr)
{
    for (int i = 0; i < MAX; i++)
    {
        //cout << ptr[i]; this is possible but is not as requested
        cout << *(ptr+i) << " ";
    }
	cout << endl;
}

void zero(int * ptr, int startIndex, int endIndex)
{
    int * startptr = ptr + startIndex;
    int * endptr = ptr + endIndex;
    for(startptr; startptr <= endptr; startptr++)
        {
            *startptr = 0;
        }

}
