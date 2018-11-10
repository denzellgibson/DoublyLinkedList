//Denzell Gibson
//CSC382 10:30am
//5/25/2017

#ifndef NODE_H_
#define NODE_H_

#include "Header.h"

//Data nodes to be contained in the Linked List class.
//template <class T>
//class LinkedList;

template <class T>
class Node
{
	//friend class LinkedList<T>;

public:
	Node(); //Default Constructor.
	Node(T, Node<T>*, Node<T>*); //Constructor that takes an int, and two Node pointers.

	void setNext(Node<T>*); //Sets the pointer to the next node in the list.
	void setPrevious(Node*); //Sets the pointer to the previous node.
	Node<T>* getNext(); //Returns the pointer to the next node.
	Node<T>* getPrevious(); //Returns the pointer to the preivous node.
	T getData(); //Returns the variable within the node.
	void setData(T); //Sets the variable within the node.
private:
	//Declarations.
	T data; //int variable.
	Node<T> *next; //Node pointer that points to the next node in the list.
	Node<T> *previous; //Node pointer that points to the previous node in the list.
};

//Default Constructor.
template <class T>
Node<T>::Node()
{
	//Initializes variables and pointers.
	data = 0;
	next = NULL;
	previous = NULL;
}

//Constructor that has an int and two Node pointers as parameters.
template <class T>
Node<T>::Node(T item, Node<T> *nextNode, Node<T> *lastNode)
{
	//Assigns the arguments to their proper variable and pointers.
	data = item;
	next = nextNode;
	previous = lastNode;
}

//Changes the 'next' Node pointer to a new Node.
template <class T>
void Node<T>::setNext(Node<T>* nextNode)
{
	next = nextNode;
}

//Changes the 'previous' Node pointer to a new Node.
template <class T>
void Node<T>::setPrevious(Node<T> * lastNode)
{
	previous = lastNode;
}

//Returns the 'next' Node pointer.
template <class T>
Node<T>* Node<T>::getNext()
{
	return next;
}

//Returns the 'previous' Node pointer.
template <class T>
Node<T>* Node<T>::getPrevious()
{
	return previous;
}

//Returns the value of 'data' variable.
template <class T>
T Node<T>::getData()
{
	return data;
}

//Reassigns 'data' int variable to a new value.
template <class T>
void Node<T>::setData(T number)
{
	data = number;
}

#endif