// list.cpp 
// Defining the operations that we can perform on the doubly linked list

#include <iostream> // allows program to perform input and output
#include <string.h> // program uses C++ standard string class 
#include "list.h" // include definition of struct List (doubly linked list)

using namespace std; // enables the program to use all the names in any included standard C++ header 

// create list
void List::create()
{
	head = NULL; // create empty list  
	tail = NULL;
	nodecount = 0; // initialize nodecount to 0
	read_fromfile();
}

// close list 
void List::close()
{
	write_tofile();
	makeEmpty();
}

// read phone records from file into list 
void List::read_fromfile()
{
	// File_Record struct definition
	struct File_Record{
		char name[NAME_LENGTH];	
		char phonenum[PHONENUM_LENGTH];
	};

	File_Record record; // create a File_Record object named record

	Phone_node *newnode; // create a new phone node 

	filename = "phonebook.txt"; // filename is a character array that is a member of the List struct

	// open the file filename and associate it with a stream that can be identified in future operations by the FILE pointer returned into phonebook
	// if the file is not successfully opened, a null pointer is returned 
	// "r+" indicates that the file is opened in read/update (both for input and output) mode
	// the file filename must exist
	if ( !(phonebook = fopen(filename, "r+") ) ) { 
		if ( !(phonebook = fopen(filename, "w+") ) ) { // create an empty file and open it for write/update (both for input and output)
			cerr << "File could not be opened." << endl; // standard error output is printed to the screen
			cerr << "Will work in memory only." << endl;
			return;		
		}
	}

	fseek(phonebook, 0, SEEK_SET); // set the position indicator associated with the stream phonebook to a new position defined by SEEK_SET + 0  
	
	while ( !feof(phonebook) ) // check whether the end-of-File indicator associated with stream phonebook is set, returning a value different from zero if it is
	{			
		newnode = new Phone_node; // allocate storage for object newnode of type Phone_node

		// read an array of 1 element, each one with a size of sizeof(File_Record) bytes, 
		// from the stream phonebook and store them in the block of memory specified by &record
		fread( &record, sizeof(File_Record), 1, phonebook);	
	
		if ( feof(phonebook) ) break; // check whether the end-of-File indicator associated with stream phonebook is set, returning a value different from zero if it is
		strcpy(newnode->name, record.name); // copy the string record.name into newnode->name
		strcpy(newnode->phonenum, record.phonenum); // copy record.phonenum into newnode->phonenum
		
		newnode->next=NULL;

		insert(newnode);
	}
	fclose(phonebook); // close the file associated with the stream and disassociate it
}

// write phone records from list into file
void List::write_tofile()
{
	// File_Record struct definition
	struct File_Record{
		char name[NAME_LENGTH];	
		char phonenum[PHONENUM_LENGTH];
	};

	File_Record record; // create a File_Record object named record

	Phone_node *p; // create a new phone node

	if ( !(phonebook = fopen( filename, "w+" ) ) ) { // create an empty file and open it for write/update (both for input and output)
			cerr << "File could not be opened" << endl; // standard error output is printed to the screen
			return;	
	}

	p = head; // point p to head 

	while (p) // while the end of the list has not been reached
	{
		strcpy(record.name, p->name); // copy the string p->name into record.name
		strcpy(record.phonenum, p->phonenum); // copy the string p->phonenum into record.phonenum

		// write an array of 1 element, each one with a size of sizeof(File_Record) bytes, 
		// from the block of memory specified by &record to the stream phonebook
		fwrite(&record, sizeof(File_Record), 1, phonebook);
		p = p->next;		
	}	
	fclose(phonebook); // close the file associated with the stream and disassociate it
}

// empty out the list 
void List::makeEmpty()
{
	Phone_node *p;
	while (head){
		p = head;
		head = head->next;
		delete p;
	}
	nodecount = 0;
}

// insert new phone record into list 
void List::insert(Phone_node *toadd)
{
	Phone_node *traverse, *newnode;

	traverse = head;

	newnode = new Phone_node;
	*newnode = *toadd;	
	newnode->previous = NULL;
	newnode->next = NULL;

	if (head == NULL) { // first node being added
		head = newnode;
		tail = newnode;
		nodecount++;
		return;
	}

	if (strcmp(newnode->name, head->name) < 0) { // insert to head of list (newnode's name comes before head's)
		newnode->next = head;
		head = newnode;
		(newnode->next)->previous = newnode;
		nodecount++;
		return;
	}

	while ( traverse && (strcmp(newnode->name,traverse->name) > 0) ) { // newnode's name comes after traverse's
		traverse = traverse->next;
	}
	if (traverse){ // insert in between
		newnode->next = traverse;
		newnode->previous = traverse->previous;
		(traverse->previous)->next = newnode;
		traverse->previous = newnode;
	}
	else{ // insert to end 
		tail->next = newnode;
		newnode->previous = tail;
		tail = newnode;
	}
	nodecount++;
}

// remove phone record from list
void List::remove(int ordernum)
{
	Phone_node *traverse;
	int counter = 1;
	traverse = head;

	if (ordernum <= 0) {
		cout << "Invalid record order number.\n";
		return;
	}

	if (ordernum == 1) {
		head = head->next;
		head->previous = NULL;
		delete traverse;
		nodecount--;
		return;
	}

	while ( (traverse != NULL) && (counter < ordernum) ) {
		traverse = traverse->next;
		counter++;
	}

	if (counter < ordernum){ // given record num too large
		cout << "Could not find record to delete.\n";
	}
	else{ // record found
		(traverse->previous)->next = traverse->next;
		if (traverse->next)
			traverse->next->previous = traverse->previous;
		else
			tail = traverse->previous;
		delete traverse;
		nodecount--;
	}
}

// search the list for a name 
int List::search(char *target)
{
	Phone_node *traverse;
	int counter = 0;
	int found = 0;
	traverse = head;
	bool all = false;

	if (target[0] == '*') // compare the string target to the string "*", if they are equal do the following
		all = true;

	while (traverse){
		counter++;
		if (all){
            	cout << counter << "." << traverse->name << " " << traverse->phonenum << endl;
			found++;
		}
		else if (strncmp(target, traverse->name, strlen(target)) == 0){ // if strings traverse->name and target are equal up to the length of target 
			found++;
			cout << counter << "." << traverse->name << " " << traverse->phonenum << endl;
		}
		traverse = traverse->next;
	}
	return found;
}

// update a phone record in the list 
void List::update(int recordnum, Phone_node *newnode)
{
	Phone_node *traverse;
	int counter = 1;
	traverse = head;
	while (traverse && (counter < recordnum) ) {
		counter++;
		traverse = traverse->next;
	}
	if (traverse){
		newnode->next = traverse->next;
		*traverse = *newnode;
	}
	else
		cout << "Invalid record number for record to be updated.\n";
}
