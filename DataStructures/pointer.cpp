#include <iostream>
#include <stdlib.h>

int main(void)
{
	int a = 12;
	int *p;
	p = &a;
	std::cout << "The value that p points to: " << *p << " and the address of: " << p << std::endl;
	// Allocating heap memory:
	int *q;
	q = new int[5];
	*q=3;
	std::cout << "Created an array of 5 elements: " << *q << " and the address of q is: " << q << std::endl; 
	delete [] q;
	return 0;
}
