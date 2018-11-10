//Denzell Gibson
//CSC382 10:30am
//5/25/2017

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "Header.h"
#include "Node.h"

//List of Node objects that are connected by pointers.
template <class T> class LinkedList
{
public:
	LinkedList<T>(); //Default Constructor.
	~LinkedList<T>(); //Default Destructor.

	void insert(T); //Creates a new node and puts it at the end of the list.
	Node<T>* find(T); //Finds the node with the matching variable value and returns the pointer to that node.
	void deleteNode(T); //Deletes the node with the matching variable value.
	T findMinimum(); //Finds minimum value out of the list.
	T findMaximum(); //Finds the maximum value out of the list.
	void displayData(); //Displays values of all nodes in the same order as they appear in the list.

	
	
private:
	//Declarations.
	Node<T> *head; //Node pointer that points to the first node in the list.
	Node<T> *tail; //Node pointer that points to the last node in the list.
};

//Definition
//Default Constructor.
template <class T>
LinkedList<T>::LinkedList()
{
	head = NULL;
	tail = NULL;
}

//Default Destructor.
template <class T>
LinkedList<T>::~LinkedList()
{

}

//Takes an int argument and creates a new Node.
template <class T>
void LinkedList<T>::insert(T item)
{
	Node<T>* tempLast;
	if (head == NULL) //If the list is empty...
	{
		head = new Node<T>(item, NULL, NULL); //The new Node will be assigned to the 'head' Node pointer.
		tail = head; //The 'tail' Node pointer to the new Node as well.
	}
	else //Otherwise, if the list isn't empty...
	{
		Node<T> *tempLast; //Create a temporary Node pointer.

		tempLast = tail; //Assign the last Node in the list to the 'temp' Node pointer.
		tail = new Node<T>(item, NULL, tempLast); //Assign the newly created Node to the 'tail' Node pointer.
		tempLast->setNext(tail); //Assign the new tail as the next Node for the old tail Node.
	}
}

//Finds a node by matching the value passed in with the data member of the Node.
template <class T>
Node<T>* LinkedList<T>::find(T number)
{
	Node<T>* currentNode; //Creates a new Node pointer called currentNode (will be referred to by 'current').
	currentNode = head; //Assigns the first Node to 'current' Node pointer.

	while (currentNode != NULL) //While the 'current' Node pointer is not NULL...
	{
		if (currentNode->getData() == number) //If the data member 'data' is equal to the passed in value 'number'...
		{
			return currentNode; //Return the 'current' Node pointer.
			break; //Breaks from the loop, ending the function.
		}
		else //Otherwise, if the two values are not equal...
		{
			currentNode = currentNode->getNext(); //Assign the next Node in the list to the 'current' Node pointer.
		}
	}
}

//Deletes a node that holds the matching value by first using the find() method to return the pointer of the node,
//then reassigning the Nodes before and after the to-be-deleted node to point to each other, and finally deleting the Node.
template <class T>
void LinkedList<T>::deleteNode(T number)
{
	Node<T> *currentNode, *lastNode, *nextNode; //Create the Node pointers 'currentNode',' lastNode', and 'nextNode'.
	currentNode = find(number); //Finds the node, using the passed in value, and assigns the node to the 'currentNode' Node pointer.

	if (currentNode == head && currentNode->getNext() != NULL) //While the desired Node is the first Node and the next Node is not NULL...
	{
		nextNode = currentNode->getNext(); //Make nextNode equal to the second Node in the list.
		nextNode->setPrevious(NULL); //Sets the previous pointer of the second Node NULL.
		head = nextNode; //Makes the second Node the first Node;
		delete currentNode; //Deletes the old head Node;
	}
	else if (currentNode == tail && currentNode->getPrevious() != NULL) //While the desired Node is the last Node and the previous Node is not NULL...
	{
		lastNode = currentNode->getPrevious(); //Make lastNode equal to the second to last Node in the list.
		lastNode->setNext(NULL); //Makes lastNode next pointer equal to NULL.
		tail = lastNode; //Makes the lastNode the new tail Node.
		delete currentNode; //Deletes the old tail Node.
	}
	else if (currentNode->getNext() == NULL && currentNode->getPrevious() == NULL) //If the to be deleted Node is the only Node in the list...
	{
		head = NULL; //Sets head pointer NULL
		tail = NULL; //Sets tail pointer NULL
		delete currentNode; //Deletes the only Node.
	}
	else //Otherwise...
	{
		lastNode = currentNode->getPrevious(); //Sets lastNode to the Node before the to be deleted Node.
		nextNode = currentNode->getNext(); //Sets nextNode to the Node after the to be deleted Node.
		lastNode->setNext(nextNode); //Assigns lastNode's 'next' Node pointer to 'nextNode'.
		nextNode->setPrevious(lastNode); //Assigns nextNode's 'previous' Node pointer to 'lastNode'.
		delete currentNode; //Delete the Node.
	}
}

//Searches through all the Nodes until a Node contains the value matching the passed in value.
template <class T>
T LinkedList<T>::findMaximum()
{
	Node<T>* currentNode; //Creates a 'currentNode' Node pointer.
	T max; //Declares a max variable of data type int.
	currentNode = head; //Assigns the 'currentNode' Node pointer to first Node in the list.
	max = currentNode->getData(); //Assigns the max variable to the 'data' variable found in currentNode.
	currentNode = currentNode->getNext(); //Sets 'currentNode' equal to the next Node in the list.

	while (currentNode != NULL) //While the currentNode pointer is not pointing to NULL...
	{
		if (currentNode->getData() > max) //If currentNode's data variable is greater than the max variable...
		{
			max = currentNode->getData(); //Reassign the max variable to equal the currentNode's data variable value.
		}
		currentNode = currentNode->getNext(); //Makes currentNode equal to the next Node in the list.
	}
	return max; //Returns the max after tranversing the list and comparing values.
}

//Finds the minimum data variable value in the list.
template <class T>
T LinkedList<T>::findMinimum()
{
	Node<T>* currentNode; //Creates a Node pointer.
	T min; //Declares a new variable.

	if (head == NULL && tail == NULL)
	{
		std::cout << "The list is empty" << std::endl;
	}
	else
	{
		currentNode = head; //Makes currentNode equal to the first Node in the list.
		min = currentNode->getData(); //Makes the min variable equal to the currentNode's data variable value.
		currentNode = currentNode->getNext(); //Makes the currentNode equal to the next Node in the list.

		while (currentNode != NULL) //While the currentNode pointer is not point to NULL...
		{
			if (currentNode->getData() < min) //If the currentNode's data variable's value is less than min variable's value...
			{
				min = currentNode->getData(); //Make the min variable equal to the currentNode's data variable's value.
			}
			currentNode = currentNode->getNext(); //Makes the currentNode equal to the next Node in the list.
		}
		return min; //Returns the min value after tranversing and compares values in the list.
	}
}

//Displays all Nodes' data variable values in the order that they appear in.
template <class T>
void LinkedList<T>::displayData()
{
	Node<T>* currentNode; //Creates a Node pointer.
	currentNode = head; //Makes the currentNode equal to the first Node.

	if (head == NULL && tail == NULL)
	{
		std::cout << "The list is empty" << std::endl;
	}
	else
	{
		std::cout << "Items in the list" << std::endl; //Prints to console.

		while (currentNode != NULL) //While the currentNode pointer is not pointing to NULL...
		{
			std::cout << currentNode->getData() << std::endl; //Print to console the currentNode's data variable's value.
			currentNode = currentNode->getNext(); //Make the currentNode equal to the next Node in the list.
		}
	}
}

#endif