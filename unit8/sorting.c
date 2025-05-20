#include <stdio.h>
#include <stdlib.h>

#define NUM_EMPLOYEES 10
#define NAME_MAX 16

struct employee_t {
    char last[NAME_MAX];
    char first[NAME_MAX];
    float salary;
} employees[NUM_EMPLOYEES] = {
    {"Abarnathy", "Alice",  123000.45},
    {"Berry",     "Bob",    39299.44},
    {"Cougar",    "Carol",  132654.55},
    {"Davis",     "David",  44443.99},
    {"Ernest",    "Eddie",  88776.33},
    {"Faulk",     "Frank",  67332.31},
    {"Gobert",    "George", 99292.33},
    {"Hughes",    "Harry",  77773.50},
    {"Irving",    "Ingrid", 99999.99},
    {"Julius",    "Jack",   93939.11}
};

// comparison function prototype
int compare(const void *row1, const void *row2);

int main(void)
{
    int i;

    // Display the contents of the array
    for (i=0; i < NUM_EMPLOYEES; ++i) {
        printf("%2d. %-*s = %10.2f\n",
               i+1,
               NAME_MAX,
               employees[i].last,
               employees[i].salary);
    }

    // Code added below to qsort array by employee salary
    qsort(employees, NUM_EMPLOYEES, sizeof(struct employee_t), compare);

    // Display the contents of the sorted array
    printf("\n----------------\n");
    for (i=0; i < NUM_EMPLOYEES; ++i) {
        printf("%2d. %-*s = %10.2f\n",
               i+1,
               NAME_MAX,
               employees[i].last,
               employees[i].salary);
    }

    return EXIT_SUCCESS;
}

// comparison function to pass to qsort
int compare(const void *row1, const void *row2) {
    // must cast the void arguments to our struct type
    struct employee_t *new_row1 = (struct employee_t *) row1;
    struct employee_t *new_row2 = (struct employee_t *) row2;

    if (new_row1->salary < new_row2->salary) {
        return -1;
    } else if (new_row1->salary == new_row2->salary) {
        return 0;
    } else { //new_row1->salary > new_row2->salary
        return 1;
    }
}
