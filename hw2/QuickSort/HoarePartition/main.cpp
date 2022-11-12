#include <iostream>
#include <fstream> //file
#include <tgmath.h> //pow() 
#include<time.h>
#include<stdlib.h>

#include "QuickSort.h"

using namespace std;

int* fillArrayWithRandNum(int arr[], int size) //return type- address of integer array
{
	//static int arr[size]; //array declared as static
	
	for(int s=0; s<size; s++)
	{
		int no = rand()%1000;
		arr[s]=no;
	}
	return arr; //address of a returned
}

int main(int argc, char *argv[]) {
	// open file to write the data
	ofstream ofs;
	ofs.open("Hoare.csv", ofstream::app);
	int kNum = atoi(argv[1]);
	time_t start, end;
	double duration;
	double duration_sum=0.0, duration_avg;
	int size = pow(2.0, kNum);  //2^k
	srand(time(NULL));

	for (int j=0; j<10; ++j){
		// make the input array with random variable
		int* arr = new int[size];
		fillArrayWithRandNum(arr, size);
		// sort the array
		start = clock();
        HoareQuickSort(arr, 0, size);
		end = clock();
		// count the duration
		duration = (double) (end-start) / CLOCKS_PER_SEC;
		duration_sum += duration;
		delete [] arr;
	}

	// count the average duration
	duration_avg = duration_sum / (double)10;
	ofs << kNum << "," << "Hoare" << "," << duration_avg << endl;
	
	// close the file
	ofs.close();
	return 0;
}
