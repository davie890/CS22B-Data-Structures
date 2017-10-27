// lab 2:  Variation of Connect 4 game
// Written by:  Davie Truong
// Date:   April 21, 2015

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

char ** buildGrid(int &size);
void printGrid(char ** ptr, int size);
void play(char ** ptr, int size);
bool oneTurn(char ** ptr, int size, int playerNumber);


int main()
{
	char **ptr;
	int size;
	char answer;
	do
	{
		ptr = buildGrid(size);
		printGrid(ptr, size);
		play(ptr, size);
		cout << "Play again? y/n: ";
		cin >> answer;
	} while (answer == 'y');
    //delete [] ptr;   //////////////// need to delete all rows that were allocated    -1/2pt
    ////correct delete ////
    for(int i = 0; i < size; i ++)
    {
        delete[]*(ptr + i);
        delete[] ptr;
    }
	return 0;
}

// buildGrid: prompt the user for a grid size between 6 and 10, reprompt if invalid size,
//            create a 2D array of characters for the grid,
//            fill the grid with _ characters
// input: reference to the size of the grid that the user enters
// return: the address of the 2D array
char ** buildGrid(int &size)
{
    size = 0;                                                       //askes the user for the size of their grid

    do
    {
        cout << "What size do you want for the connect 4 grid?" << endl;
        cout << "The size of the grid must be between 6 and 10" << endl;
        cin >> size;
        while (cin.fail())                                          //used so alphabets do not work
            {
                cout << "ERROR, enter a number" << std::endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> size;
            }

        if(size > 10 || size < 6)       //checks to see if the number is valid
        {
        cout << "Invalid Size. Choose a number between 10 and 6.";
        }
        else
        {
            break;
        }
    }
    while(true);    //sets the condition to go through the loop
	         ///////////// use loop control. This loop is not meant to run forever.    -1/2pt
			/////////////  while (size > 10 || size < 6)

    char * *ptr = new char * [size];    //creates the "column"

    for(int i = 0; i < size; i++)
    {
    *(ptr+i) = new char[size];          //creates the "rows"						///////////// indent inside statement block    -1/2pt
            for(int j = 0; j < size; j++)
            {
            *(*(ptr+i)+j) = '_';        //goes through the pointer and adds in the _
            }
    }
    return ptr;
}


// printGrid: prints the grid
// input: the address of the grid, the size of the grid
// return: nothing
void printGrid(char ** ptr, int size)       //prints the grid out for the user
{
cout << "   ";
for(int s= 1; s <= size; s ++)              //numbers the columns
    {

        cout << "  " << s;
    }
    cout << endl;


    for(int i = 0; i < size; i++)
    {
        cout << setw(3) <<i+1;                        //numbers the rows
        for(int j = 0; j < size; j++)
        {
        cout << setw(2) << "  " << *(*(ptr+i)+j);       //prints out the grid by traversing though the pointers
        }
    cout << endl;
    }
}


// play: loop until a user enters 0
//       inside the loop: let player 1 have one turn, then let player 2 have one turn
// input: the address of the grid, the size of the grid
// return: nothing

void play(char ** ptr, int size)
{

int remainder;
int i = 1;
int playerNumber;
bool output;

    do
    {
            remainder = i % 2;          //used to help determin which turn and player the game is at

            if(remainder != 0)
                {
                playerNumber = 1;
                }
            else
                {
                playerNumber = 2;
                }
                i++;
           output = oneTurn(ptr, size, playerNumber);   //returns bool to set the condition for the while loop
           printGrid(ptr, size);                        //prints the grid so the players can see their move
		      ////////// if output is false, don't print the grid again    -1/2pt



    } while(output == true);    //used to set the condition for the do while loop



}


// oneTurn: ask for a column in the grid, reprompt if invalid column
//          return if the user enters 0
//          change the lowest _ in the column to X for player 1, or O for player 2
// input: the address of the grid, the size of the grid, the player number
// return:  < your choice >
bool oneTurn(char ** ptr, int size, int playerNumber)
{
    int columnChoice;
    char playerChar;
    bool columnFull = true;

    if(playerNumber == 1)               //used to asign a token to the player
    {
        playerChar = 'X';
    }
    else if (playerNumber == 2)
    {
        playerChar = 'O';
    }
    do
    {
        cout << "Player " << playerNumber << " column (0 to end): " << endl;
        cin >> columnChoice;                                                        //asks the user for the column choice and assigns it to a variable
            while (cin.fail())
            {
                cout << "ERROR, enter a number" << endl;                            //used so alphabets dont work
                cin.clear();
                cin.ignore(256,'\n');
                cin >> columnChoice;
            }

        if(columnChoice == 0)               //compares the user input with 0 to check wether to end the function
        {
            return false;
        }

		//////////////// line up the code on the left, indent only inside a statement block
            if(columnChoice > size || columnChoice < 0)     //checks if the user input is correct for the desired size
            {
                cout << "invalid column number." << endl;
                cout << "Enter in a number between 1 and " << size << endl;
            }
            else                                                         //if everything has gone according to the rules, this part is ran to place the token
            {
                    for(int row= size - 1; row >= 0; row--)             //checks the row from the bottom up for other pieces
                    {
                        if(*(*(ptr+row)+columnChoice - 1) == '_' && columnFull)       //compares the value of the point with _
                        {

                            *(*(ptr+row)+columnChoice -1) = playerChar; //if the location has a _, it is replaced with the current player's token
                        columnFull = false;                             //changes the value of the bool so that the function can exit when it breaks

                        }
                    }
                    if(columnFull)                                      //used to tell the user that the current location is full
                    {
                        cout << "can't add to this column" << endl;
                    }

            }
    }while(columnFull); //ends the function or continues depending on the bool set by the for loop



	/////////// return a boolean?
	/////////// without the return statement here, the return value is false and the game ends after 1 turn    -2pts
}










