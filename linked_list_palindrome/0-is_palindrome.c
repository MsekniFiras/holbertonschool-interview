#include "lists.h"
#include <stdio.h>
/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: double linked list to check.
 * Return: 1 if it's palindrome otherwise 0.
 **/
int is_palindrome(listint_t **head) {
    if (!head || !*head || !(*head)->next) return 1;

    listint_t *slow = *head, *fast = *head, *prev = NULL, *temp = NULL;

    // Find the middle of the list
    while (fast && fast->next) {
        fast = fast->next->next;
        // Reverse the first half while finding the middle
        temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    // Handle odd number of elements
    listint_t *second_half = (fast ? slow->next : slow);

    // Compare the first half and the second half
    while (prev && second_half) {
        if (prev->n != second_half->n) {
            return 0;
        }
        prev = prev->next;
        second_half = second_half->next;
    }


    return 1;
}
