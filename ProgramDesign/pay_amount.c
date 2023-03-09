#include <stdio.h>

#define TWENTY 20
#define TEN 10
#define FIVE 5
#define ONE 1

void pay_amount(int dollar, int *twenties, int *tens, int * fives, int *ones);

int main(void)
{
    int amount, tw, tn, fv, one;
    
    printf("Enter the amount of money: ");
    scanf("%d", &amount);

    pay_amount(amount, &tw, &tn, &fv, &one);

    printf("The amount is %d twenty dollar bill, %d ten dollar bills, %d five dollar bills, %d one dollar bills.\n", tw, tn, fv, one);

    return 0;
}

void pay_amount(int dollar, int *twenties, int *tens, int *fives, int *ones)
{
    *twenties = (int) dollar / TWENTY;
    dollar -= *twenties * TWENTY;
    *tens = (int) dollar / TEN;
    dollar -= *tens * TEN;
    *fives = (int) dollar / FIVE;
    dollar -= *fives * FIVE;
    *ones = dollar;
}