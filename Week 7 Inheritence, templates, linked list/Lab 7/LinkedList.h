//Davie Truong
// Header and implementation for linked list with template

#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>     

using namespace std;

template <class T>
class LinkedList
{
private:
	int count = 0;
	struct ListNode
	{
		T data;
		struct ListNode * next;
	};

	ListNode *head;

public:
	LinkedList() {count = 0, head = nullptr; }
	~LinkedList();

	// Linked list operations
	void insertNode(T);
	bool deleteNode(T);
	bool searchNode(T);
	void displayList() const;
	int getCount() const { return count; }
	LinkedList<T>(const LinkedList<T> & right);
	LinkedList<T> * operator= (const LinkedList<T> & right);

};


/////////// Implementation portion of linked list with template  /////////////
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

	if (head == nullptr)
	{
		head = newNode;
		count++;
	}
	else
	{
		pCur = head;
		pPre = nullptr;
		while (pCur != nullptr && pCur->data < newValue)
		{
			pPre = pCur;
			pCur = pCur->next;
		}

		if (pPre == nullptr)
		{
			head = newNode;
			newNode->next = pCur;
			count++;
		}
		else
		{
			pPre->next = newNode;
			newNode->next = pCur;
			count++;
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

	if (pCur != NULL && pCur->data == toBeDeleted)
	{
		if (pPre)
			pPre->next = pCur->next;
		else
			head = pCur->next;
		delete pCur;
		count--;
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

// Overloaded = operator, deep copies the linked list
template <class T>
LinkedList<T> * LinkedList<T>::operator= (const LinkedList<T> & right)
{	
	this->count = 0;
	if (right.head == NULL)
	{
		this->head = nullptr;
	}
	else
	{
		ListNode * ptr = right.head;

		while (ptr != nullptr)
		{
			insertNode(ptr->data);	//inserts the data into the node
			ptr = ptr->next;
		}
	}
	return this; // returns the 
}

//copy construcor for linked list
template <class T>
LinkedList<T>::LinkedList<T>(const LinkedList<T> & right)
{
	this->count = 0;
	if (right.head == NULL)
	{
		this->head = nullptr;
	}
	else
	{
		ListNode * ptr = right.head;

		while (ptr != nullptr)
		{
			insertNode(ptr->data);
			ptr = ptr->next;
		}
	}
}
#endif 