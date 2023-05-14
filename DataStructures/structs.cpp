#include <iostream>
#include <stdio.h>

struct R {
	int length;
	int breadth;
	char x;
};

int main(void)
{
	struct R r1;
	r1.length = 23;
	r1.breadth = 2;
	std::cout << "The area of the rectangle is: " << r1.length * r1.breadth << std::endl;
	struct R r2 = {2, 5};
	std::cout << "The area of the second rectangle is: " << r2.length * r2.breadth << ". The size of struct is: " << sizeof(struct R) << std::endl;
}
