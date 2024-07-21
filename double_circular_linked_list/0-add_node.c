#include "list.h"

/**
 * add_node_end - Add a new node to the end of a double.
 * circular linked list.
 * @list: the list to modify.
 * @str: the string to copy into the new node.
 * Return: Address of the new node, or NULL on failure.
 */

List *add_node_end(List **list, char *str)
{
	List *new;
	List *p;

	if (!list || !str)
		return (NULL);

	new = malloc(sizeof(list));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
		return (NULL);
	if (*list == NULL)
	{
		new->next = new->prev = new;
		*list = new;
		return (new);
	}
	p = (*list)->prev;
	p->next = new;
	new->next = (*list);
	new->prev = p;
	(*list)->prev = new;
	return (new);
}

/**
 * add_node_begin - Add a new node to the begin of a double.
 * circular linked list.
 * @list: the list to modify.
 * @str: the string to copy into the new node.
 * Return: Address of the new node, or NULL on failure.
 */

List *add_node_begin(List **list, char *str)
{
	List *new;
	List *p;

	if (!list || !str)
		return (NULL);

	new = malloc(sizeof(list));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	if (new->str == NULL)
		return (NULL);
	if (*list == NULL)
	{
		new->next = new->prev = new;
		*list = new;
		return (new);
	}
	p = (*list)->prev;
	new->next = (*list);
	new->prev = p;
	(*list)->prev = p->next = new;
	*list = new;
	return (new);
}
