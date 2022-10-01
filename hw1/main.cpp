#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <fstream>
#include <vector>
#include <numeric>
//#include "dynamic_arr.cpp"
#include "linked_list.h"

using namespace std;

int main(int argc, char *argv[]) {
	ofstream ofs;
	ofs.open("ds_hw1.csv", ofstream::app);
	int kNum = atoi(argv[1]);
	int n;
	time_t start, end;
	double duration;
	int sum;
	ofs << kNum << ",";
	
	// Add elements in Linked List
	ofs << "Linked  List" << ",";
	struct Node* head = NULL;
	start = clock();
	n = 0;
	while( n++ < pow(2.0, kNum) ){
		int i = rand() % 10;	
		push(&head, i);
	}
	end = clock();
	duration = (double) (end-start) / CLOCKS_PER_SEC;
	ofs << duration << ",";
	// Sum elements in Linked List
	start = clock();
	sum = sumOfNodes(head);
	end = clock();
	duration = (double) (end-start) / CLOCKS_PER_SEC;
	ofs << sum << ",";
	ofs << duration << ",";
	
	// Add element in Dynamic Array
	ofs << "Dynamic Array" << ",";
	vector<int> v;
	srand( time(NULL) );
	n = 0;
	start = clock();
	while( n++ < pow(2.0, kNum) ){
		int i = rand() % 10;
		v.push_back(i);
	}
	end = clock();
	duration = (double) (end-start) / CLOCKS_PER_SEC;
	ofs << duration << ",";   
	// Sum the elements in Dynamic Array
	start = clock();
	sum = accumulate(v.begin(), v.end(), 0);
	end = clock();
	duration = (double) (end-start) / CLOCKS_PER_SEC;
	ofs << sum << ",";
	ofs << duration << ",";
	
	ofs << endl;
	ofs.close();

	return 0;
}
