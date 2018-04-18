// node.h
// Phone_node struct definition for node of a doubly linked list

#define NAME_LENGTH 30 // replace all subsequent occurrences of the symbolic constant NAME_LENGTH with 30
#define PHONENUM_LENGTH 15 // replace all subsequent occurrences of symbolic constant PHONENUM_LENGTH with 15

// Phone_node struct definition
struct Phone_node{
	char name[NAME_LENGTH];	// name data stored in this Phone_node
	char phonenum[PHONENUM_LENGTH]; // phonenum data stored in this Phone_node
	Phone_node *next; // pointer to next object of the same type
	Phone_node *previous; // pointer to previous object of the same type
};