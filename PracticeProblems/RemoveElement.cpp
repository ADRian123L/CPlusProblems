#include <iostream>

int main (void)
{
	return 0;
}

int removeElement(int* nums, int numsSize, int val)
{
    // Initialize k (counter) to zero:
    int k = 0;
    // Iterate through the array searching for integers that equal val:
    for (int *p = nums + numsSize - 1; p > nums - 1; --p)
    {
        // Move any integer that equal val to the end of the loop:
        if (*p == val)
        {
           *p = nums[numsSize - k - 1];
           ++k;
        }
    }
    return numsSize - k;
}

int removeElement(int* nums, int numsSize, int val)
{
	int k = 0;
	for (int i = numsSize; i > 0; --i)
	{
		if (nums[i - 1] == val)
		{
			nums[i - 1] = nums[numsSize - k - 1];
			++k;
		}
	}
	
	return numsSize - k;
}
