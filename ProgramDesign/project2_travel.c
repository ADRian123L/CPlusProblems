/*
	Name: project2_travel.c
	Purpose: The program prompts for two integers. Then it calculates
		 when two spacecrafts will intersect.
	Authot: Adrian Lozada
*/

#include <stdio.h>
#include <math.h>

// A macro for the log(3/2):
#define DEN logf((float) 3 / 2)  

// Functions:
void days(void);

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
	printf("Enter the number of cases: ");
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
		days = (short) truncf((logf((float) first/second) / DEN) + 1);
	
		// Output the result:
		printf("Case #%hd: %hd day(s)\n", count, days);
	}
}
