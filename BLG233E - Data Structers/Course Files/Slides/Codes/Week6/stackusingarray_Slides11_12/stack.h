// stack.h
// Stack struct definition
// Member functions are defined in stack.cpp

// prevent multiple inclusions of header
#ifndef STACK_H
#define STACK_H

#define STACKSIZE 5 // replace all subsequent occurrences of symbolic constant STACKSIZE with 5

typedef char* StackDataType;  // declares StackDataType as a synonym (alias) for data type char*

// Stack struct definition
struct Stack{
	StackDataType element[STACKSIZE];
	int top;

	void create();
	void close();
	bool push(StackDataType);
	StackDataType pop();
	bool isempty();
};

#endif
