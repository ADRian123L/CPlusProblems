#include <iostream>

int main(void)
{
	return 0;
}

int removeDuplicates(int* nums, int numsSize)
{
  // Check if the array has less than two elements:
  if (numsSize < 2)
    return numsSize;
  
  if (nums == NULL)
	return 0;
 
  // The value to replace the repeated ones (1000 is out of the scope of the inputs):
  #define REPLACE 1000

  // Replace with duplicates with a REPLACE:
  for (int *p = nums; p < nums + numsSize - 1; ++p)
    for (int *q = p + 1; q < nums + numsSize; ++q)
      if (*q == *p)
        *q = REPLACE;

  // Move all of the REPLACE to the end:
  for (int *p = nums; p < nums + numsSize - 1; ++p)
    if (*p == REPLACE)
      for (int *q = p + 1; q < nums + numsSize; ++q)
        if (*q != REPLACE)
        {
          *p = *q;
          *q = REPLACE;
          break;
        }

  // Count the number of non-repeating integers:
  int k = 0;
  for (int *p = nums; (p < nums + numsSize); ++p, ++k)
    if (*p == REPLACE)
      break;

  return k;
}

int removeDuplicates (int* nums, int numsSize)
{
	if (numsSize < 2)
		return numsSize;
	
	int index = 1;
	for (int *p = nums + 1; p < nums + numsSize; ++p)
	{
		if (*(p - 1) != *p)
		{
			nums[index] = *p;
			++index;
		}
	}
	return index;
}
