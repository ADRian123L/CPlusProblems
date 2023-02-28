#include <stdio.h>


int main(void)
{
    char str1[100], *p = str1;
    char ch = getchar();

    while ((ch = getchar() == '/n'))
    {
        if (ch == *p)
            ch = getchar();
        if (*p)
            break;
    }

    return 0;
}

