#include<iostream>
#include <fstream> //file
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void Merge(vector<int>& V1, vector<int>& V2, vector<int>& out) {
	sort(V1.begin(), V1.end());    // sort first half	
	sort(V2.begin(), V2.end());    // sort second half
	merge(V1.begin(), V1.end(), V2.begin(), V2.end(), out.begin()); // merge two half
};

void PrintVector(const vector< vector<int> >& V){
	for (int i = 0; i < V.size(); i++) {  // vector by vector
		cout << "i=" << i << "    " ;
		for (int j = 0; j < V[i].size(); j++)
			cout <<  V[i][j] << " ";  // print the value of the vector
		cout << endl;
	}		
	cout << endl;
};

class ASA {
	public:
		vector< vector<int> > D, _D;
		ASA(): D(1), _D(1) {};
		void Insert(int x) {
			_D[0].push_back(x);
			for (int level = 0; ; level++) {
				if (level >= D.size()){  // make a new empty vector
					vector<int> newVec;
					D.push_back(newVec);
					D[level].clear();
				}
				if (D[level].empty()) {
					//copy _D[level] to D[level] 
					vector<int> newVec;			
					newVec.assign(_D[level].begin(), _D[level].end());
					D[level].assign(newVec.begin(), newVec.end());
					_D[level].clear();
					return;
				}
				else {
					//merge D[level] & _D[level] and save to _D[level+1]
					vector<int> newVec(D[level].size() + _D[level].size());
					Merge(D[level], _D[level], newVec);
					if (level+1 >= _D.size()){  // make a new empty vector
						_D.push_back(newVec);
						_D[level+1].clear();
					}
					//cout << level+1 << " " << _D.size() << endl;
					_D[level+1].assign(newVec.begin(), newVec.end());
					_D[level].clear();
					D[level].clear();			
				}
			}
		};

		void Print(){
			cout << "===============" << endl;
			PrintVector(D);
			cout << "_______________" << endl;
			PrintVector(_D);
			cout << "===============" << endl;
		}

		bool Search(int x) {
			for (int i=0; i<D.size(); ++i){
				if (binary_search(D[i].begin(), D[i].end(), x)){  // use std::binary_search to search the value in this vector
					return true;
				}
			}
			return false;
		};
};

void InsertRandNum(ASA& t, int kN, int kRandNum) 
{
	for(int s=0; s<kN; s++) // repeat kN times
	{
		int no = rand()%kRandNum;  // choose an random num from 1 to kRandNum
		t.Insert(no);  // insert this number to the ASA
	}
}

void SerchRandNum(ASA& t, int kRandNum)
{
	for(int s=0; s<1000000; s++)  // repeat 1000,000 times
	{
		int no = rand()%kRandNum;  /// choose an random num from 1 to kRandNum
		if(t.Search(no)){  // search this number in the ASA
		}
	}
}
int main(int argc, char *argv[]) {
	// open file to write the data
	ofstream ofs;
	ofs.open("Result.csv", ofstream::app);
	int kExp = atoi(argv[1]);
	time_t startInsert, endInsert;
	time_t startSearch, endSearch;
	double durationInsert, durationSearch;
	srand(time(NULL));

	// make the input array with random variable
	ASA t;
	startInsert = clock();
	InsertRandNum(t, pow(2.0, kExp), pow(2.0, 30));
	endInsert = clock();
	durationInsert = (double) (endInsert-startInsert) / CLOCKS_PER_SEC;
	ofs << "Insert" << "," << kExp << "," << durationInsert << ",";

	// search a random num in the data structure	
	startSearch = clock();
	SerchRandNum(t, pow(2.0, 30));
	endSearch = clock();
	durationSearch = (double) (endSearch-startSearch) / CLOCKS_PER_SEC;
	ofs << "Search" << "," << kExp << "," << durationSearch << endl;

	// close the file
	ofs.close();
	return 0;
}

