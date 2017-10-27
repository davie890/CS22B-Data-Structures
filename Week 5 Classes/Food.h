//Food.h: header file for the Food class

#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Food
{
private:		//private usually contains the data for "data hiding"
	string name;
	int num;
	string * list;

public:
	//mutators
	void setName(string n);
	void setNum(int n);
	void setIngredients(string * list);

	//accesssors
	string getName() { return name; } //inline function
	int getNum();
	string getIngredients(int i);

	//constructer
	Food();		//default constructor because no input arguments are needed
				//for constructer to work:
					//must have same name as the class
					//NO return data type, not even void

	Food(string inputName, vector<string> inputList);	//constructor with 2 arguments

	//destructor
	~Food(); //destructor name starts with ~ and is the same name as the clas name
			//no input argument, no return data type


	//output function
	void print(); //prints data from inside the object
};

#endif