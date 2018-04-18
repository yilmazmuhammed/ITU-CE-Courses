/* @Author
 * Muhammed YILMAZ
 * yilmazmu15@gmail.com
 * 2017 Spring
 */

#ifndef YAPILAR_H
#define YAPILAR_H

struct konum
{
	int row;
	int col;
};

struct stackKonum
{
	int row;
	int col;
	stackKonum *prev;
};

#endif