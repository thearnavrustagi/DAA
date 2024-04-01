#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <iostream>
#include "sortable.hpp"
#include "swap.hpp"

#define LEFT(x) (2 * (x))
#define RIGHT(x) (2 * (x) + 1)
#define PARENT(x) ((x) / 2)

/**
 * maxHeapify
 * arguments:
 * - T* array     : the input array to be modified (inplace)
 * - int heapsize : size of the heap in the array
 * - int idx      : the node of the tree where you are supposed
 *   to make the max heap
 * returns:
 * - int : the number of comparisions done
 *
 * This function ensures that the max heap property is maintained
 */
template <Sortable T>
int maxHeapify(T *array, int heapsize, int idx)
{
    int left = LEFT(idx);
    int right = RIGHT(idx);
    int maximum;
    int comparisions = 0;

    if (left < heapsize && array[left] > array[idx])
    {
        maximum = left;
        comparisions++;
    }
    else
    {
        maximum = idx;
        comparisions += left < heapsize; // checking if the second half was not short circuited
    }

    if (right < heapsize && array[right] > array[maximum])
    {
        maximum = right;
    }

    comparisions += right < heapsize; // checking short circuit

    if (maximum != idx)
    {
        swap(array[idx], array[maximum]);
        return comparisions + maxHeapify(array, heapsize, maximum);
    }
}

/**
 * buildHeap
 * arguments:
 * - T* array     : this is the array in which the heap should be made
 * - int heapsize : this is the size of the heap to be built
 *
 * returns:
 * - int: the number of comparisions done
 *
 * This function creates a heap by calling the maxHeapify function
 */
template <Sortable T>
int buildHeap(T *array, int heapsize)
{
    int comparisions = 0;
    for (int idx = (heapsize / 2) + 1; idx > -1; idx--)
    {
        comparisions += maxHeapify(array, heapsize, idx);
    }

    return comparisions;
}

/**
 * heapsort
 * arguments:
 * - T* array   : this is the array which needs to be sorted inplace
 * - int length : this is the length of the array
 *
 * returns:
 * - int: the number of comparisions done
 *
 * This function sorts an array using heapsort, it creates max heaps in
 * place and then uses them to sort the array in an ascending order
 */
template <Sortable T>
int heapsort(T *array, int length)
{
    int comparisions = buildHeap(array, length);
    int heapsize = length;

    for (int idx = length - 1; idx > -1; idx--)
    {
        T temp = array[0];
        array[0] = array[idx];
        array[idx] = temp;

        comparisions += maxHeapify(array, --heapsize, 0);
    }

    return comparisions;
}

#endif
