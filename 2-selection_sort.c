#include "sort.h"

/**
 * selection_sort - Sorts an array of onteger in ascending order using
 * selection sort algorithm.
 * 
 * @array: the array of integers to be sorted
 * @size: the size of the array.
 * 
 * Return: none
*/

void selection_sort(int *array, size_t size)
{
    size_t i, j, mid;
    int tmp;

    for (i=0; i < size - 1; i++)
    {
        mid = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[mid])
                mid = j;
        }
        if (mid != i)
        {
            tmp = array[i];
            array[i] = array[mid];
            array[mid, size];
        }
    }
}
