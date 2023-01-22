/*
	Name: project2_travel.c
	Purpose: The program prompts for two integers. Then it calculates
		 when two spacecrafts will intersect.
	Authot: Adrian Lozada
*/

#include <stdio.h>
#include <math.h>
#include <tgmath.h>

// A macro for the log(3/2):
#define DENO log((float) 3 / 2)  

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
	// Prompt for the number of tries:
	unsigned short cases;
	printf("Enter the number of cases: ");
	scanf("%hu", &cases);
	
	// Runs the number of cases:
	for (short first, second, days; cases > 0; --cases)
	{	
		// Prompt for the initial speed:
		printf("Speed of A: ");
		scanf("%hd", &first);
		printf("Speed of B: ");
		scanf("%hd", &second);
		
		// Calculate the days:
		days = (short) trunc((log(first/second) / DENO) + 1);
	
		// Output the result:
		printf("Case #%hd: %hd day(s)\n", cases, days);
	}
}
