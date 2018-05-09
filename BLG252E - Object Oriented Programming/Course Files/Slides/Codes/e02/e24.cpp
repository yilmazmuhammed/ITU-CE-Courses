// e24.cpp
// http://www.faculty.itu.edu.tr/buzluca
// http://www.buzluca.info/
//Return by reference

#include <iostream>

// max  function returns a refference to the largest element of an array
int&  max(const int a[], int length)			
{
   int i=0;    								// i is indices of the largest element
   for (int j=0 ; j<length ; j++)	
	   if (a[j] > a[i])  i = j;
   return const_cast<int &> (a[i]);		// returns refference to a[i]
}

int main()
{
   int array[] = {12, -54 , 0 , 123, 63};	// An aray with 5 elements
   max(array,5) = 0;								// Write 0 on the largest element
   for(int i=0; i<5; i++) std::cout << array[i] << " ";       // array on the screen
   return 0;
}

