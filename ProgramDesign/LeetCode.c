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
    short temp, temp2;

    for (char *p = s, *q = t; *q && *p; ++p, ++q)
    {
	    temp = *q - *p;
	
	    for (char *u = p, *v = q; *u != '\0'; ++u, ++v)
	    {
	        if (*u == *p)
	        {
		        temp2 = *v - *u;
		        if (temp != temp2)
		            return 0;
	        }
	    }

        temp = *p - *q;
	    for (char *u = q, *v = p; *u != '\0'; ++u, ++v)
	    {
	        if (*u == *q)
	        {
		        temp2 = *v - *u;
		        if (temp != temp2)
		            return 0;
	        }
	    }
    }

    return 1;
}  


int main(void)
{
    char b[5] = "1223";
    char a[5] = "3446";
    int bol;
    bol = isIsomorphic(a ,b);

    printf("The value of bool is: %d\n", bol);
    return 0;
}

