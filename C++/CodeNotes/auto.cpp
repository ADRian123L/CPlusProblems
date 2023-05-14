#include <iostream>

int main(void)
{
	auto num {12};
	auto decimal {23.34};
	auto name {"Adrian"};
	auto c {'Z'};
	std::cout << "The value stored in num is: " << num << ". The size is: " << sizeof(num) << std::endl;
	std::cout << "The value stored in name is: " << name << ". The size is: " << sizeof(name) << std::endl;
	return 0;
}
