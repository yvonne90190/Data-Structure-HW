/*
 * C++ Program to Implement Hash Tables chaining 
 * with Singly Linked Lists
 */
#include <unordered_set>
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
#include <fstream> //file
#include <cmath>
#include<time.h>
using namespace std;
 
void InsertRandNum(std::unordered_set<int>& t, int kN, int kRandNum) 
{
	for(int s=0; s<kN; s++)  // repeat kN times
	{
		int no = rand()%kRandNum;  // choose an random num from 1 to kRandNum
		t.insert(no);  // insert the number in the data structure
	}
}

void SerchRandNum(std::unordered_set<int>& t, int kRandNum)
{
	for(int s=0; s<1000000; s++)  // repeat 1000,000 times
	{
		int no = rand()%kRandNum;   // choose a random num in 1~2^30
		if(t.find(no) != t.end()){}  // search the number in the data structure
	}
}

int main(int argc, char *argv[]) {
	// open file to write the data
	ofstream ofs;
	ofs.open("Result.csv", ofstream::app);
	int kExp = atoi(argv[1]);
	time_t startInsert, endInsert;
	time_t startSearch, endSearch;
	double durationInsert=0.0, durationSearch;
	srand(time(NULL));

	// make the input array with random variable
	std::unordered_set<int> myunordered_set;  // unordered_set can represent hash table
	startInsert = clock();
	InsertRandNum(myunordered_set, pow(2.0, kExp), pow(2.0, 30));
	endInsert = clock();
	durationInsert = (double) (endInsert-startInsert) / CLOCKS_PER_SEC;
	ofs << "Insert" << "," << kExp << "," << durationInsert << ",";
	
	// search a random num in the data structure	
	startSearch = clock();
	SerchRandNum(myunordered_set, pow(2.0, 30));
	endSearch = clock();
	durationSearch = (double) (endSearch-startSearch) / CLOCKS_PER_SEC;
	ofs << "Search" << "," << kExp << "," << durationSearch << endl;
	
	// close the file
	ofs.close();
	return 0;
}

