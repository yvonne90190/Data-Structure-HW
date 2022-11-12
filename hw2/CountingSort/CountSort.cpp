// Counting sort in C++ programming
//https://www.sanfoundry.com/cpp-program-implement-counting-sort/
#include "CountSort.h"
#include <iostream>

using namespace std;
  
// A function implementing Counter sort.
void counterSort(int a[], int n)
{
    
	int i, j = 0, counter[1000] = {0};	
	// Counting the number occurrence of each element.
	for(i=0; i<n; i++)
		counter[a[i]]++;
 
	i=0;
	// placing the elements back into array.
	while(i < 1000)
	{
		while(counter[i] > 0){ // place the same element until its counter is zero.
		    a[j] = i;
		    j++;
		    counter[i]--;
		    
        }
        i++;
	}
    
}