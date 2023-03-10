#include <stdio.h>

#define ROW 5
#define COL 3

int main(void) 
{
    // Array:
    int array[ROW][COL] = {{1, 2, 3}, 
                           {4, 5, 6}, 
                           {7, 8, 9}};

    int *p = &array[0][0];
    int index;

    for (; p < &array[ROW][COL]; ++p)
    {
        index = p - &array[0][0];
        printf("The value of %d is: %d\n", index, *p);
    }

    return 0;
}