#include <iostream>

int main(void)
{
	// Declaring and Initializing int variable, a.
	int a {10};
	// Declaring and Initializing reference varible r.
	int &r = a;
    // The cariable 'r' is an alias to variable a. 
    // Therefore, they share the same value and if
    // changwe the other will also be changed.
	std::cout << "The value in a: " << a << ". The value in the reference value r: " << r << std::endl;
	return 0;
}
