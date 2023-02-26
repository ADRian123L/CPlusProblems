/*
	Name: project4_median.c
	Purpose: The program prompts for an array of integers
		then it returns the median element of the array.
	Author: Adrian Lozada
*/

#include <stdio.h>

// Functions prototypes:
int compute_median(int *a, int n);

int main(void)
{
    int N;
    // Prompt for the length of the array:
    printf("Enter array size: ");
    scanf("%d", &N);

    // Prompt for the array elements:
    printf("Enter array elements: ");
    int a[N];
    for (int *i = a; i < (a + N - 1); ++i)
	scanf("%d", i);

    // Call the compute_median function:
    int median;
    median = compute_median(a, N);

    // Find the number of elements that are equal to the median:
    int counter = 0;
    for (int *u = a; u < (a + N - 1); ++u)
    {
	if (*u == median)
	    ++counter;
    }
    // Print the number of medians:
    printf("Output: %d\n", counter);

    return 0;
}

int compute_median(int *a, int n)
{
    /// @brief This function returns the median element of the array.
    /// @param a is the array.
    /// @param n is the length of the array.
    /// @return the median element of the array.

    for (int *p = (a + 1); p < (a + n - 1); ++p)
    {
	    int key, *j;
	    key = *p;
	
	    j = p - 1;
	
	    while (j >= a && *j > key)
 	    {
	        *(j + 1) = *j;
	        --j;
	    }

	    *(j + 1) = key; 
    }

    return *(a + ((n - 1) / 2));
}