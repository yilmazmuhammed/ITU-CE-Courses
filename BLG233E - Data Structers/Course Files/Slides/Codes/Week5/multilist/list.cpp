// list.cpp 
// Defining the operations that we can perform on the multilist

#include <iostream> // allows program to perform input and output
#include <string.h> // program uses C++ standard string class 
#include "list.h" // include definition of struct List (multilist)

using namespace std; // enables the program to use all the names in any included standard C++ header 


// create list
void List::create()
{
	head = NULL; // create empty list 
	personcount = 0; // initialize personcount to 0
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
		char type[TNAME_LENGTH];
	};

	File_Record record; // create a File_Record object named record

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
	
	while ( !feof(phonebook) ){			
		// read an array of 1 element, each one with a size of sizeof(File_Record) bytes, 
		// from the stream phonebook and store them in the block of memory specified by &record
		fread( &record, sizeof(File_Record), 1, phonebook);
	
		if (feof(phonebook)) break;

		insert(record.name, record.phonenum, record.type); // insert new node with these values
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
		char type[TNAME_LENGTH];
	};

	File_Record record; // create a File_Record object named record

	Phone_node *names; // create a new phone node

	number *n;

	if ( !(phonebook = fopen( filename, "w+" ) ) ) { // create an empty file and open it for write/update (both for input and output)
			cerr << "File could not be opened" << endl; // standard error output is printed to the screen
			return;	
	}

	names = head; // point names to head 

	while (names) // while the end of the list has not been reached
	{
		n = names->phonenum;
		while (n){
			strcpy(record.name, names->name); // copy the string names->name into record.name
			strcpy(record.phonenum, n->num); // copy the string n->num into record.phonenum
			strcpy(record.type, n->type); // copy the string n->type into record.type	

			// write an array of 1 element, each one with a size of sizeof(File_Record) bytes, 
			// from the block of memory specified by &record to the stream phonebook
			fwrite(&record, sizeof(File_Record), 1, phonebook);
			n = n->next;
		}
		names = names->next;		
	}	
	fclose(phonebook); // close the file associated with the stream and disassociate it
}

// empty out the list 
void List::makeEmpty()
{
	Phone_node *p;
	number *q;
	while (head) {
		p = head;
		head = head->next;
		q = p->phonenum;
		while (q){
			p->phonenum = p->phonenum->next;
			delete q;
			q = p->phonenum;
		}
		delete p;
	}
	personcount = 0;
}

// insert new node 
Phone_node * List::create_node(char *name, char *phone, char *type){
	Phone_node *newperson;
	number *newnum;
	newperson = new Phone_node;
	strcpy(newperson->name, name);
	newnum = new number;
	newperson->phonenum = newnum;
	strcpy(newnum->num, phone);
	strcpy(newnum->type, type);
	newnum->next = NULL;
	newperson->next = NULL;
	return newperson;
}

// insert new phone record into list 
void List::insert(char *newname, char *newphone, char *newtype)
{
	Phone_node *traverse, *behind, *newperson;
	number *newnum;
	traverse = head;
	if (head == NULL) { // first node being added 
		head = create_node(newname, newphone, newtype);
		personcount++;
		return;
	}

	if ( strcmp(newname, head->name) < 0 ) { // insert to head of list (newname comes before head's name)
		newperson = create_node(newname, newphone, newtype);
		newperson->next = head;
		head = newperson;
		newperson++;
		return;
	}

	while ( traverse && (strcmp(newname, traverse->name) > 0) ) { // newname comes after traverse's name
		behind = traverse;
		traverse = traverse->next;
	}
	
	if (traverse && strcmp(newname, traverse->name) == 0){ // this name was added previously
		// just add the phone number
		newnum = new number;
		newnum->next = traverse->phonenum;
		traverse->phonenum = newnum;
		strcpy(newnum->num , newphone);
		strcpy(newnum->type, newtype);
	}
	else {
		newperson = create_node(newname, newphone, newtype);
		if (traverse) { // insert new name in between
			newperson->next = traverse;
			behind->next = newperson;
		}
		else // insert to the end
			behind->next = newperson;
		personcount++;
	}
}

// remove from the list all phone numbers and name of the person whose record order number is given
void List::remove(int ordernum) {
	Phone_node *traverse, *behind;
	number *pn;
	int counter = 1;
	traverse = head;

	if (ordernum <= 0){
		cout << "Invalid record order number.\n";
		return;
	}

	if (ordernum == 1){
		head = head->next;
		pn = traverse->phonenum;
		while (pn) {
			traverse->phonenum = pn->next;
			delete pn;
			pn = traverse->phonenum;
		}
		delete traverse;
		personcount--;
		return;
	}

	while ( (traverse != NULL) && (counter < ordernum) ) {
		behind = traverse;
		traverse = traverse->next;
		counter++;
	}

	if (counter < ordernum){ // given record num too large
		cout << "Could not find record to delete.\n";
	}
	else{ // record found
		behind->next = traverse->next;
		pn = traverse->phonenum;
		while (pn) {
			traverse->phonenum = pn->next;
			delete pn;
			pn = traverse->phonenum;
		}
		delete traverse;
		personcount--;
	}
}

// search the list for a name and print a list of found records
int List::search(char *target)
{
	Phone_node *traverse;
	number *pn;
	int counter = 0;
	int found = 0;
	traverse = head;
	bool all = false;

	if (target[0] == '*') // compare the string target to the string "*", if they are equal do the following
		all = true;

	while (traverse){
		counter++;
		if (all) {
            	cout << counter << "." << traverse->name << endl;
			pn = traverse->phonenum;
			while (pn){
				cout << pn->type << " : " << pn->num << endl;
				pn = pn->next;
			}
			found++;
		}
		else if (strncmp (target, traverse->name, strlen(target)) == 0){
			found++;
			cout << counter << ". record:" << traverse->name << endl;
			pn = traverse->phonenum;
			while (pn) {
				cout << pn->type << " : " << pn->num << endl;
				pn = pn->next;
			}
		}
		traverse = traverse->next;
	}
	return found;
}

// only update the name
void List::update(int recordnum, char *newname)
{
	Phone_node *traverse;
	int counter = 1;
	traverse = head;
	while (traverse && (counter < recordnum) ) {
		counter++;
		traverse = traverse->next;
	}
	if (traverse){
		strcpy(traverse->name, newname);
	}
	else
		cout << "Invalid record number for record to be updated.\n";
}
