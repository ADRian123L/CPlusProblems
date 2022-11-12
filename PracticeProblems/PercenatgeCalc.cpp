// Author: Adrian
// The program calculates the percentage out of an amount.

#include <iostream>

int main(){
    
    // Variables to hold the pay:
    double monthPay = 7800.00, contributing;

    // Calculates the monthly contribution at five percent:
    contributing = monthPay * 0.05;
    std::cout << "\n" << contributing << "\n";

    // Calculates the monthly contribution at seven percent:
    contributing = monthPay * 0.07;
    std::cout << "\n" << contributing << "\n";

    // Calculates the monthly contribution at ten percent:
    contributing = monthPay * 0.10;
    std::cout << "\n" << contributing << "\n";

    // Output the last contribution (10%):
    std::cout << "\nAt 10% the contribution is: " << contributing << "." << "\n";

    return 0;
}