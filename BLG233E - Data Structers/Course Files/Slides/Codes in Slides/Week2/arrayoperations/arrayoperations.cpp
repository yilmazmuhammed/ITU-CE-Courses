// arrayoperations.cpp 
// Defining the operations that we can perform on the array

#include <iostream> // allows program to perform input and output
#include <stdlib.h>
#include <stdio.h>
#include <string.h> // program uses C++ standard string class 
#include <iomanip>

#include "arrayoperations.h" // include definition of struct Array

using namespace std; // enables the program to use all the names in any included standard C++ header 
   
// create an empty array
void Array::create()
{	
	numrecords = 0; // the number of records in the list is initially 0
}

// add new phone record into array
void Array::add(Phone_Record *nrptr)
{
	// add the new record as the last element (into position "numrecords") 
	strcpy(r[numrecords].name, nrptr->name); 
	strcpy(r[numrecords].phonenum, nrptr->phonenum); 

	numrecords++; // increment the number of records in the list
}

// search the array for a name
int Array::search(char target[])
{	
	int counter = 0;
	bool all = false;
	int found = 0;

	if ( strcmp(target, "*") == 0 ) { // compare the string target to the string "*", if they are equal do the following
		all = true;
	}
	for (int i = 0; i < numrecords; i++) {
		// if( strcmp(r[i].name, target) == 0 ) { 
		if( all || strnicmp(r[i].name, target, strlen(target)) == 0 ){
			cout << i + 1 << ". " << r[i].name << "    \t" << r[i].phonenum << endl;  
			found++;
		}	
	}	
	return found;
}

// remove the name and phonenum fields of a phone record in the array in position "recordnum - 1"
// by replacing it with an empty record
void Array::remove(int recordnum)
{
	Phone_Record temp;
	strcpy(temp.name, "");
	strcpy(temp.phonenum, "");
	r[recordnum - 1] = temp;
}

// update the name and phonenum fields of a phone record in the array in position "recordnum - 1"
void Array::update(int recordnum, Phone_Record *nrptr)
{
	strcpy( r[recordnum - 1].name, nrptr->name );
	strcpy( r[recordnum - 1].phonenum, nrptr->phonenum );	
}

// print to the screen a listing of records in the array
void Array::list()
{
	for (int i = 0; i < numrecords; i++)
		cout << i + 1 << ". " << r[i].name << "    \t" << r[i].phonenum << endl;  
}