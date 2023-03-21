#include <stdio.h>

int main(int argc, char* argv[])
{

    FILE *file;

    
    file = fopen("planets.txt", "r");

    if (file == NULL)
    {
	printf("Cannot open file\n");
	return 0;
    }
    char content[20][20], *p = content[0];

    for (; fgets(p, 199, file) != NULL;++p)

    printf("%s\n", p);

    fclose(file);
	 
    return 0;
}
