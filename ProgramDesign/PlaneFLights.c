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

    // Output the result:
    printf("The closet departure time is %d:%d %s, arriving at %d:%d %s.\n", 
            depart[0], depart[1], j, arrive[0], arrive[1], u);
    
    return 0;
}


void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
    // Flight schedule:
    int time[ROW][COL] = {{800, 1016},  // 0
                        {943, 1152},    // 1
                        {1119, 1331},   // 2
                        {1247, 1500},   // 3
                        {1400, 1608},   // 4
                        {1548, 1755},   // 5
                        {1900, 2120},   // 6
                        {2145, 2358},   // 7
                                   0};  // 8
    
    // Save the indexes of the flights:
    int indexes[2] = {0},
            *j = indexes;

    // Locate the closest departure time:
    for (int (*p)[COL] = &time[0]; p < &time[ROW - 1]; ++p)
        if ((desired_time) >= **p && (desired_time) <= *(*p + 1))
            *j++ = (p - &time[0]) * 100;
    
    // Initializing variables for storing the results:
    int diff_1, 
        diff_2, 
        *k = indexes;
    int element;

    // Find which is the closest index:
    if (indexes[0] == 0)
        element = indexes[1] / 100;
    else if (indexes[1] == 0)
        element = indexes[0] / 100;
    else
        {
            int temp1, temp2, temp3, temp4;
            temp1 = time[indexes[0] / 100][1] - desired_time;
            temp2 = time[indexes[1] / 100][1] - desired_time;
            temp3 = (temp1 * temp1);
            temp4 = (temp2 * temp2); 
            element = (temp3 > temp4) ? (indexes[1] / 100) : (indexes[0] / 100);
        }
    
    // Return the values:
    *departure_time = time[element][0];
    *arrival_time = time[element][1];
}