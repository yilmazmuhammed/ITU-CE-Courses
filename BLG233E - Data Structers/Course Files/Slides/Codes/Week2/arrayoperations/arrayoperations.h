// arrayoperations.h
// Array struct definition
// Member functions are defined in arrayoperations.cpp

// prevent multiple inclusions of header
#ifndef ARRAYOPERATIONS_H
#define ARRAYOPERATIONS_H

#include "record.h" // include definition of struct Phone_Record

#define MAXRECORD 100 // replace all subsequent occurrences of the symbolic constant MAXRECORD with 100

// Array struct definition
struct Array{
	char *filename;
	FILE *phonebook;
	Phone_Record r[MAXRECORD];
	int numrecords; // keeping track of the current number of records in the array
	void create();
	void add(Phone_Record *);
	int search(char []);
	void remove(int recordnum);
	void update(int recordnum, Phone_Record *);
	void list(); // print a list of all records in the array
};

#endif