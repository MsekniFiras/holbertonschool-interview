#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the head of the linked list
 * Return: the address of the loop node
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *hare = head, *tortoise = head;

	while (hare && hare->next)
	{
		hare = hare->next->next;
		tortoise = tortoise->next;
		if (hare == tortoise)
		{
			tortoise = head;
			while (tortoise != hare)
			{
				tortoise = tortoise->next;
				hare = hare->next;
			}
			  return (hare);
        }
    }
    return (NULL);
}
