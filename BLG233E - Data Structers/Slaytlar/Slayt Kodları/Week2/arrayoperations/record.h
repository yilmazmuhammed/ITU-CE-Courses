// record.h
// Phone_Record struct definition

#define NAME_LENGTH 30 // replace all subsequent occurrences of the symbolic constant NAME_LENGTH with 30
#define PHONENUM_LENGTH 15 // replace all subsequent occurrences of symbolic constant PHONENUM_LENGTH with 15

// Phone_Record struct definition
struct Phone_Record{
	char name[NAME_LENGTH];	// name data stored in this Phone_Record
	char phonenum[PHONENUM_LENGTH]; // phonenum data stored in this Phone_Record
};