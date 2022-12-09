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

// functions:

void out1();
int min(int first, int second, int third);
void out(int biggest);
int prompt(void);
int max(int nums[3]);

int main(){


    // Calls the functions:
    int number = prompt();
    int calculate = max(&number);
    out(calculate);

    return 0;
}

void out1(void){

    printf("It works!!!\n");

}

int min(int first, int second, int third){
    int smallest;
    if (first < second && first < third){
        smallest = first;
    }
    else if (second < third && second < first){
        smallest = second;
    }
    else {
        smallest = third;
    }

    return smallest;
}

int prompt(void){

    // Empty array:
    int elements[3];

    // Prompts for three numbers:
    scanf("%d%d%d", &elements[0], &elements[1], &elements[2]);

    return elements;
}

int max(void){
    
    // Empty array:
    int elements[3];

    // Prompts for three numbers:
    scanf("%d%d%d", &elements[0], &elements[1], &elements[2]);

    // Variables:
    const int ONE = elements[0], 
              TWO = elements[1], 
              THREE = elements[2];
    
    int largest_num = 0;

    // Compare:
    if (ONE > TWO && ONE > THREE){
        largest_num = ONE;
    }

    else if (TWO > THREE && TWO > ONE){
        largest_num = TWO;
    }

    else {
        largest_num = THREE;
    }

    return largest_num;    
}

void out(int biggest_number) {
    printf("%d\n", biggest_number);
}