//Food.cpp: implementation file for the Food class

#include "Food.h"

//Food:: tells the compiler that setName is a member of the Food class
void Food::setName(string n)
{
	name = n;
}
void Food::setNum(int n)
{
	num = n;
}
void Food::setIngredients(string * input_list)
{
	list = new string[num];			//creates a new array to copy the users data
	for (int i = 0; i < num; i++)
	{
		list[i] = input_list[i];	//copies the users data to our own array for safer use
									//list[i] = *(input_list + i)  also works
	}
}
/////remove from .cpp file because we made it an inline function
//string Food::getName()
//{
//	return name;
//}
int Food::getNum()
{
	return num;
}
string Food::getIngredients(int i)
{
	return list[i];
}

//default constructor initializes all data to a "safe" value
Food::Food()
{
	name = "none";
	num = 0;
	list = 0;
}
Food::Food(string inputName, vector<string> inputList)
{
	name = inputName;
	num = inputList.size(); 

	list = new string[inputList.size()];

	for (int i = 0; i < inputList.size(); i++)
	{
		list[i] = inputList[i];
	}
}
void Food::print()
{ 
	cout << name << endl;
	//cout << num << endl ;
	for (int i = 0; i < num; i++)
	{
		cout << list[i] << endl; 
	}
}
Food::~Food()	//destructor
{
	delete[] list;
}