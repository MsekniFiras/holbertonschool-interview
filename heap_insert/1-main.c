#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void) {
    heap_t *root = NULL;
    heap_t *node;

    int values[] = {98, 402, 12, 46, 128, 256, 512, 50};
    size_t n_values = sizeof(values) / sizeof(values[0]);

    for (size_t i = 0; i < n_values; i++) {
        node = heap_insert(&root, values[i]);
        if (node == NULL) {
            fprintf(stderr, "Failed to insert %d\n", values[i]);
            return EXIT_FAILURE;
        }
        printf("Inserted: %d\n", node->n);
        binary_tree_print(root);
    }

    // Cleanup code here (if necessary)

    return EXIT_SUCCESS;
}