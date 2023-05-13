#include <iostream> 

int main(void)
{
	char letter {'A'};
	std::cout << "The number of the letter, " << letter << " is " << static_cast<int>(letter) << std::endl;
	return 0;
}
