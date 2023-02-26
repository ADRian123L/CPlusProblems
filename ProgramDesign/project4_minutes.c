/*
…	Name: project4_minutes.c
	Purpose: The program prompts for the number of interesting
		minutes. Afterwards, it checks an array for some
		requirements.
	Author: Adrian Lozada
*/

#include <stdio.h>

#define SEVEN 7

// Function prototypes:
int find_minute(int *, int);

int main(void)
{
    // Prompt for the number of elements:
    int elements;
    printf("Enter the number of interesting minutes: ");
    scanf("%d", &elements);
	
    // Prompt for the elements of the array:
    int array[elements];
    printf("Enter the interesting minutes: ");
    for (int i = 0; i < elements; ++i)
	    scanf("%d", &array[i]);

    // Call the find_minute function:
    int output;
    output = find_minute(array, elements);
    
    // Print the result and check if it is greater than 45:
    printf("Output: %d\n", (output > 45) ? 45: output);

    return 0;
}

int find_minute(int *minutes, int n)
{
    /// @brief The function determines if an array of ints follow some requirements.
    /// @param minutes is the pointer for the array.
    /// @param n is the length of the array.
    /// @return the minutes after people stop watching.

    int *p = minutes;

    if (*p > SEVEN)
	    return SEVEN;

    for (; p < (minutes + n - 1); ++p)
    {
	    if ((*(p + 1) - *p) > SEVEN)
	        return (*p + SEVEN);
    }	
    return (*(minutes + n - 1) + SEVEN);
}