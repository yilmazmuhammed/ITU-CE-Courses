// main.cpp 
// Testing the operations that we can perform on the stack

#include <iostream> // allows program to perform input and output
#include <stdlib.h>
#include <iomanip>

#include <ctype.h>

#include "stack_1.h" // include implementation of struct Stack

using namespace std; // enables the program to use all the names in any included standard C++ header 

// function main begins program execution
int main()
{
	Stack s;
	s.create();	
	s.push('A');
	s.push('B');
	char c = s.pop();
	c = s.pop();	
	// if ( !s.isempty() )
		s.pop();	
	s.close();
	
	return EXIT_SUCCESS; // C++ macro that indicates program was executed successfully
}

