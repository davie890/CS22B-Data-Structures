// This program demonstrates function templates
#include <iostream>
#include <iomanip>
using namespace std;


template <class T>
T square (T num)
{
	return num * num;
}


template <class T>
T add (T n1, T n2)
{
	return n1 + n2;
}

template <class T>
T add (T n1, T n2, T n3)
{
	return n1 + n2 + n3;
}

template <class T1, class T2>
void size(const T1 var1, const T2 var2)
{
	cout << "size of argument 1 is " << sizeof(var1) << " bytes\n";
	cout << "size of argument 2 is " << sizeof(var2) << " bytes\n";
}

//int square(int n)
//{
//	return n * n;
//}

int main()
{
	/*
	///////////////// part 1: function template /////////////
	int int1;        
	double float1; 

	cout << fixed << setprecision(2);
	cout << "Enter an int and a float: ";
	cin >> int1 >> float1;
	cout << "Here are their squares: ";
	cout << square(int1) << " and " << square(float1) << endl;    // is there a problem with the output?
	*/

	
	//////////////////  part 2 overloading function template  //////////
	int int1 = 1, int2 = 2, int3 = 3, sumI;
	double float1 = 1.1, float2 = 2.2, float3 = 3.3, sumF;

	sumI = add(int1, int2);				// which add function runs?
	sumF = add(float1, float2);			// which add function runs?
	cout << "sum of ints: " << sumI << "\nsum of doubles: " << sumF << endl;
	
	sumI = add (int1, int2, int3);			// which add function runs?
	sumF = add(float1, float2, float3);		// which add function runs?
	cout << "sum of ints: " << sumI << "\nsum of doubles: " << sumF << endl;
	

	/*
	//////////////////  part 3 function template with multiple data types //////////
	int int1 = 1;
	double float1 = 1.1;

	size(int1, float1);
	//size(int1, int1);               // does this work?
	*/

	return 0;
}