#include <stdio.h>
#include <stdlib.h>

// The function to find the pivot index:
int pivotIndex(int* nums, int numsSize)
{
    // Check if the array length if less than 1:
    if (numsSize < 1)
	    return -1;
    else if (numsSize == 1)
	    return 0;

    // Initializing some variables to store the data:
    int sum = 0;
    int *p;
 
    // Get the total sum:
    for (p = &nums[0]; p < &nums[numsSize]; ++p)
    	sum += *p;

    // Setting q and p to point to nums:
    p = &nums[0];

    // Search for the pivot:
    for (float suml = 0; p < &nums[numsSize]; ++p)
    {   
	// Check if the sum are the same:	
        if (suml == ((sum - *p) / 2.0f))
            return (p - nums);
	// Add p to suml:
        suml += *p;
    }
    return -1;
}

int isIsomorphic(char *s, char *t)
{
    for (char *p = s, *q = t, tmp; *p; ++p, ++q)
    { 
	// Store the value of q:
    tmp = *q;
    *q = *p;

	    for (char *i = q + 1; *i; ++i)
   	        // Check if any letters repeat:
	        if (*i == tmp)
		        *i = *p;		
	    
    } 

    for (char *p = s, *q = t; *q; ++p, ++q)
        if (*p != *q)
	        return 0;
   
    return 1;	
}  

int main(void)
{
    return 0;
}

