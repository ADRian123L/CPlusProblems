#include <iostream>
#include <stdio.h>

using namespace std;

int main (void)
{
	// Declaring an array:
	int array[19];
	// Initializing an element of an array:
	array[1] = 2;
	
	std::cout << "First course on Data structures: " << array[1] << endl;
	printf("The size of array: %ld and the number of elements in the array are: %d\n", sizeof(array), (int) sizeof(array) / 4);
	cout << array[3];

	return 0;

}
