#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    return 0;
}


// The function to find the pivot index:
int pivotIndex(int* nums, int numsSize)
{
    // Initializing some variables to store the data:
    int sumr = 0, suml = 0, flag = 0;
    int *p, *q;

    // Setting q and p to point to nums:
    p = q = &nums[0];

    // Search for the pivot:
    for (; p < &nums[numsSize]; ++p)
    {   
        // Start q at the first element:
        q = &nums[0];
        suml = 0;
        sumr = 0;

        // Find the sum of the left-hand side values:
        if (q == p)
            suml += 0;
        while(q < p)
        {
            // Take the sum of the elements:
            suml += *q;
            ++q;
        }

        // Fing the sum of the right-hand side:
        if (q == p)
            ++q;
        while (q > p && q < &nums[numsSize])
        {
            sumr += *q;
            ++q;
        }

        // Check if the sums are eqaul:
        if (sumr == suml)
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