// stack_1.h
// Stack struct definition
// Member functions are defined in stack_1.cpp

// prevent multiple inclusions of header
#ifndef STACK_H
#define STACK_H

#define STACKSIZE 5 // replace all subsequent occurrences of symbolic constant STACKSIZE with 5

typedef char StackDataType;  // declares StackDataType as a synonym (alias) for data type char

// Node struct definition 
struct Node{
	StackDataType data;
	Node *next;
};

// Stack struct definition
struct Stack{	
	Node *head;
	void create();
	void close();
	void push(StackDataType);
	StackDataType pop();
	bool isempty();
};

#endif
