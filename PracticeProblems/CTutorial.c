/* Name: Ctutorial.c */
/* Purpose: Prints some statements. */
/* Author: Adrian */

// The preprocessor:
#include <stdio.h> // The header file.
#include <stdlib.h>

// Variables:
int number = 78;
float decimal[] = {67.9, 897, 876, 67};
char name = 'L';
char place[] = "USF";
double big_num = 9799.098778990;
// functions:

int main(){

    printf("%.2f\n", big_num);
    return 0;
}
