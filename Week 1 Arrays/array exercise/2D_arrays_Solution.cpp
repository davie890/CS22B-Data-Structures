// This program calculates the average gpas of students

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


const int NUM_STUDENTS = 12;		// Number of students
const int NUM_QTRS = 4;				// Number of quarters

bool fillArr(double gpa[][NUM_QTRS]);
void averaging(double gpa[][NUM_QTRS]);

int main()
{
	double gpa[NUM_STUDENTS][NUM_QTRS]; // Array for 12 students, each with 4 quarters						
	
	// read from file and fill array with students gpas
	if (!fillArr(gpa))
		return 1;

	// print student5's gpa for quarter 2
	cout << "Student 5, quarter 2: " << gpa[4][1] << endl;

	// print all the gpas of student10
	cout << fixed << setprecision(2);
	cout << "GPAs for student10\n";
	for (int i = 0; i < NUM_QTRS; i++)   // loop through all quarters
		cout << gpa[9][i] << endl;       // print gpa of student10
	cout << endl;

	// print all the gpas during the first quarter
	cout << "GPAs for first quarter\n";
	for (int i = 0; i < NUM_STUDENTS; i++)     // loop through all students
		cout << gpa[i][0] << endl;			   // print gpa of first quarter
	cout << endl;


	// Calculate average gpa for each student and the average gpa for all students
	averaging (gpa);

   return 0;
}

// fillArr: open the file gpa.txt, read in from the file
// to fill the gpa array
bool fillArr(double gpa[][NUM_QTRS])
{
	ifstream in;
	in.open("gpa.txt");
	if (!in)
	{
		cout << "error opening file\n";
		return false;
	}
	for (int s = 0; s < NUM_STUDENTS; s++)   // loop through all students
	{
		for (int n = 0; n < NUM_QTRS; n++)   // go through each score in one row
			in >> gpa[s][n];				 // read into array
	}
	in.close();
	return true;

}


// averaging: calculate and print the average gpa of each student
// and then print the average gpa of all students
void averaging(double gpa[][NUM_QTRS])
{
	double avg = 0;
	double total = 0;
	for (int s = 0; s < NUM_STUDENTS; s++)
	{
		avg = 0;
		for (int i = 0; i < NUM_QTRS; i++)
		{
			avg += gpa[s][i];				// total for 1 student
		}
		// print avg for 1 student
		cout << "average for student " << s+1 << " is " << avg / NUM_QTRS << endl; 

		// total for all students
		total += avg / NUM_QTRS;
	}
	cout << "average for all students: " << total / NUM_STUDENTS << endl;
}
