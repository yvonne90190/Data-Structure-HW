//https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int Lomuto_partition(int arr[], int low, int high);

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void Lomuto_quickSort(int arr[], int low, int high);