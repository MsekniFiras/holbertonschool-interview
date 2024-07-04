#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/*
* intsert_node - insert node into head
* @head: head of linked list
* @number: number to insert
**/
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node, *current;

    if (!head)
        return (NULL);

    new_node = malloc(sizeof(listint_t));
    if (!new_node)
        return (NULL);

    new_node->n = number;
    new_node->next = NULL;

    if (*head == NULL || (*head)->n >= number) {
        new_node->next = *head;
        *head = new_node;
    } else {
        current = *head;
        while (current->next != NULL && current->next->n < number) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

    return (new_node);
}