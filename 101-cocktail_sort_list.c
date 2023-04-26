#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order
 *                      using the cocktail shaker sort algorithm
 *
 * @list: A pointer to the head of the doubly linked list to sort
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *left, *right, *node, *tmp;
    int swapped;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    left = *list;
    right = left;
    while (right->next != NULL)
        right = right->next;

    do
    {
        swapped = 0;
        for (node = left; node != right; node = node->next)
        {
            if (node->n > node->next->n)
            {
                tmp = node->next;
                node->next = tmp->next;
                if (tmp->next != NULL)
                    tmp->next->prev = node;
                tmp->prev = node->prev;
                tmp->next = node;
                node->prev = tmp;
                if (tmp->prev != NULL)
                    tmp->prev->next = tmp;
                else
                    left = tmp;
                print_list(*list);
                swapped = 1;
            }
        }
        if (!swapped)
            break;
        swapped = 0;
        right = right->prev;
        for (node = right; node != left; node = node->prev)
        {
            if (node->n < node->prev->n)
            {
                tmp = node->prev;
                node->prev = tmp->prev;
                if (tmp->prev != NULL)
                    tmp->prev->next = node;
                tmp->next = node->next;
                tmp->prev = node;
                node->next = tmp;
                if (tmp->next != NULL)
                    tmp->next->prev = tmp;
                else
                    right = tmp;
                print_list(*list);
                swapped = 1;
            }
        }
        left = left->next;
    } while (swapped);
}
