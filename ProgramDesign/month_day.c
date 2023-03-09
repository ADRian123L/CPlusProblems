#include <stdio.h>

void month_day(int dy, int year, int *day, int *month);

int main(void)
{
    int year = 0,
        dy = 0;

    int day, month;
    
    printf("Enter the year: ");
    scanf("%d", &year);
    printf("Enter the days: ");
    scanf("%d", &dy);

    // Call the month_function:
    month_day(dy, year, &day, &month);

    printf("The month and day of the year are: %d of %d.\n", day, month);

}

void month_day(int dy, int year, int *day, int *month)
{
    // Length of each month:
    int month_length[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 0};

    // Check if the year is a leap year:
    if ((year % 100 != 0 || year % 400 == 0) && (year % 4 == 0))
        month_length[2] = 29;
    
    for (int *p = &month_length[1]; *p; ++p)
        {
            if (dy - *p <= 0)
            {
                *day = dy;
                *month = p - month_length;
                return;
            }
            else 
                dy -= *p;
        }
}
