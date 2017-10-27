// This program calculates the average gpas of students

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


const int NUM_STUDENTS = 12;		// Number of students
const int NUM_QTRS = 4;				// Number of quarters


int main()
{
	double gpa[NUM_STUDENTS][NUM_QTRS]; // Array for 12 students, each with 4 quarters

	// read from file and fill array with students gpas
	if (!fillArr(gpa))
		return 1;

	// print student5's gpa for quarter 2
	cout << "Student 5, quarter 2: " << gpa[4][1];  //4,1 BECAUSE THE ARRAY STARTS AT 0

	// print all the gpas of student10
	cout << fixed << setprecision(2);


	// print all the gpas during the first quarter
    for(int i=0; i < NUM_STUDENTS; i++)
        {
            cout << gpa[i][0] << endl;
        }

	cout << endl;

	// Calculate average gpa for each student and the average gpa for all students
	averaging (gpa);

   return 0;
}

// fillArr: open the file gpa.txt, read in from the file
// to fill the gpa array

bool fillArr(double gpa[][NUM_QTRS])
{
    ifstream.in
    in.open("gpa.txt")
    if(!in)
    {
        cout << "ERROR Opening the file \n";
        return false;
    }
    for(int s = 0; s < NUM_STUDENTS; s++) // THE OUTER LOOP IS FOR EACH ROW
    {
        for(int n=0; n < NUM_QTRS; n++) //THE INNER LOOP IS FOR COLUMNS //GOES THROUGH EACH SCORE ON ONE ROW
            in >> gpa[s][n];
    }
    in.close();
    return true;
}



// averaging: calculate and print the average gpa of each student
// and then print the average gpa of all students
void averaging(double gpa[][NUM_QTRS])
{
    double avg=0;
    for(s= 0; s < NUM_STUDENTS; s++)
    {
        avg = 0;
        for(int i=0; i < NUM_QTRS; i++)
        {
            avg += gpa[s][i];
        }
    }
    cout << "average for student is: " << s+1 << "is " << avg / NUM_QTRS << endl;
}
