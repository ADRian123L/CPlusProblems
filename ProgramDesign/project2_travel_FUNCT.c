/*
	Name: project2_travel.c
	Purpose: The program prompts for two integers. Then it calculates
		 when two spacecrafts will intersect.
	Author: Adrian Lozada
*/

#include <stdio.h>

// Macros:
#define BASE (float) (3.0  / 2.0)

// Function prototypes:
void days(void);
int loga(float number, float base);
float power(float base, int expo);


int main (void)
{
	// Drives the program:
	days();
	return 0;
}

void days(void) 
{
	/// @brief The function prompts the user and returns the days.

	// Prompt for the number of tries:
	unsigned short cases;
	printf("Number of cases: ");
	scanf("%hu", &cases);
	
	// Runs the number of cases:
	for (short first, second, days, count = 1; cases >= count; ++count)
	{	
		// Prompt for the initial speed:
		printf("Speed of A: ");
		scanf("%hd", &first);
		printf("Speed of B: ");
		scanf("%hd", &second);
		
		// Calculate the days:
		days = (short) ((loga((float) first/second, BASE)) + 1);
	
		// Output the result:
		printf("Case #%hd: %hd day(s)\n", count, days);
	}
}

int loga(float number, float base)
{	
	/// @brief The function calculates the logarithm of a number.
	/// @param number is the number to calculate the logarithm.
	/// @param base is the base of the logarithm.
	/// @return the logarithm of the number.

	// If the number is 1 or less than 1:
	if (number == 1)
		return 0;
	if (number < 1)
		return -1;

	// If the number is greater than 1:
	for (int i = 0;; ++i)
	{
		if ((number - power(base, i)) < 0)
			return i - 1;
	}
}

float power(float base, int expo)
{
	/// @brief The function calculates the power of a number.
	/// @param base is the base of the power.
	/// @param expo is the exponent of the power.
	/// @return the power of the number.

	float result = 1.0;
	// If the exponent is 0:
	if (expo == 0)
		return result;
	// If the exponent is greater than 0:
	for (; expo > 0; --expo)
	{
		result *= base;
	} 
	return result;
}
