/* Name: Ctutorial.c */
/* Purpose: Prints some statements. */
/* Author: Adrian */

// The preprocessor:
#include <stdio.h> // The header file.
#include <stdlib.h> 
#include <string.h>

// functions:
// The function power takes two arguments, x and n.
int power(int x, int n) 
{
    if (n == 0) // If the exponent is 0
    {
        return 1; // Return 1
    }
    else // If the exponent is a positive number
    {
        int y = power(x, n - 1); // Calculate x to the (n-1)th power
        return x * y; // Return x multiplied by x to the (n-1)th power
    }
}

// main function:
int main(void)
{   
    // Ask for a base and an exponent
    char n[8];
    n[0] = 'a';
    n[1] = 'b';
    n[2] = 'c';
    n[3] = 'u';
    int len = strlen(n);
    printf("%d\n", len);
    printf("%s\n", n);

    return 0;
}
