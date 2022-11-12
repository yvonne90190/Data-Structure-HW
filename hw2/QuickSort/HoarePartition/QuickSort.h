
//https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/
/* C++ implementation of QuickSort using Hoare's
   partition scheme. */

/* This function takes first element as pivot, and places
   all the elements smaller than the pivot on the left side
   and all the elements greater than the pivot on
   the right side. It returns the index of the last element
   on the smaller side*/
int HoarePartition(int arr[], int low, int high);

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void HoareQuickSort(int arr[], int low, int high);
