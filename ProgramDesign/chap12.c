// The program uses a function to determine if an element is in the array a.
#include <stdio.h>

int search(const int a[], int n, int key);

int main(void)
{
    int a[3] = {1, 7, 4};

    int bool = search(a, 3, 7);

    printf("The is key is in the array? %d\n", bool);

    return 0;
}

int search(const int a[], int n, int key)
{
    int flag = 0;

    for (const int *p = &a[0]; p <= &a[n]; ++p)
    {
        if (key == *p)
            {
                flag = 1;
                break;
            }
    }

    return flag;
}