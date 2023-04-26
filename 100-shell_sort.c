#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using
 *          Shell Sort Algorithm
 * @array: the array of integers to be sorted
 * @size: size of the @array
 * 
 * Return: void
*/

void shell_sort(int *array, size_t size)
{
    size_t interval = 1;
    size_t i, j;
    int tmp;

    /* calculate interval sequence*/
    while (interval < size / 3)
        interval = interval * 3 + 1;
    
    while (interval >= 1)
    {
        /* sort the array using insertion sort with interval*/
        for (i = interval; i < size; i++)
        {
            tmp = array[i];
            j = i;
            while (j >= interval && array[j - interval] > tmp)
            {
                array[j] = array[j - interval];
                j -= interval;
            }
            array[j] = tmp;
        }
        /* print the array*/
        print_array(array, size);

        /* decrease interval*/
        interval = (interval - 1) / 3;
    }
}
