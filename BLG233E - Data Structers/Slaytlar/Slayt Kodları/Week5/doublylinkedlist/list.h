// list.h
// List struct definition for doubly linked list
// Member functions are defined in list.cpp

// prevent multiple inclusions of header
#ifndef LIST_H
#define LIST_H

#include "node.h" // include definition of struct Phone_node

// List struct definition
struct List{
	Phone_node *head, *tail;
	int nodecount;
	char *filename;
	FILE *phonebook;
	void create();
	void close();
	void makeEmpty();
	void insert(Phone_node *);
	void remove(int ordernum);
	int search(char *);   
	void update(int recordnum, Phone_node *);
	void read_fromfile();
	void write_tofile();
};

#endif
