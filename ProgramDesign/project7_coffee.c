/*
    Purpose: The program reads a cvs file. Stores the contents of the file.
	     And sorts the content of the file by the score on assigned to 
             each coffee type. Afterwards, the program writes the sorted 
     	     information into a file.
    Author: Adrian Lozada
*/
#include <stdio.h>

#define STR_LN 150

struct Coffee
{
    char country[STR_LN + 1];
    char region[STR_LN + 1];
    char onwner[STR_LN + 1];
    char variety[STR_LN + 1];
    double score;
};

int read_csv(char *name, struct Coffee list[]);
void selection_sort_coffee(struct Coffee list[], int n);
void writer(char *file_name, struct Coffee list[], int n);
void output_name(char *source, char *out);

int main(void)
{
    // Prompt for the name of the file:
    char name[100];
    printf("Enter the file name: ");
    scanf("%s", name);
    // Get the output file's name:
    char out_name[100];
    output_name(name, out_name);
    // Initialize structs of coffee:
    struct Coffee coffee[100];
    // Copy the csv's contents into coffee:
    int num_coffees = 0;
    num_coffees = read_csv(name, coffee);
    // Check if the file opened:
    if (num_coffees == -1)
	return 0;
    // Sort the structs:
    selection_sort_coffee(coffee, num_coffees);
    // Save the sorted info:
    writer(out_name, coffee, num_coffees); 
    // Print the name of the output file:
    printf("%s", out_name); 
    return 0;
}

void output_name(char *source, char *out)
{
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
    // Open the file:
    FILE *pFile;
    pFile = fopen(name, "r");
    if (pFile == NULL)
        return -1;
    // Copy the content of the file:
    int i = 0;
    for (; (!feof(pFile)&&!ferror(pFile)); ++i)
       fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %lf\n", list[i].country, list[i].region, list[i].onwner, list[i].variety, &list[i].score);
    fclose(pFile);
    return i;
}

void writer(char *file_name, struct Coffee list[], int n)
{
    // Open the file:
    FILE *pFile;
    pFile = fopen(file_name, "w");
    if (pFile ==  NULL)
        return;
    // Write the data to the file: 
    for (int i = 0; i < n; ++i)
        fprintf(pFile, "%s,%s,%s,%s,%.2lf\n", list[i].country, list[i].region, list[i].onwner, list[i].variety, list[i].score);
    fclose(pFile);
}
// {1, 3, 2, 5} -> {5, 3, 2, 1} -> {5, 
void selection_sort_coffee(struct Coffee list[], int n)
{
    if (n <= 1)
        return;
    int sm = 0;
    struct Coffee tmp; 
    
    for (int i = 0; i < n; ++i)
        if (list[i].score < list[sm].score)
	    sm = i;

    if (sm < n - 1)
    {
        tmp = list[n - 1];
        list[n - 1] = list[sm];
        list[sm] = tmp;
    }

    selection_sort_coffee(list, n - 1);
}	 
