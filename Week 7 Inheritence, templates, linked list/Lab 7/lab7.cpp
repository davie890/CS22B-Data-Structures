// Lab 7:  Program to maintain class lists during registration
// Name: Clare Nguyen
// Date: June 2015

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "History.h"
#include "ShortCourse.h"
using namespace std;


int main()
{
	// 1. Create 2 History courses from De Anza
	History class1("HIST 3C", 3, 4);       // HIST 3C: world history, 18th century to cold war
	class1.add("Marx, Karl");
	class1.add("Darwin, Charles");
	class1.add("von Bismarck, Otto");
	class1.add("Truth, Sojourner");
	class1.add("Curie, Marie");
	cout << "class 1:\n" << class1 << endl;

	vector<string> v = { "Roosevelt, Franklin", "King, Martin Luther", "Addams, Jane" };
	History class2("HIST 17C", 4, 4, v);    // HIST 17C: us history, 1900 - 1980
	cout << "class 2:\n" << class2 << endl;
	
	// 2. Add and drop students from History courses
	cout << "Adding student to class 1\n";
	class1.add("Tojo, Hideki");
	cout << "class 1:\n" << class1 << endl;
	cout << "Dropping student from class 1\n";
	class1.drop("Darwin, Charles");       
	cout << "class 1:\n" << class1 << endl;
	cout << "Adding student to class 1\n";
	class1.add("Churchill, Winston");
	cout << "class 1:\n" << class1 << endl;
	cout << "Dropping students from class 1\n";
	class1.drop("Curie, Marie");
	cout << "class 1:\n" << class1 << endl;

	cout << "Dropping all students from class 2\n";
	class2.drop("Addams, Jane");
	class2.drop("Roosevelt, Franklin");
	class2.drop("King, Martin Luther");
	class2.drop("abc");
	cout << "class 2:\n" << class2 << endl;

	cout << "Copying class 1 to class 2\n";
	class2 = class1;
	cout << "class 2:\n" << class2 << endl;

	cout << "Create a new class 3 from class 2\n";
	History class3 = class2;
	cout << "class 3:\n" << class3 << endl;

	cout << "==================================\n";

	// 3. create 2 ShortCourses classes from De Anza
	ShortCourse class4("Public Speaking");
	class4.add("Kennedy, John");
	class4.add("Mandela, Nelson");
	class4.add("Bhutto, Zulfiqar");
	cout << "class 4:\n" << class4 << endl;

	vector<string> v1 = { "McCarthy, Paul", "Ruzhuo, Cui", "Gormley, Antony", "Warhol, Andy"};
	ShortCourse class5("Art and Design", v1);
	cout << "class 5:\n" << class5 << endl;

	// 4. add and drop students from ShortCourse classes
	class5.drop("McCarthy, Paul");
	cout << "class 5:\n" << class5 << endl;
	class5.add("Gormley, Antony");
	cout << "class 5:\n" << class5 << endl;

	return 0;
}
