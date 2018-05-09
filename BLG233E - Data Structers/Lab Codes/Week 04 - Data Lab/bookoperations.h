/* @Author
 * Muhammed YILMAZ
 * yilmazmu15@gmail.com
 * 2017 Spring
 */

#ifndef DOSYAISLEMLERI_H
#define DOSYAISLEMLERI_H
#include <stdio.h>
#include "record.h"

struct file {
	phone_type *phoneTypeArray;
	bool create();
	bool increase();
	bool add(phone_type *newrecord);
	bool remove(int recordNumber);
	bool list();
	int search(char *searched);
	bool update(char *updated);
	int recordnumber;
};
#endif