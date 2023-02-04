/* 
	Name: project3_checksum.c
	Purpose: The program prompts for an integer and returns its
		 checksum value.
	Author: Adrian Lozada
*/

#include <stdio.h>

// Macro for the length of the array:
#define LENGTH 13

// Used to store info:
struct STORAGE 
{
	// Counter for the prompt:
	unsigned int counter;
	// An array to store the integers:
	unsigned short number[LENGTH];
	// The result:
	unsigned short result;
} INPUT;

// Function prototypes:
void prompt(void);
void check(void);

int main(void)
{
	// Set the counter's initial value to 0:
	INPUT.counter = 0;
	// Call the functions:
	prompt();
	check();
	// Output the result:
	printf("Checksum: %hu\n", INPUT.number[0]);
	return 0;
}

void prompt(void)
{	
	/// @brief The function prompts for a number and stores its integers into an array.

	// Prompt for the integer:
	if (INPUT.counter == 0)
		printf("Input: ");
 	unsigned short input = getchar();
	// Check if the input is the newline character:
	if (input == '\n')
		return;
	// Store the value:
	INPUT.number[INPUT.counter] = (unsigned short) (input - '0');
	// Call prompt again for the next integer and increment counter:
	++INPUT.counter;
	prompt();
}

void check(void)
{
	/// @brief The function calculates the checksum recursively.

	// Check if the array is over:
	if (INPUT.counter <= 1)
		return;
	// Add the integers:
	unsigned short i = (INPUT.counter - 1), number;
	if ((number = INPUT.number[i] + INPUT.number[i - 1]) > 9)
		INPUT.number[i - 1] = (number - 9);
	else
		INPUT.number[i - 1] = number;
	// Call again:
	--INPUT.counter;
	check();
}
