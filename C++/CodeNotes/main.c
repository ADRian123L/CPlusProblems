#include <stdio.h>

#define MAX(x, y) (((x) > (y)) ? (x): (y))

int main(int argc, char *argv[])
{
    printf("The greater value between the argc or 2 is: %d", MAX(argc, 3));
    return 0;
}