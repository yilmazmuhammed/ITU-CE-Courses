/* @Author
 * Muhammed YILMAZ
 * yilmazmu15@gmail.com
 * 2017 Spring
 */

#ifndef STACK_H
#define STACK_H

#include "yapilar.h"

struct stack
{
	stackKonum *tepeEleman;
	void create();
	void push(stackKonum *ekle);
	void pull();
	void show(FILE *dg);
	stackKonum top();
};

#endif