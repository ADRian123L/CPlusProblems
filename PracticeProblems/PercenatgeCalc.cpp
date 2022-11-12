/*
    PROGRAM: PercenatgeCalc.cpp
    Written by Adrian
    This program calculates retirement savings
    Last modification: 11/12/2022
*/

#include <iostream>

int main(){
    
    // Variables to hold the pay:
    double monthPay = 7800.00, contributing;
    
    // Constants that hold the percentages:
    const float 
        FIVE = 0.05, 
        SEVEN = 0.07, 
        TEN = 0.10;


    // Calculates the monthly contribution at five percent:
    contributing = monthPay * FIVE;
    std::cout << "\n" << contributing << "\n";

    // Calculates the monthly contribution at seven percent:
    contributing = monthPay * SEVEN;
    std::cout << "\n" << contributing << "\n";

    // Calculates the monthly contribution at ten percent:
    contributing = monthPay * TEN;
    std::cout << "\n" << contributing << "\n";

    // Output the last contribution (10%):
    std::cout << "\nAt 10% the contribution is: " << contributing << "." << "\n";

    return 0;
}