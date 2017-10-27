// lab 3:  Madlibs game
// Written by:  Davie Truong
// Date:    April 23, 2015

#include<iostream>  //standard input output
#include<cstring>   //library for c string
#include<cctype>    //library for character functions
#include<string>    //library for c++ strings
#include<fstream>   //used to work with files
#include<stdlib.h>  //needed for RNG
#include<time.h>    //used for RNG

using namespace std;

int readFile(string ** story);
void print(string * story, int count);
void play(string * story, int count);

int main()
{
	string * story;                 //adress of a string
	int count = readFile(&story);   // count is number of lines in the file
	if (count == -1)				// which is also the number of elements in the array
		return 1;
	play(story, count);
	print(story, count);
    delete [] story;        //INCLUDE DELETE FOR DYNOMICOLLLY ALLOCATED ARRAY
	return 0;
}

// readFile: read lines of the file into an array of C++ strings
//           each line is a string element in the array
// input: address of the array
// return: -1 if file open fails
//         number of lines in the file if file reading is successful
int readFile(string ** story)
{


srand(time(NULL));
int number = rand() % 4 + 1;        //generates a random number between 1 and 4

    string txt = "";

    if(number == 1)                 //compares the number and if it is equivilent,
    {                               //assigns the string txt to the txt variable
           txt = "lab3_1.txt";
    }
    else if(number == 2)
    {
           txt = "lab3_2.txt";
    }
    else if(number == 3)
    {
          txt = "lab3_3.txt";
    }
    else if(number == 4)
    {
        txt = "lab3_4.txt";
    }
    else                            //else to end the if-else loop
    {                               //should not come to this
          txt = "";
    }

    ifstream in;
    in.open(txt.c_str());                                //opens the file
        if(!in)                                     //checks to see if the file opens properly
        {
            cout << "Error Openning the file \n";
            return -1;
        }

    int count = 0;
    string linesOfTxt;
    while(getline(in,linesOfTxt))           //counts the number of lines in the files
        {
        count++;
        }

    // reset file pointer to beginning of file
    in.clear();
    in.seekg(0, ios::beg);


    *story = new string [count];            //creates the rows with dynomocally allocated memory

    for(int i = 0; i < count; i++)          //loops through each line of the array
    {
        getline(in,*(*story+i));            //gets the lines from the file and places it into the array
    }
    in.close();
    return count;
}

// print: print the story in the array
// input: address of array, number of elements
// return: nothing
void print(string * story, int count)
{
        for(int i = 0; i < count; i++)  //loops through each line
        {
            cout << *(story+i)<<endl;   //couts each line
        }
}


// play: prompt the user with each keyword and replace the keywordŝ user input
//       user input must be a C string, and it can be multiple words
//       user input is capitalized when stored in the string
// input: address of the array, number of elements
// return: nothing
void play(string * story, int count)
{
    const int Size = 81;
    int pos1 = 0, pos2;
    string temp;
    char answer[Size];

    for(int i = 0; i < count; i++)  //goes through each line of the file
    {

        pos1=story[i].find('<',0);  //assigns pos1 to the first bracket found.
        while(pos1 != -1)           //condition used to continue if there is a < in the line
        {
            pos2=story[i].find('>',pos1);   //assigns pos2 to the next > bracket after starting from pos1

            temp = story[i].substr(pos1 +1,(pos2-pos1-1));  //finds the substring and assigns it to temp
            cout << "Enter " << temp << ": " << endl;  //asks the user to enter specific catagory depending on whats in temp


            cin.getline(answer, Size);        //places the users answer into the variable answer for manipulation

         //  char * shortAnswer = new char[(strlen(answer))+1];


          //converts the answer to upper case///
          for(int j=0; j < strlen(answer) + 1; j++)
          {

            answer[j]=toupper(answer[j]);

          }

          //Changes the txt with the user input//
            story[i].erase(pos1,pos2-pos1+1);
            story[i].insert(pos1,answer);

            pos1=story[i].find('<',0);   //continues the loop to check if there are other < brackets in the line


        }

    }

}

