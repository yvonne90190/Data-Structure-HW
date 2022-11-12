/* C++ implementation of QuickSort using Hoare's
   partition scheme. */
//#include <bits/stdc++.h>
#include <algorithm> // Needed for swap
using namespace std;
 
/* This function takes first element as pivot, and places
   all the elements smaller than the pivot on the left side
   and all the elements greater than the pivot on
   the right side. It returns the index of the last element
   on the smaller side*/
int HoarePartition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
 
    while (true) {
        // Find leftmost element greater than
        // or equal to pivot
        do {
            i++;
        } while (arr[i] < pivot);
 
        // Find rightmost element smaller than
        // or equal to pivot
        do {
            j--;
        } while (arr[j] > pivot);
 
        // If two pointers met.
        if (i >= j)
            return j;
 
        swap(arr[i], arr[j]);
    }
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void HoareQuickSort(int arr[], int low, int high)
{
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = HoarePartition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        HoareQuickSort(arr, low, pi);
        HoareQuickSort(arr, pi + 1, high);
    }
}