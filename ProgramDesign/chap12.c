// The program uses a function to determine if an element is in the array a.
#include <stdio.h>

#define L 10

int search(const int a[], int n, int key);
int string(char *array, int n);

int main(void)
{
    char array[L];
    int length;
    printf("Enter the string: ");
    length = string(array, L);

    printf("The array has a length of %d and says: \n %s.\n", length, array);

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

int string(char *array, int n)
{
    /// @brief the function prompts for a string and stores it.
    int ch, l = 0;
    char *p = &array[0];

    for (; ((ch = getchar()) != '\n'); ++p, ++l)
    {
        if (p >= &array[n - 1])
            break;
        *p = ch;
    }
    // Assign the last element the null char:
    *(p) = '\0';

    return l;
}