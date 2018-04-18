/* @Author
 * Muhammed YILMAZ
 * yilmazmu15@gmail.com
 * 2017 Spring
 */

#ifndef TEMP_H
#define TEMP_H
#include "car.h"

struct stTempArea
{
	stCar *tepeEleman;
	stCar *tailEleman;
	void create();
	void push(char *tempPlaka);
	bool pull();
	void show();
	stCar top();
};

#endif