/*
	Name: project5_encode.c
	Purpose: The program takes some strings and outputs them encoded.
	Author: Adrian Lozada
*/

#include <stdio.h>

void encode(char *input, char *output);
void concatenate(char **input, char *output);

int main(int argc, char *argv[])
{
	/// @brief The function takes the strings from the command line and encodes them.
	/// @param argc is the number of strings.
	/// @param argv is the multidimensional array that stores the strings.

	// Check if there are any strings:
	if (!(--argc))
	{
		printf("Invalid input!\n");
		return 0;
	}

	// Declare the variables:
	char input[1000] = {0}, output[1000] = {0};

	// Concatenate the strings:
	concatenate(argv, input);
	// Encode the strings:
	encode(input, output);
	// Print the output:
	printf("Output: %s\n", output);

	return 0;
}

void encode(char *input, char *output)
{
	/// @brief The function encodes the string input.
	/// @param input is the string to be encoded.
	/// @param output is where the encoded string is stored.

    for (; *input; ++input, ++output)
	{
		if (*input >= 'a' && *input <= 'z')
		{
			*input -= 'a';
			*input += 6;
			*input %= 26;
			*input += 'a';

		}
		else if (*input >= 'A' && *input <= 'Z')
		{
			*input -= 'A';
			*input += 6;
			*input %= 26;
			*input += 'A';
		}
		else if (*input >= '0' && *input <= '9')
		{
			*input -= '0';
			*input += 6;
			*input %= 10;
			*input += '0';
		}
		else
			*input = '_';

		*output = *input;
	}

}

void concatenate(char **input, char *output)
{
	/// @brief The function concatenates all of the strings stored in the multidimensional array input.
	/// @param input is the multidimensional array.
	/// @param output is where the strings are concatenated.
	++input;
	for (; *input; ++input)
	{
		while ((*output++ = *((*(input))++)));
		*(--output) = '0';
	}
	*output = '\0';
}