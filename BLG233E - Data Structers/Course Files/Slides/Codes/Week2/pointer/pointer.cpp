#include <iostream>
using namespace std;


int main(int argc, char* argv[]){
	int t[3] = {1,2,3};
	int *ptr = t;
	cout << t[0] << "\t" << t[1] << "\t" << t[2] << endl;
	*ptr = 8;	
	(*ptr)++;
	cout << t[0] << "\t" << t[1] << "\t" << t[2] << endl;
	*ptr++ = 5;
	cout << t[0] << "\t" << t[1] << "\t" << t[2] << endl;
	*ptr = 6;
	cout << t[0] << "\t" << t[1] << "\t" << t[2] << endl;
	(*++ptr)++;
	cout << t[0] << "\t" << t[1] << "\t" << t[2] << endl;
	return 0;
}