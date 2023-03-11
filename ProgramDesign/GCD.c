#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

int main(void) 
{
    int numerator, denominator, input_n, input_d;

    // Prompt for the numbers:
    printf("Enter a fraction to simplify: (n/d) ");
    scanf("%d/%d", &input_n, &input_d);

    // Reduce the fraction:
    reduce(input_n, input_d, &numerator, &denominator);

    // Print the results:
    printf("The reduced fraction of %d / %d is %d / %d.\n", input_n, input_d, numerator, denominator);

    return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{   
    // Variables for string the results:
    int gcd, greater, lesser, rem = 1;

    // Determines which is larger:
    if (numerator > denominator)
    {
        greater = numerator;
        lesser = denominator;
    }
    else
    {
        greater = denominator;
        lesser = numerator;
    }

    // Finds the greatest common divisor:
    while (rem != 0)
    {
        rem = greater % lesser;
        greater = gcd = lesser;
        lesser = rem;
    }

    // Stores the reduced values:
    *reduced_numerator = numerator / gcd;
    *reduced_denominator = denominator / gcd;
}