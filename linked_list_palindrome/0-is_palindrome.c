#include "lists.h"
#include <stdio.h>

/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: double pointer to the head of the linked list to check.
 * Return: 1 if it's a palindrome otherwise 0.
 **/
int is_palindrome(listint_t **head)
{
    listint_t *oldHead = *head; 
    int counter = 0, i = 0; 
    int list[2048]; 

    /* Count the number of elements in the list */
    for (i = 0; oldHead; i++)
        oldHead = oldHead->next;
    if (i == 0)
        return (1); /* Empty or single-element list is a palindrome */

    oldHead = *head; /* Reset to start */
    for (counter = 0; oldHead; oldHead = oldHead->next, counter++)
        list[counter] = oldHead->n; /* Populate array with list values */

    for (counter = 0; counter < i; counter++) {
        if (list[counter] != list[i - counter - 1])
            return (0); /* Return 0 if mismatch found */
    }

    return (1); /* Return 1 if palindrome */
}
