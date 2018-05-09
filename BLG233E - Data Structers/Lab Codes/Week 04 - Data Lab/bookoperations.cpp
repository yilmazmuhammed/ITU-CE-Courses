/* @Author
 * Muhammed YILMAZ
 * yilmazmu15@gmail.com
 * 2017 Spring
 */

#include "bookoperations.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

bool file::create()
{
	recordnumber = 0;
	phoneTypeArray = (phone_type*) malloc(sizeof(phone_type) * 10);
	return EXIT_SUCCESS;
}

bool file::increase()
{
	phoneTypeArray = (phone_type*) realloc(phoneTypeArray, sizeof(phone_type) * 10);
	return EXIT_SUCCESS;
}

bool file::add(phone_type *newrecord)
{
	recordnumber++;

	if (recordnumber % 10 == 0)
	{
		cout << "increase" << endl;
		increase();
	}
	cout << "sass" << endl;
	//phoneTypeArray[recordnumber] = newrecord;
	strcpy(phoneTypeArray[recordnumber].name, newrecord->name);
	strcpy(phoneTypeArray[recordnumber].phonenumber, newrecord->phonenumber);
	return EXIT_SUCCESS;
}