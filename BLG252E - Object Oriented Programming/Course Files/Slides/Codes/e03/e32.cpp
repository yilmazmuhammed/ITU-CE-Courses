// e32.cpp
// this Pointer
// http://www.buzluca.info/oop

#include <iostream>
using namespace std;

class Point{				// Delaration Point Class
	int x,y;					// Properties: x ve y coordinates
 public:
	void move(int, int);	// A function to move points
	void print();			// to prints cordinates on the screen
	bool is_zero();		// is point on the zero point(0,0)
	Point *Point::far_away(Point &); // Finds the point that has the largest distance from (0,0)
};

// ***** Bodies of Member Functions *****

// A function to move the points 
void Point::move(int new_x, int new_y)
{
	x = new_x;				// assigns new value to x coordinat
	y = new_y;				// assigns new value to y coordinat 
}

// To print the coordinates on the screen 
void Point::print()
{
	cout << "X= " << x << ", Y= " << y << endl;
}
				
// is the point on the zero point(0,0)
bool Point::is_zero()
{
	return (x == 0) && (y == 0);	  
}


// Finds the point that has the largest distance from (0,0)
Point *Point::far_away(Point &p)
{
	unsigned long x1 = x*x;				
	unsigned long y1 = y*y;
	unsigned long x2 = p.x * p.x;
	unsigned long y2 = p.y * p.y;
	if ( (x1+y1) > (x2+y2) ) return this;
	else return &p;
}

int main()
{
	Point point1,point2;		// 2 objects: point1 , point2
	point1.move(100,50);		// point1 to (100,50)
	point2.move(20,65);			// point2 to (20,65)
	Point *pointer;				// pointer is a pointer to points
	pointer=point1.far_away(point2);
	pointer->print();				// the point that has the largest distanece on the screen
	return 0;
}
