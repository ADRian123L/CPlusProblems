#include <stdio.h>

#define ROW 4
#define COL 3

int main(void) 
{
    // Array:
    int array[ROW][COL] = {{1, 2, 3}, 
                           {4, 5, 6}, 
                           {7, 8, 9},
                           {10, 11, 12}};

    int (*p)[3] = &array[0];
    int index;

    for (; p < &array[ROW - 1]; ++p)
    {
        printf("The first and second elements of the array row %d are: %d and %d.\n", (int) (p - &array[0]), **p, *(*p + 2));
    }

    return 0;
}