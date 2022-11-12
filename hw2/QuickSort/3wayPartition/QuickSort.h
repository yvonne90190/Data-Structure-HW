//https://www.geeksforgeeks.org/3-way-quicksort-dutch-national-flag/
// C++ program for 3-way quick sort

/* This function partitions a[] in three parts
   a) a[l..i] contains all elements smaller than pivot
   b) a[i+1..j-1] contains all occurrences of pivot
   c) a[j..r] contains all elements greater than pivot */
void partition_3way(int a[], int l, int r, int& i, int& j);
// 3-way partition based quick sort
void quicksort_3way(int a[], int l, int r);