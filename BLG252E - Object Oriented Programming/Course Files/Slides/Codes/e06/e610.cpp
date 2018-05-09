// e610.cpp
// http://www.buzluca.info/oop/
// Multiple Inheritance 
#include<iostream>
using namespace std;

class Base1{        // Base 1
 public:
	void f1(){cout << "Base1 f1" << endl;}
	char *f2(int){cout << "Base1 f2" << endl; return 0;}
};

class Base2{      // Base 2
 public:
	char *f2(int, char){cout << "Base2 f2" << endl; return 0;}
	int f3(){cout << "Base2 f3" << endl; return 0;}
	void f4(){cout << "Base2 f4" << endl;}
};

// ** Derived is derived from Base1 and Base1 **
class Derived : public Base1 , public Base2{
 public:
	float f1(float){cout << "Derived f1" << endl; return 1.0;}
	void f4(){cout << "Derived f4" << endl;}
	int f5(int){cout << "Derived f5" << endl; return 0;}
};

int main()
{
	Derived d;
	float y=d.f1(3.14);				// Derived::f1
	d.f3();							// Base2::f3
	d.f4();							// Derived::f4
	d.Base2::f4();					// Base2::f4
	//d.f1();						// ERROR
	d.Base1::f1();					// Base1::f1
	//char *c = d.f2(1);			// ERROR
	char *c = d.Base1::f2(1);		// Base1::f2
	char *cc = d.Base2::f2(1,'A');	// Base2::f2

	return 0;
}
