// e46.cpp
//	Static Members
// http://www.buzluca.info/oop

#include <iostream>
using namespace std;

class A{
  char c;
  static int number;						//  Number of created objects (static data)
 public:
	 static void clearNumber(){number=0;}	// Static function to initialize number
  A(){number++; cout<<  "Constructor "<< number << endl;} //Constructor
  ~A(){number--; cout<<  "Destructor "<< number << endl;} //Destructor
};

int A::number;     // Allocating memory for number

// ----- Main function -----
int main()
{
 cout <<"  Entering 1. BLOCK............" << endl;
 A::clearNumber();											// The static function is called
 A a,b,c;
  {
    cout << endl << "  Entering 2. BLOCK............" << endl;
    A d,e;
    cout << endl << "  Exiting 2. BLOCK............" << endl;
  }
  cout << endl << "  Exiting 1. BLOCK............" << endl;
  return 0;
}