/*
    Purpose: The program reads a cvs file. Stores the contents of the file.
	     And sorts the content of the file by the score on assigned to 
             each coffee type. Afterwards, the program writes the sorted 
     	     information into a file.
    Author: Adrian Lozada
*/
#include <stdio.h>
#include <stdlib.h>

#define STR_LN 150
#define MAX_COFFEE 100
#define MAX_NAME 100

struct Coffee
{
    char country[STR_LN + 1];
    char region[STR_LN + 1];
    char owner[STR_LN + 1];
    char variety[STR_LN + 1];
    double score;
};

int comparison(const void *p, const void *q);
int read_csv(char *name, struct Coffee list[]);
void writer(char *file_name, struct Coffee list[], int n);
void output_name(char *source, char *out);

int main(void)
{
    // Prompt for the name of the file:
    char name[MAX_NAME];
    printf("Enter the file name: ");
    scanf("%s", name);
    // Get the output file's name:
    char out_name[MAX_NAME];
    output_name(name, out_name);
    // Initialize structs of coffee:
    struct Coffee coffee[MAX_COFFEE];
    // Copy the csv's contents into coffee:
    int num_coffees = 0;
    num_coffees = read_csv(name, coffee);
    // Check if the file opened:
    if (num_coffees == -1)
	return 0;
    // Sort the structs:
    qsort(coffee, num_coffees, sizeof(struct Coffee), comparison);
    // Save the sorted info:
    writer(out_name, coffee, num_coffees); 
    // Print the name of the output file:
    printf("%s", out_name); 
    return 0;
}

void output_name(char *source, char *out)
{
    /// @brief The function renames the input name by appending it to 'sorted_'.
    /// @param source is the name of the input file.
    /// @param out is the address where the modified name will be stored.
   
    // Copy the 'sorted_' into out:
    char *append = "sorted_";
    for (; *append; ++out, ++append)
        *out = *append;
    // Append the name of the file into out:
    for (;*source; ++source, ++out)
        *out = *source;   
}

int read_csv(char *name, struct Coffee list[])
{
    /// @brief The function stores the content of a csv file into a struct array.
    /// @param name is the input file name.
    /// @param list is the array of structs.
    /// @return the number of elements in the array.
 
    // Open the file:
    FILE *pFile;
    pFile = fopen(name, "r");
    if (pFile == NULL)
        return -1;
    // Copy the content of the file:
    int i = 0;
    for (; (!feof(pFile)&&!ferror(pFile)); ++i)
       fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %lf\n", list[i].country, list[i].region, list[i].owner, list[i].variety, &list[i].score);
    fclose(pFile);
    return i;
}

void writer(char *file_name, struct Coffee list[], int n)
{
    /// @brief The function writes the content stored in an array of structs.
    /// @param file_name is the name of where the content will be saved.
    /// @param list is the array of stuct.
    /// @param n the number of elements in the array.

    // Open the file:
    FILE *pFile;
    pFile = fopen(file_name, "w");
    if (pFile ==  NULL)
        return;
    // Write the data to the file: 
    for (int i = 0; i < n; ++i)
        fprintf(pFile, "%s,%s,%s,%s,%.2lf\n", list[i].country, list[i].region, list[i].owner, list[i].variety, list[i].score);
    fclose(pFile);
}

int comparison(const void *p, const void *q)
{
	/// @brief the function return 1 if the fisrt argument is smaller then the second, 0 if they are equal, otherwise 1.
	if (((struct Coffee *) p) -> score > ((struct Coffee *) q) -> score)
		return -1;
	else if (((struct Coffee *) p) -> score == ((struct Coffee *) q) -> score)
		return 0;
	else
		return 1;
}	
