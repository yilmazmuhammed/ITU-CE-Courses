// stack_1.cpp 
// Defining the operations that we can perform on the stack

#include <iostream> // allows program to perform input and output
#include <string.h> // program uses C++ standard string class 
#include "stack_1.h" // include implementation of struct Stack

// create empty stack
void Stack::create()
{
	head = NULL;
}

// close the stack
void Stack::close()
{
	Node *p;
	while (head){
		p = head;
		head = head->next;
		delete p;
	}
}

// push new element onto stack
void Stack::push(char newdata)
{
	Node *newnode = new Node;
	newnode->data = newdata;
	newnode->next = head;	
	head = newnode;
}

// pop an element from stack
StackDataType Stack::pop()
{
	Node *topnode;
	StackDataType temp;
	topnode = head;
	head = head->next;
	temp = topnode->data;
	delete topnode;
	return temp;
}

// check if stack is empty
bool Stack::isempty()
{
	return head == NULL;
}
