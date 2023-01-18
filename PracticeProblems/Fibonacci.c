// The program calculates the fibonacci sequance.

#include <stdio.h>

int fibo(int i);

int main(void) 
{
	// The variables for storing the input and answer:
	int input, number;
	// Prompt for an index:
	scanf("%d", &input);
	// Call the fibo function to get the fibonacci number at the inputed
	// index:
	number = fibo(input);
	// Print the result:
	printf("%d\n", number);
	// Loop until the user inputs 0:
	while (input != 0)
	{

		scanf("%d", &input);	
		number = fibo(input);
		printf("%d\n", number);
	}
	return 0;
}

// The function calculates the fibonacci number at an inputed index:
int fibo(int i) 
{
	
	if (i <= 1) 
		return 0;
	else if (i == 2) 
		return 1;
	else {
		return fibo(i - 1) + fibo(i - 2);	

             }
}
