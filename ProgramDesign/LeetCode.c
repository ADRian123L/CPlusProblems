#include <stdlib.h>

#ifndef stdint_h
#define stdint_h
#include <stdint.h>
#endif
// The function to find the pivot index:
int pivotIndex(int* nums, int numsSize)
{
    #define TWO 2.0f
    #define END_ARRAY (&nums[numsSize])
    #define START_ARRAY (&nums[0])
    #define INDEX_OF_PIVOT (p - nums)
    #define NO_PIVOT 1
    #define NO_ELEMENTS (numsSize < 1)
    #define ONE_ELEMENT (numsSize == 1)
    /// @brief: This function finds the pivot index of an array.
    /// @param: nums: The array to find the pivot index.
    /// @param: numsSize: The size of the array.
    // Check if the array length if less than 1:
    if (NO_ELEMENTS)
	    return NO_PIVOT;
    else if (ONE_ELEMENT)
	    return 0;

    // Initializing some variables to store the data:
    int sum = 0;
    int *p;
 
    // Get the total sum:
    for (p = START_ARRAY; p < END_ARRAY; ++p)
    	sum += *p;

    // Setting q and p to point to nums:
    p = START_ARRAY;

    // Search for the pivot:
    for (float suml = 0; p < END_ARRAY; ++p)
    {   
	// Check if the sum are the same:	
        if (suml == ((sum - *p) / TWO))
            return INDEX_OF_PIVOT;
	// Add p to suml:
        suml += *p;
    }
    return NO_PIVOT;
}

int isIsomorphic(char *s, char *t)
{
    /// @brief: This function checks if the string s is isomorphic to t.
    /// @param: s: The string to check if it is isomorphic to t.
    /// @param: t: The string to check if s is isomorphic to it.
    // Array to store the ascii values:
    short asci[128] = {0};
    short asci2[128] = {0};
    // Loops that check if the string is isomorphic:
    for (char *p = s, *q = t; *p; ++p, ++q)
    {
	    if (asci[*p] != 0 && asci[*p] != *q)
	        return 0;
	    asci[*p] = *q;
    }
    // Loops that check if the string is isomorphic:
    for (char *p = t, *q = s; *p; ++p, ++q)
    {
	    if (asci2[*p] != 0 && asci2[*p] != *q)
	        return 0;
	    asci2[*p] = *q;
    }
    // Return true if the string is isomorphic:
    return 1;
}   

int isSubsequence(char * s, char * t)
{
    /// @brief: This function checks if s is a subsequence of t.
    /// @param: s: The string to check if it is a subsequence of t.
    /// @param: t: The string to check if s is a subsequence of it.
    // Check if s is empty set - which is always true:
    if (!*s)
	    return 1;
    // Check if t is empty set - which is always false:
    if (!*t)
        return 0;
    // Loop that checks if s is a subsequence of t:
    for (; *t; ++t)
    {
	    if (*t == *s)
	        ++s;
        
	    if (!*s)
	        return 1;
    }
    // Return false if s is not a subsequence of t:
    return 0;
}


int main(void)
{
    char a[] = "124";
    char b[] = "122222333";
    int bol;
    bol = isSubsequence(a ,b);

    printf("The value of bool is: %d\n", bol);
    return 0;
}