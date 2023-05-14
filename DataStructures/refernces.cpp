#include <iostream>

int main(void)
{
	// Declaring and Initializing int variable, a.
	int a {10};
	// Declaring and Initializing reference varible r.
	int &r = a;
	std::cout << "The value in a: " << a << ". The value in the reference value r: " << r << std::endl;
	return 0;
}
