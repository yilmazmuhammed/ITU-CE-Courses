#include <iostream>
using namespace std;


int main(int argc, char* argv[]){
	float x, y;
	int *p;
	x = 10.25; y = 20.89;
	p = &x;    // can assign any address to p 
	y = *p;   

	return 0;
}