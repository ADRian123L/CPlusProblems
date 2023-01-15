/*
    Name: Project1.c
    Purpose: The program calculates the total cost of an event depending 
             on the package selected and the number of hours and people attending.
    Author: Adrian Lozada
*/

#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

// Array Variables:
const unsigned int package_options[3] =  {1, 2, 3};
const unsigned int package_1[6] = {50, 25, 95, 50, 200, 25};
const unsigned int package_2[6] = {30, 15, 55, 80, 300, 22};
const unsigned int package_3[6] = {20, 12, 40, 30, 150, 20};

// The Struct stores the package number, hours, people, 
// the info array, the invalid number of people, and the total:
struct Info {
    int package,
        hours,
        people,
        info[6], // 0: base fee, 1: hourly fee, 2: max fee, 3: min people, 4: max people, 5: per person fee
        invalid_num_people,
        total;

};  

// Initialize the struct:
struct Info Reserve;

// Functions:
void get_info(void);
int check_package(void);
int check_hours(void);
int check_people(void);
void calc_total(void);
void change_info(void);
void copy_list(const unsigned int list[], int length, int start);

// Main functions:
int main(void) {
    // Drive the program:
    get_info();

    return 0;
}

// Runs the program:
void get_info(void) {

    do {

    // Get the package number:
    printf("Please select from three packages: 1, 2, and 3\n");
    printf("Enter package selection: ");
    scanf("%d", &Reserve.package);
    // Check if the number is within range:
    if (!check_package()) {
        printf("Invalid selection. Select from 1 to 3.\n");
        break;
    }
    // Get the hours:
    printf("Enter hours: ");
    scanf("%d", &Reserve.hours);
    // Check if the number is within range:
    if (!check_hours()) {
        printf("Invalid input. Enter a positive number less than or equal to 4 for number of hours.\n");
        break;
    }
    // Get the number of people:
    printf("Enter number of people: ");
    scanf("%d", &Reserve.people);
    // Call the change function:
    change_info();
    // Check if the number of people is within range:
    if (!check_people()) {
        
        // Print the error message:
        switch (Reserve.invalid_num_people) {
        case 1:
            printf("Not meeting minimum requirement for number of guests.\n");
            break;
        case 2:
            printf("Exceeded maximum number of guests.\n");
            break;
        default:
            break;
        }
        break;
    }
    // Call the total function:
    calc_total();
    // Print the result:
    printf("Charge($): $%d\n", Reserve.total);
    break;
    
    } while (true);
}

// The function checks if the package is valid:
int check_package(void) {
    // Loop through all possible options
    for (int i = 0; i < 3; ++i) {
        // Check if the package matches one of the options
        if (Reserve.package == package_options[i]) {
            // If it does, return 1
            return 1;
        }
    }
    // If it gets through the whole loop without returning 1, return 0
    return 0;
}

// The function checks if the hours is valid:
int check_hours(void) {
    // check if hours is greater than 1 and less than 4
    if (Reserve.hours >= 1 && Reserve.hours <= 4) {
        // if so, return 1
        return 1;
    }
    // if not, return 0
    return 0;
}

// The function checks if the people is valid:
int check_people(void) {
    // If the number of people is less than the minimum number of people
    if (Reserve.people < Reserve.info[3]) {
        // Set invalid_num_people to 1
        Reserve.invalid_num_people = 1;
        // Return 0
        return 0;
    }
    // Else if the number of people is more than the maximum number of people
    else if (Reserve.people > Reserve.info[4]) {
        // Set invalid_num_people to 2
        Reserve.invalid_num_people = 2;
        // Return 0
        return 0;
    }
    // Return 1
    return 1;
}

// The function changes the info array:
void change_info(void) {

    // Check which package is selected and copy the array of strings
    //   to the info array.
    switch (Reserve.package) {
    case 1:
        copy_list(package_1, 0, 6);
        break;
    case 2:
        copy_list(package_2, 0, 6);
        break;
    case 3:
        copy_list(package_3, 0, 6);
        break;
    default:
        break;
    }

}

// The function copies an array:
void copy_list(const unsigned int lists[], int start, int end) {

    // check to see if the length is greater than the start
    if (end > start) {
        // if it is, then copy the value at the start position
        // into the new array
        Reserve.info[start] = lists[start]; 
        // now call the function again, incrementing the start
        // position by 1
        copy_list(lists, ++start, end);
    } 

}

// The function calculates the total:
void calc_total(void) {
    // Calculate the total fees:
    Reserve.total = Reserve.info[0] + Reserve.info[1] * (Reserve.hours - 1);
    // Check if the total is greater than the maximum:
    (Reserve.total > Reserve.info[2]) ? (Reserve.total = Reserve.info[2]): (Reserve.total);
    // Add the cost of each person:
    Reserve.total += Reserve.info[5] * Reserve.people;
}