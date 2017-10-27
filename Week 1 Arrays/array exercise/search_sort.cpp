// This program demonstrates insertion sort, binary search
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 10;		// size of 1D array

void insertionSort(int arr[]);
void search(int arr[]);

int main()
{
	int nums[MAX] = {3, 2, 23, 19, 8, 9, 17, 7, 20, 5};

	insertionSort(nums);
	search(nums);
	return 0;
}

void insertionSort(int arr[])
{
	int current = 1;				// start at index 1      
	int last = MAX - 1;				// last index       	
    int temp;						// storage for current element 
	int walker;						// index to walk and compare 

	while (current <= last)  
	{     
		temp = arr[current];		// copy current element to temp     
		walker = current - 1;		// start walking from element in front of current
		while (walker >= 0			// not past front of array yet
			&& temp < arr[walker])	// and current element < element in front     
		{        
			arr[walker+1] = arr[walker];  // shift element in front to the right
			walker = walker - 1;    // walk to next element in front     
		}     
		// when loop stops
		arr[walker+1] = temp;		// insert current element to the proper location in the array 
		current = current + 1;		// get next element  
	}

	for (walker = 0; walker < MAX; walker++)
		cout << arr[walker] << " ";
	cout << endl;
} 

// is the above an ascending or descending sort?
// what line needs to be changed for it to be the other type of sort?


// write comment to explain each line of code
void search (int arr[])
{
	int target;
	
	int first = 0,					       
	    last = MAX - 1,				
		mid,						       
		position = -1;				   
		bool found = false;			// not found yet  

	cout << "Target: ";
	cin >> target;

	while (!found && first <= last)   
	{      
		mid = (first + last) / 2;           
		if (arr[mid] == target)        
		{         
			cout << "found at index " << mid << endl;  
			found = true;
		}      
		else if (arr[mid] > target)         
			last = mid - 1;              
		else            
			first = mid + 1;             
	}  
	if (!found)
		cout << "Not found\n"; 
}
