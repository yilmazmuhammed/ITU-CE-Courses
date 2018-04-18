// BLG 221E Data Structures
// This program uses students' exam grades stored as a two-dimensional array to compute the class average

#include <iostream>
using namespace std;

int main(){
	int grades[3][10]={{50,86,55,45,70,12,43,12,76,90},{55,13,45,45,65,13,45,30,55,95},{45,60,75,10,76,10,80,35,65,98}};
	cout.precision(2);
	float sum = 0, grandsum = 0;
	for (int i = 0; i < 3; i++){		// for each of the three exams
		sum = 0;
		for (int j = 0; j < 10; j++)
			sum += grades[i][j];
		cout << i + 1 <<". exam average=" << fixed << sum/10 << endl;		
	}
	
	for (int i = 0; i < 10; i++){   // for each of the 10 students
		toplam=0;
		for(int j=0;j<3;j++)
			sum += grades[j][i];
		cout << i + 1 <<". student average=" << fixed << sum/3 << endl;		
		grandsum += (sum/3);
	}

	cout << "Class average=" << fixed << (grandsum/10)<<endl;	 
	getchar();
	return EXIT_SUCCESS;
}

