#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using
 * the quick sort algorithm with Lomuto partition scheme.
 * 
 * @array: pointer to the array of integers to be sorted
 * @size: size of the array to be sored
 * 
 * Return: void
*/

void quick_sort(int *array, size_t size)
{
    if (size < 2)
        return;
    
    quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - recursive helper function for Quick sort algorithm
 * @low: lowest index of the partition being sorted
 * @high: highest index of the partiion being sorted
 * @size: size of the array to be sorted
 * 
 * Return: void
*/

void quick_sort_helper(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
        pivot = lomuto_partition(array, low, high, size);
        quick_sort_helper(array, low, pivot - 1, size);
        quick_sort_helper(array, pivot + 1, high, size);
    }
}

/**
 * lomuto_partition - Helper function for quick sort algorithm
 * 
 * @array: pointer to the array of integers to be sorted
 * @low: lowest index of the partition being sorted
 * @high: highest index of the partition being sorted
 * @size: size of the array to be sorted
 * 
 * Return: new pivot index
*/

int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1, j;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }
    if (i + 1 != high)
    {
        swap(&array[i + 1], &array[high]);
        print_array(array, size);
    }

    return (i + 1);
}

/**
 * swap - Helper function to swap two integers in an array
 * 
 * @a: pointer to the first integer to be swapped
 * @b: pointer to the second integer to be swapped
 * 
 * Return: void
*/

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
