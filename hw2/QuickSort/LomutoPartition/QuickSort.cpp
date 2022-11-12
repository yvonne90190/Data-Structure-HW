/* C++ implementation of QuickSort using Hoare's
   partition scheme. */
//#include <bits/stdc++.h>
#include <algorithm> // Needed for swap
using namespace std;

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int Lomuto_partition(int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void Lomuto_quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = Lomuto_partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        Lomuto_quickSort(arr, low, pi - 1);
        Lomuto_quickSort(arr, pi + 1, high);
    }
}
