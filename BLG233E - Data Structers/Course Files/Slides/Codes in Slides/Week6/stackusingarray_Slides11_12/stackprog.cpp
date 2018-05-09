// stackprog.cpp 
// Testing the operations that we can perform on the stack

#include <iostream> // allows program to perform input and output
#include "stack.h" // include implementation of struct Stack

using namespace std; // enables the program to use all the names in any included standard C++ header 

// function main begins program execution
int main() {
	Stack s;
	s.create();
	char name[10] = "Ahmet";
	s.push(name);
	strcpy(name, "Burak");
	s.push(name);

	s.push("Yusuf");
	while ( !s.isempty() ) 
	{
		cout << s.pop() << " ";
	}
	cout << endl;
	return EXIT_SUCCESS; // C++ macro that indicates program was executed successfully
}