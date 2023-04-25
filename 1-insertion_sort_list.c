#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *      order using the insertion sort algorithm.
 * 
 * @list: pointer to the head of the list to be sorted.
*/

void insertion_sort_list(listint_t **list)
{
    listint_t *curr, *prev;

    if (!list || !(*list) || !(*list)->next)
        return;
    
    curr = (*list)->next;
    while (curr != NULL)
    {
        while (curr->prev != NULL && curr->n < curr->prev->n)
        {
            prev = curr->prev;
            prev->next = curr->next;
            if (curr->next != NULL)
                curr->next->prev = prev;
            curr->prev = prev->prev;
            curr->next = prev;
            prev->prev = curr;
            if (curr->prev == NULL)
            {
                (*list) = curr;
            }
            else
                curr->prev->next = curr;
        }
        curr = curr->next;
    }
}
