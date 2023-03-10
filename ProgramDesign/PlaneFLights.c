#include <stdio.h>

void find_closest_flight(int, int *, int *);

int main(void)
{
    return 0;
}


void find_closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
    // Flight schedule:
    int time[][2] = {{800, 1016}, {943, 1152}, {1119, 1331}, 
                    {1247, 1500}, {1400, 1608}, {1548, 1755}, 
                    {1900, 2120}, {2145, 2358}, 0};
    
    int indexes[2] = {0};

    for (int *p = &time[0][0], *j = indexes; p < &time[9][0]; ++p)
    {
        if ((desired_time * 100) >= *p && (desired_time * 100) <= *p +  1)
        {
            *j = p - &time[0][0] + 1;
            ++j;
        }
    }

    int diff_1, diff_2, *k = indexes;

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
