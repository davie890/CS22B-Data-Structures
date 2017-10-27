// Review of 22A concepts
// This program greets the user by name and prints a triangular pattern
// of the user given size.
// Then it reads in a class name and scores from a file, and prints out
// the class name, scores, min score, max score, and average score

// what include files are needed
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAX = 25;		// Max number of scores

void print(int scores[], string classname, int numScores);
bool fillArr(int scores[], string &classname, int &numScores);
void printStats(int scores[], int numScores);

int main()
{
	// create 2 integers for height and base of triangle
	int h, b;

	// create 2 strings called uname and classname
    string uname, classname;

	// create an array of MAX integers called scores
    int scores[MAX];

	// create an integer numScores
	int numScores;

	// prompt the user for a name (can have space) and print "hi, name!"
	cout << "Enter name: ";
	getline(cin, uname);
	cout << "Hi, " << uname << "!\n";

	// ask the user for the base and the height of the triangle
	cout << "Height of triangle: ";
	cin >> h;
	cout << "Base of triangle: ";
	cin >> b;

    //set both h and b to the smallest of the 2
    if(h<b)
    {
        b=h;
    }
    else if (h>=b)
    {
        h=b;
    }

	// print a triangular pattern of * with given height and base
    if (h == b)
    {
        for(int r=1; r <= h; r++)
        {
                for(int c=1; c<=r; c++)
                {
                    cout << " *";
                }
                cout << "\n";
        }
    }


	// call function fillArr to fill the scores array, the classname, and the number of scores
	// fillArr returns false if file open fails, true if successful

	if (!fillArr (scores, classname, numScores));
	{
		return true;
	}

	// call a function print to print the classname and scores
	print (scores, classname, numScores);

	// call a function printStats to print the minimum, maximum, and average scores
	printStats(scores, numScores);

	// create a vector of integers

	// copy data from the array into the vector

	// print data from the vector by calling the print function


   return 0;
}

// fillArr: open scores.txt, read in the classname (first line of scores.txt),
//          then read all scores into scores array until EOF
// Input: scores array, classname, number of scores
// Return: true - success
//         false - fail to open
bool fillArr(int scores[], string &classname, int &numScores)
{
    ifstream in;
    in.open("scores.txt");
        if(!in)
        {
            cout << "Error opening file \n";
            return false;
        }
        int i=0;
        getline(in, classname);
        //while (in >> scores[i++]); //makes it one more than needed
        while (in >> scores[i]);
        {
            i++;
        }
        numScores = i;
        // numScores = numScores-1; alternate fix
        in.close();
        return true;
}


// print: print the class name and the scores
//        scores are printed with minimum width of 3, all on one line
// Input: scores array, class name, number of scores
// Return: nothing
void print(int scores[], string classname, int numScores)   //pass by value because function doensn't change data
{
    cout << classname << endl;
    for(int i=0; i< numScores; i++)
    {
        cout<< setw(4) <<scores[i];
    }
    cout << endl;
}


// printStats: print the minimum, maximum, and average of the scores,
//             with 2 digits after the decimal point, lined up in column format
// Input: scores array, number of scores
// Return: nothing
void printStats(int scores[], int numScores)
{
    int maxScore = scores[0];
    int minScore = scores[0];
    int total = scores[0];
    double avg;
    for(int i=1; i<numScores;i++)
    {
        if(scores[i] > maxScore)  // find largest value
        {
            maxScore = scores[i];
        }
        if(scores[i] < minScore)  // find smallest value
        {
            minScore = scores[i];
        }
        total += scores[i];
    }
        avg = static_cast<double>(total)/ numScores;


    cout << "The miniumum score is: " << right << setw(5) << minScore << endl;
    cout << "The maxumum score is: " << right << setw(5) << maxScore << endl;
    cout << "THe Average score is: " << right << fixed << showpoint << setw(5) << setprecision(2) << avg << endl;
}


