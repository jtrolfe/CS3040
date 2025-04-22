#include <stdio.h>
#include <stdlib.h> // needed for malloc
#include <errno.h>

struct num {
    int val;
    struct num *next;
};

int main(void)
{
    struct num *first = NULL;
    struct num *last  = NULL;

    errno = 0;
    // Get the linked list started:
    first = malloc(sizeof(struct num));
    if ((first == NULL) || (errno != 0)) {
        printf("Error in allocating memory.\n");
        exit(EXIT_FAILURE);
    }

    // No error, so proceed with node:
    first->val  = 0;
    first->next = NULL;
    last        = first;
    printf("%i\n", last->val);

    return EXIT_SUCCESS;
}


