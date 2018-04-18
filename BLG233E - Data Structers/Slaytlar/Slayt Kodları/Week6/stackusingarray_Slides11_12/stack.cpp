// stack.cpp 
// Defining the operations that we can perform on the stack

#include <iostream> // allows program to perform input and output
#include <string.h> // program uses C++ standard string class 
#include "stack.h" // include implementation of struct Stack

// create empty stack
void Stack::create()
{
	top = 0;
}

// close the stack
void Stack::close()
{
}

// push new element onto stack
bool Stack::push(StackDataType newelement){
	if (top < STACKSIZE){
		element[top++] = newelement;
		return true;
	}
	return false;
}

// pop an element from stack
StackDataType Stack::pop()
{
	return element[--top];
}

// check if stack is empty
bool Stack::isempty()
{
	return (top == 0);
}
