// node.h
// Phone_node struct definition (for multilist)

#define NAME_LENGTH 30 // replace all subsequent occurrences of the symbolic constant NAME_LENGTH with 30
#define PHONENUM_LENGTH 15 // replace all subsequent occurrences of symbolic constant PHONENUM_LENGTH with 15
#define TNAME_LENGTH 4 // replace all subsequent occurrences of symbolic constant TNAME_LENGTH with 4

// number struct definition
struct number{
    char type[TNAME_LENGTH]; // phone type name data stored in this number
    char num[PHONENUM_LENGTH]; // phonenum data stored in this number
    number *next;
};

// Phone_node struct definition
struct Phone_node{
	char name[NAME_LENGTH];	// name data stored in this Phone_node	
	number *phonenum; // phonenumber struct data stored in this Phone_node
	Phone_node *next; // pointer to next object of the same type
};
