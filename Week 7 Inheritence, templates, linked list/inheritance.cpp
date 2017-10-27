// This program demonstrates inheritance concepts

// Due to time constraints with the in class exercises, all classes are in this one source file.
// They technically should be in separate .h and .cpp files.

#include <iostream>
#include <string>
using namespace std;

// base class
class College
{
//private:
protected:
	string name;   // what does protected mean?
					//it means derived class can access this name
public:
	College(string name = "any college") 
	   { this->name = name; cout << "base College constructor\n"; }
	virtual ~College() { cout << "base College destructor\n"; }
	virtual void printName() const = 0;			//pure virtual function (has no body, becomes an abstract class)
	virtual void printAll() const { cout << "College: "; printName(); }
 
};

// derived class 
class CommunityCollege : public College
{
private:
	string district;
public:
	CommunityCollege(string name, string district) : College(name)
	   { this->district = district; cout << "derived Community College constructor\n"; }
	~CommunityCollege() { cout << "derived Community College destructor\n"; }
	void printName() const { cout << district << "'s " << name << endl; }
	// this printName is function overriding
	// - must have exact same function signiture to override : return data type, name, and input argument
};

// derived class 
class FourYearCollege : public College
{
public:
	FourYearCollege(string name) : College(name) 
	   { cout << "derived Four Year College constructor\n"; }
	~FourYearCollege() { cout << "derived Four Year College destructor\n"; }
	void printName() const { cout << "Four year college: " << name << endl; }
};

int main()
{
	/*
	/////////////////////// Part 1: inheritance basics //////////////////////
	// 1. run the following code and observe the order the constructors / destructors run
	// Order is: college constructor, then community college constructor
				//community college destructor, then college destructor

	CommunityCollege da ("De Anza", "fhda");
	da.printName();		// 1. which printName is called?   
								//derived print name is called
						// 2. what if there is no derived printName()?   
								//then base printName will be called
						// 3. how to call base printName()?      
								da.College::printName();

	// 4. what if it's a protected inheritance?    
		//
	// 5. what if it's a private inheritance?		

	
	///////////////// Part 2: base class creates virtual functions /////////////////////////
	// 1. add a College printAll function that prints "College" and then calls printName

	College c;				// base object
	c.printName();			// 1. which printName?
									//base printName
	c.printAll();			// 2. printAll calls which printName?
									//base printName
	CommunityCollege da ("De Anza", "fhda");
	da.printName();			// derived printName runs
	da.printAll();			// 3. does it run?
									//yes, it goes to higher class to look for the printAll function and runs
							// 4. which printName runs?    
									//base print name, because we are in the base class when printAll is ran
	// 5. how to get derived printName to run?   
	/*
	use keyword virtual in front of base printName 
	this allows dynamic binding: the compiler will not bind the base printAll 
	with  the base printName, but will keep the option of a different printName
	This causes the compiler, during runtime, to find the derived printName
	if the current object is a derived object

	The keyword virtual has no effect on the function that it's in front if 
	It only has the effect on the redefined function in the derived class

	In a base class, typically you put virtual in front of every function 
	that you think a derived class will redefine, including destructors
	The only function that doesn't have virtual in a base class are constructors
	*/
	/*


	////////////////// Part 3: polymorphism ////////////////////////
	College c;
	CommunityCollege da("De Anza", "fhda");
	// 1. create a base pointer
	College * ptr;
	// a base class pointer can legally point to both a base object
	// and a derived object

	// 2. set it to base class and call printName
	ptr = &c;
		//(*ptr).printName();
	ptr->printName();

							// which printName runs?
								//base printName

	// 3. set it to derived class and call printName
	ptr = &da;
	ptr->printName;
							// which printName runs?
								//derived printName

	// polymorphism means: from the same ptr, it can appear as a base object 
	// or it can appear as a derived object

	// 4. use of polymorphism
	College * derivedPtr1 = new College;
	derivedPtr1->printName();    // which printName?
									//base

	CommunityCollege * derivedPtr2 = new CommunityCollege("Foothill", "fhda");
	derivedPtr2->printName();     // which printName?
									// derived

	FourYearCollege * derivedPtr3 = new FourYearCollege("San Jose State");
	derivedPtr3->printName();    // which printName?
									//derived

	College * basePtr = derivedPtr1;
	basePtr->printName();       // which printName?
									//base
	basePtr = derivedPtr2;
	basePtr->printName();       // which printName?
									//derived
	basePtr = derivedPtr3;
	basePtr->printName();       // which printName?
									//derived

	// anything we need to do if the program ends here?
	delete[] derivedPtr1;
	delete[] derivedPtr2;
	delete[] derivedPtr3;
	*/

	////////////////// Part 4: abstract class ////////////////////////
	// 1. turn the College class to an abstract class

	//College c;				// 2. is there a problem?
									//cannot create objects from an abstract class

	CommunityCollege da ("De Anza", "fhda");    // 3. is there a problem?
													//no
	da.printName();			   


	return 0;
}