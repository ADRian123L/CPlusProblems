#include <iostream>

int main()
{
	bool red {false};
	bool blue {0};

	// The conditional statements print some text depending on the value of 'red'.
	if (red)
		std::cout << "Red is true." << std::endl;
	else
		std::cout << "Red is false and blue is: " << std::boolalpha << blue << " and the size of a boolean type in C++ is: " << sizeof(bool) << " byte." << std::endl;

	return 0;
}
