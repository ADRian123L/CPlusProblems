/* 
	Name: project2_encode.c 
	Purpose: The program prompts for a integer or a character 
		and returns them encoded.
	Author: Adrian Lozada
*/

#include <stdio.h>
#include <string.h>

// Constants and macros for determining the type of input:
#define WHITE_SPACE 32
#define UNDER_SCORE '_'
#define NEW_LINE '\n'
#define ALPHA_LENGTH 26
#define ADDER 6
#define ZERO 48
#define DIGIT 10
#define A 65
#define a 97

// Arrays to determine the type of input:
const unsigned short integers[2] = {48, 57},
		             upper_letters[2] = {65, 90},
	                 lower_letters[2] = {97, 122};


// Struct to safe the encoded data:
struct Data 
{
	/// @brief The struct to safe the encoded data.
	char numbers[1000];

} Inputs;

// Functions:
void encode(void);
char encoder(char num, short type);
void output(void);

// Main function:
int main(void) 
{
	// The function drives the program:
	encode();
	output();
	return 0;
}

// The function prompts for a integer or a character and returns them encoded:
void encode(void) 
{
	/// @brief The function prompts for a integer or a character and returns them encoded.

	// The variable input is the input:
	char input;
	// The loop prompts for a integer or a character:
	for (int i = 0; ((input = getchar()) != NEW_LINE); ++i) 
	{	
		if (input >= integers[0] && input <= integers[1])
		
			Inputs.numbers[i] = encoder(input, 1);
	
		else if (input >= upper_letters[0] && input <= upper_letters[1])

			Inputs.numbers[i] = encoder(input, 2);

		else if (input >= lower_letters[0] && input <= lower_letters[1])

			Inputs.numbers[i] = encoder(input, 3);

		else if (input == WHITE_SPACE)

			--i;

		else

			Inputs.numbers[i] = UNDER_SCORE;
	}
}

// The function encodes the input:
char encoder(char num, short type)
{
	/// @brief The function encodes the input.
	/// @param num The input to be encoded.
	/// @param type The type of input.
	/// @return The encoded input.
	
	char changed;
	// The switch encodes the input:
	switch (type)
	{
		case 1:

			changed = ((int) num - ZERO + ADDER) % DIGIT;
			changed = ((char) changed) + ZERO;			
			break;

		case 2:

			changed = (char) (((num - A) + ADDER) % ALPHA_LENGTH) + A;
			break;

		case 3:

			changed = (char) (((num - a) + ADDER) % ALPHA_LENGTH) + a;
			break; 

	}
	return changed;
}

// The function prints the encoded data:
void output(void)
{
	/// @brief The function prints the encoded data.
	printf("%s", Inputs.numbers);
}
