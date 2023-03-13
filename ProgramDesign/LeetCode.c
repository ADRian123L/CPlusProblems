#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    return 0;
}


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
