/* @Author
 * Muhammed YILMAZ
 * yilmazmu15@gmail.com
 * 2017 Spring
 */

#include "bookoperations.h"
#include <iostream>
//#include <stdlib.h>
//#include <string.h>
//#include <stdio.h>

using namespace std;
typedef file prog;
prog phonebook;

void print_menu();
bool do_operation(char);
bool add_record();

int main()
{
	phonebook.create();
	bool finish = false;
	char menuOperation;
	while (!finish)
	{
		print_menu();
		cin >> menuOperation;
		finish = do_operation(menuOperation);
	}
	return EXIT_SUCCESS;
}

bool do_operation(char menuOperation)
{
	switch (menuOperation)
	{
	case 'e':	case 'E':
		return EXIT_FAILURE;
	case 'a':	case 'A':
		add_record();
		break;

	default:
		cout << "Please choose valid operation!!!" << endl;
	}
	return EXIT_SUCCESS;
}

void print_menu()
{
	cout << "Phonebook aplication menu" << endl;
	cout << "Choose an operation" << endl;
	cout << "a -> Add record" << endl;
	cout << "e -> Exit" << endl;
}

bool add_record()
{
	phone_type newRecord;

	if (phonebook.add(&newRecord) == EXIT_FAILURE)
	{
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
