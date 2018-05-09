// list.h
// List struct definition (multilist)
// Member functions are defined in list.cpp

// prevent multiple inclusions of header
#ifndef LIST_H
#define LIST_H

#include "node.h" // include definition of struct Phone_node

// List struct definition
struct List{
	Phone_node *head;
	int personcount;
	char *filename;
	FILE *phonebook;
	void create();
	Phone_node *create_node(char *, char *, char *);
	void close();
	void makeEmpty();
	void insert(char *, char *, char *);
	void remove(int ordernum);
	int search(char *);   
	void update(int, char *);
	void read_fromfile();
	void write_tofile();
};

#endif
