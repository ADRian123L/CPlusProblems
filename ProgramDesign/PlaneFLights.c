#include <stdio.h>

#define N 4
#define L 2
#define ROW 9
#define COL 2

void find_closest_flight(int, int *, int *);

int main(void)
{
    // Initializing variables:
    char period[N], *j = period, 
        period_2[N], *u = period_2;
    int depart[L], arrive[L];
    int departure, arrival;
    int time[2], real_time;

    // Prompt for the time:
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &time[0], &time[1]);

    // Convert the inputted time into a single number:
    real_time = time[0] * 100 + time[1];
    
    // Call the find_closest_flight:
    find_closest_flight(real_time, &departure, &arrival);

    // The determine if the time is after noon:
    if (departure >= 1200)
        j = "p.m.";
    else
        j = "a.m.";
    // For arrival:
    if (arrival >= 1200)
        u = "p.m.";
    else
        u = "a.m.";

    // Convert the departure and arrival times into twelve-hour times:
    depart[0] = (int) departure / 100;
    depart[1] = (int ) departure % 100;
    arrive[0] = (int) arrival / 100;
    arrive[1] = (int ) arrival % 100;

    printf("The closet departure time is %d:%d %s, arriving at %d:%d %s.\n", depart[0], depart[1], j, arrive[0], arrive[1], u);
    
    return 0;
}


void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
    // Flight schedule:
    int time[ROW][COL] = {{800, 1016}, 
                        {943, 1152}, 
                        {1119, 1331}, 
                        {1247, 1500}, 
                        {1400, 1608}, 
                        {1548, 1755}, 
                        {1900, 2120}, 
                        {2145, 2358}, 
                                   0};
    
    // Save the indexes of the flights:
    int indexes[2] = {0},
            *j = indexes;

    // Locate the closest departure time:
    for (int (*p)[COL] = &time[0]; p < &time[ROW - 1]; ++p)
        if ((desired_time) >= **p && (desired_time) <= *(*p + 1))
            *j++ = p - &time[0] + 1;
    
    // Initializing variables for string the results:
    int diff_1, 
        diff_2, 
        *k = indexes;

    printf("The values of indexes are: %d and %d.\n", indexes[0], indexes[1]);
    
    // Finding which is the closest departure time:
    diff_1 = time[*k - 1][1] - desired_time;
    diff_2 = time[*(++k) - 1][1] - desired_time;

    // The absolute value:
    if (diff_1 < 0)
        diff_1 *= -1;
    if (diff_2 < 0)
        diff_2 *= -1;
    
    int element;
    if (diff_1 > diff_2)
        element = indexes[0];
    else
        element = indexes[1];
    
    *departure_time = time[element][0];
    *arrival_time = time[element][1];
}