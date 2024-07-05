#include "lists.h"
#include <stdio.h>

/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: double pointer to the head of the linked list to check.
 * Return: 1 if it's a palindrome otherwise 0.
 **/
int is_palindrome(listint_t **head)
{
    listint_t *oldHead = *head; // Pointer to traverse the list
    int counter = 0, i = 0; // Counters for the loop
    int list[2048]; // Array to store the values of the list nodes

    // First loop: count the number of elements in the list
    for (i = 0; oldHead; i++)
        oldHead = oldHead->next;
    // If the list is empty or has one element, it's a palindrome
    if (i == 0)
        return (1);

    // Reset oldHead to the start of the list
    oldHead = *head;
    // Second loop: populate the array with the list's values
    for (counter = 0; oldHead; oldHead = oldHead->next, counter++)
        list[counter] = oldHead->n;

    // Third loop: check if the list is a palindrome
    for (counter = 0; counter < i; counter++)
    {
        // Compare the values from the start and end towards the center
        if (list[counter] != list[i - counter - 1])
            return (0); // Not a palindrome if any pair of values don't match
    }

    // If all pairs of values matched, it's a palindrome
    return (1);
}
