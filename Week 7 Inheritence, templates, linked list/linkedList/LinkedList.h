// Header and implementation for linked list with template

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>     
using namespace std;

template <class T>
class LinkedList
{
private:
	struct ListNode
	{
      T data ;               
      struct ListNode * next;  
	}; 

	ListNode *head;   

public:
	LinkedList() { head = nullptr; }
	 ~LinkedList();
      
	// Linked list operations
	void insertNode(T);
	bool deleteNode(T);
	void displayList() const;
};


/////////// Implementation portion of linked list with template  //////////////

// displayList: print all list data
template <class T>
void LinkedList<T>::displayList() const
{
	ListNode * ptr = head;	

	while (ptr != nullptr)      
	{
		cout << ptr->data << endl;		
		ptr = ptr->next;				
	}
}

// insertNode: add a node in list order
template <class T>
void LinkedList<T>::insertNode(T newValue)
{
	ListNode *newNode;			   
	ListNode *pCur;	
	ListNode *pPre = NULL;

	newNode = new ListNode;
	newNode->data = newValue;
	newNode->next = nullptr;
   
	if (head == nullptr)    //adding the first node in the list
	{
      head = newNode;
    }
	else				//adding 2nd, 3rd, 4th nodes, etc.
	{
		pCur = head;        
		pPre = nullptr;	

		while (pCur != nullptr	//walk the list until end of list
			&& pCur->data < newValue)		//or until new value > current data, which ever comes first
		{  
			pPre = pCur;
			pCur = pCur->next;
		}
		//when we stop the loop, pPre is at the node before the insert location
		//and pCur is at the node AFTER the insert location
		//therefore we insert it in between pPre and pCur

		//code to do insertion
		if (pPre == nullptr)	//to insert at the head of the list (or begginning of list)
		{
			head = newNode;
			newNode->next = pCur;
		}
		else					//to insert in the middle or end of list
		{
			pPre->next = newNode;
			newNode->next = pCur;
			
		}
	}
}

// deleteNode: delete a node if found
template <class T>
bool LinkedList<T>::deleteNode(T toBeDeleted)
{
	ListNode *pCur;			
	ListNode *pPre;	

	if (!head)
		return true;
 
	pCur = head;
	pPre = NULL;
	while (pCur != NULL && pCur->data < toBeDeleted)
    {  
         pPre = pCur;
         pCur = pCur->next;
	}
	//at the end of loop, pCur points to foind node or to the node immediately after 
	//where the target node should be
	//and pPre is at the node before pCur

	//code to delete the node
	if (pCur != NULL && pCur->data == toBeDeleted)
    {
 		if (pPre)
			pPre->next = pCur->next;
		else		
			head = pCur->next;
        delete pCur;			
		return true;
    }
	return false;
}

// destructor, delete all nodes
template <class T>
LinkedList<T>::~LinkedList()
{
	ListNode *ptr = head;
	while (ptr != NULL)
	{
		head = head->next;
		delete ptr;		
		ptr = head;		
	}
}
#endif 