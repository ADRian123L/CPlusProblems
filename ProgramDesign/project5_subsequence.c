/*
	Name: project5_subsequence.c
	Purpose: The probram veryfies if a set in a subset of another.
	Author: Adrian Lozada
*/

#include <stdio.h>

int main(void)
{
    char str1[100] = {0}, *p = str1;
    int result;
    char ch = 0;

    // Prompt for the first word and store it in str1:
    printf("Enter first word: ");
    while ((ch = getchar()) != '\n')
	*p++ = ch;

    // Reset p to point to str1:
    p = str1;
    // Reset ch to 0;
    ch = 0;
	
    // Prompt for the second word and compare the words:
    printf("Enter second word: ");
    while ((ch = getchar()) != '\n')
    {
	/// @brief The function iterates through the charactes of str1 and compares them to the input.

	if ((ch - *p) == 0 || (ch - *p)*(ch - *p) == 1024)
	    ++p;
	 
	if (!*p)
	{
	    result = 1;
	    break;
	}
	else
	    result = 0;	
    }
	
    if (result)
	printf("YES\n");
    else
	printf("NO\n");

    return 0;
}
