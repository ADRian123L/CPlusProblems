/*
	Name: project3_array1.c
	Purpose: The program prompts for an array and returns if 
		the array follows some conditions.
	Author: Adrian Lozada
*/

#include <stdio.h>

// Function prototypes:
void check(int length, int list[]);

int main(void)
{ 
	int length;
	// Prompts for the length of the array:
	printf("Enter the length of the input array: ");
	scanf("%d", &length);
		
	int list[length];
	// Stores each number into the array:
	printf("Enter the array elements: ");
	for (int i = 0; i < length; ++i)
		scanf("%d", &list[i]);
	
	// Call the check function:
	check(length, list);

	return 0;
}

// The functions veryfies if the list of numbers satisfy the requirements.
void check(int length, int list[])
{
	/// @brief The function goes over the list of numbers, veryfing each for a condition.
	/// @param length is the how many elements there are in the array.
	/// @param list[] is the array of numbers.

	for (int i = 0; i < (length - 1); ++i)
	{	// Check if the proceding number is larger:
		if (list[i] >= list[i + 1])
			return (void) printf("Output: no\n");
		// Check if the proceding number is divisible:
		if (list[i + 1] % list[i] == 0)
			return (void) printf("Output: no\n");
	} 	
	// Print yes if the requirements are met:
	printf("Output: yes\n");
}
