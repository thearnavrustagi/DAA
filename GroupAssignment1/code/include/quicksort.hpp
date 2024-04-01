 #ifndef QUICKSORT_H
#define QUICKSORT_H

#include "sortable.hpp"
#include "swap.hpp"

/**
 * partition
 * arguments:
 * - T* array    : this is the array which needs to be partitioned inplace
 * - int left    : this is the left index of the sub array
 * - int right   : this is the right index of the sub array
 * - int* middle : the pointer to the middle integer, this is mutated
 * 
 * returns:
 * - int, the number of comparisions
 *
 * This function partitions the array based on a pivot
*/
template<Sortable T>
int partition(T* array, int left, int right, int *middle)
{
 
    T pivot = array[left];
    int l_itr = left;
    int r_itr = right;
    int comparisions = 0;

    while (l_itr < r_itr) {
	    while (!(array[l_itr] > pivot || l_itr > right)) ++comparisions && l_itr++;
	    while (array[r_itr] > pivot && !(r_itr < left)) ++comparisions && r_itr--;

	    if (l_itr < r_itr) {
		    swap(array[l_itr], array[r_itr]);
	    }
    }

    *middle = r_itr;
    swap(array[*middle], array[left]);

    return comparisions;
}
 
/**
 * quicksort
 * arguments:
 * - T* array  : this is the array which needs to be sorted inplace
 * - int left  : this is the left index of the sub array
 * - int right : this is the right index of the sub array
 * 
 * returns:
 * - int : the number of comparisions
 *
 * This function sorts an array using quicksort, it creates pivots which
 * has smaller values on the left and higher values on the right
*/
template<Sortable T>
int quicksort(T *arr, int left, int right)
{
 
    if (left >= right) return 0;
 
    int middle = 0;
    int comparisions = partition(arr, left, right, &middle);
 
    comparisions += quicksort(arr, left, middle - 1);
    comparisions += quicksort(arr, middle + 1, right);
    return comparisions;
}

#endif
