/* Name: Ctutorial.c */
/* Purpose: Prints some statements. */
/* Author: Adrian */

// The preprocessor:
#include <stdio.h> // The header file.
#include <stdlib.h> 


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
    int d, i1, i2, i3, i4, i5;
    int j1, j2, j3, j4, j5;
    int first_sum, second_sum, total;
    printf("Enter the first (single) digit: ");
    scanf("%1d", &d);
    printf("Enter the first group of five digits: ");
    scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
    printf("Enter the second group of five digits: ");
    scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);
    first_sum = d + i3 + j1 + j3 + j5;
    second_sum = i1 + i4 + i5 + j2 + j4;
    total = 9 - ((3 * first_sum + second_sum) - 1) % 10;
    printf("Check digit: %d\n", total);
    // Check digit:

    // TODO: You left off at page 58 of the book. Section 4.2

    return 0;
}