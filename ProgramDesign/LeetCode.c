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

    // Initializing some variables to store the data:
    int flag = 0, sum = 0;
    int *p, *q;
 
    // Get the total sum:
    for (p = &nums[0]; p < &nums[numsSize]; ++p)
    	sum += *p;

    // Setting q and p to point to nums:
    p = &nums[0];

    // Search for the pivot:
    for (float suml; p < &nums[numsSize]; ++p)
    {   
        // Check if the suml is an int:
        suml = ((sum - *p) / 2.0f);
	if ((suml - (int) suml) != 0.0f)
		continue;

        // Start q at the first element:
        q = &nums[0];
        suml = 0.0f;

        // Find the sum of the left-hand side values:
        while(q < p)
        {
            // Take the sum of the elements:
            suml += *q;
            ++q;
        }
	
	    if (suml == ((sum - *p) / 2.0f))
	    {
	        flag = 1;
	        break;
	    }

    }
  
    // Check if there is a pivot:
    if (flag == 1)
        return (p - nums);
    else
        return -1;
}