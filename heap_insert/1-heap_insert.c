#include "binary_trees.h"
#include <stdlib.h>

/* Function prototypes */
heap_t *find_insert_position(heap_t *root);
void heapify_up(heap_t *node);

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the new node
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *insert_position;

    /* Create the new node */
    new_node = binary_tree_node(NULL, value);
    if (new_node == NULL)
        return (NULL);

    /* If the heap is empty, new node becomes the root */
    if (*root == NULL)
    {
        *root = new_node;
        return new_node;
    }

    /* Find the insertion position */
    insert_position = find_insert_position(*root);

    /* Insert new node */
    if (insert_position->left == NULL)
        insert_position->left = new_node;
    else
        insert_position->right = new_node;

    new_node->parent = insert_position;

    /* Ensure Max Heap property is maintained */
    heapify_up(new_node);

    return new_node;
}

/**
 * find_insert_position - Finds the position to insert the new node
 * @root: Pointer to the root node of the heap
 *
 * Return: Pointer to the parent node where the new node should be inserted
 */
heap_t *find_insert_position(heap_t *root)
{
    /* Perform a level-order traversal to find the insertion point */
    heap_t *queue[100]; /* Assume heap has no more than 100 nodes */
    int front = -1, rear = -1;
    heap_t *temp = root;

    while (temp != NULL)
    {
        if (front == -1)
            front = rear = 0;
        else
            rear++;
        queue[rear] = temp;

        /* Dequeue */
        temp = queue[front];
        front++;

        /* If left child is NULL, insert here */
        if (temp->left == NULL)
            return temp;
        /* Otherwise, enqueue left child */
        else
        {
            rear++;
            queue[rear] = temp->left;
        }

        /* If right child is NULL, insert here */
        if (temp->right == NULL)
            return temp;
        /* Otherwise, enqueue right child */
        else
        {
            rear++;
            queue[rear] = temp->right;
        }
    }

    return NULL; /* This case should not happen */
}

/**
 * heapify_up - Maintains Max Heap property after insertion
 * @node: Pointer to the newly inserted node
 */
void heapify_up(heap_t *node)
{
    heap_t *parent;
    int temp;

    while (node->parent != NULL && node->n > node->parent->n)
    {
        parent = node->parent;
        /* Swap node and parent */
        temp = node->n;
        node->n = parent->n;
        parent->n = temp;
        node = parent;
    }
}
