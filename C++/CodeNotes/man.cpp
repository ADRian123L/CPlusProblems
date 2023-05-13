/*
    The program is meant to practice C++.
*/
#include <iostream>
#include <stdio.h>
#include <string>

// The function takes the power of the base:
int power(int base, int expo)
{
    if (expo == 0)
        return 1;

    int p = base;

    for (; expo > 1; --expo)
        p *= base;

    return p;
}

int initialization(int);

int main(int argc, char **argv)
{
    // Data input/output:
    int number_2, number_3, number_4;
    int number_1 {15}; // Brace initialization.
    int num (8); // Functional initialization.
    number_2 = 017; // Assignment initialization.
    number_3 = 0xF;
    number_4 = 0b1111;
    

    // Functional initialization:
    int number_initialized_by_function (9);
    std::cout << "The number is: " << number_initialized_by_function << std::endl;
}

int initialization (int nums)
{
    int initialize_num_to_zero {};
    return initialize_num_to_zero;
}