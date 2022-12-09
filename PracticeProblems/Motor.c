#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Constants:
const double PI = 3.14159265;

// A function that prompts for a degree:
int direction(void) {
    // Empty variable:
    int degree;
    // Prompt for degrees:
    printf("The direction in degree: ");
    scanf("%d", &degree);
    return degree;
}

// Converts to radians:
double converter(double degree) {

    // Empty variable:
    double radian;
    // Converts it to radians:
    radian = (degree * (PI / 180));
    
    // Print the value of radians:
    printf("Radians: %lf\n", radian);

    return radian;
}

int x_components(double radian) {

    // Empty variables:
    int sign;
    double value_x;

    // Finds the component:
    value_x = round(cos(radian));
    

    printf("Cos Value: %lf\n", value_x);

    if (value_x > 0) {
        sign = 1;
    }
    else if (value_x == 0) {
        sign = 0;
    }
    else {
        sign = -1;
    }
    printf("Sign-X: %d\n", sign);

    return sign;
}

// Function for calculating y-component:
int y_component(double radian_y) {

    // Variable:
    int sign_y;
    double value_y;

    value_y = round(sin(radian_y));
    printf("value y %lf\n", value_y);
    
    if (value_y > 0) {
        sign_y = 1;
    }
    else if (value_y == 0) {
        sign_y = 0;
    }
    else {
        sign_y = -1;
    }

    // Prints the value of y:
    printf("SignY: %d\n", sign_y);

    return sign_y;
}

// Function for calculating the coefficient of the motors:
void motor_control(int xcomp, int ycomp){
    
    if (xcomp == 1 && ycomp == 1){
        printf("%d, %d, %d, %d\n", 1, 0, -1, 0);
    }
    else if (xcomp == 0 && ycomp == 1){
        printf("%d, %d, %d, %d\n", 1, 1, -1, -1);
    }
    else if (xcomp == 1 && ycomp == 0) {
        printf("%d, %d, %d, %d\n", 1, -1, -1, 1);
    }
    else if (xcomp == -1 && ycomp == 0){
        /* code */
        printf("%d, %d, %d, %d\n",-1, 1, 1, -1);
    }
    else if (xcomp == -1 && ycomp == -1){
        /* code */
        printf("%d, %d, %d ,%d\n", -1, 0, 1, 0);
    }
    else if (xcomp == -1 && ycomp == 1){
        /* code */
        printf("%d, %d, %d, %d\n", 0, 1, 0, -1);
    }
    else if (xcomp == 1 && ycomp == -1){
        /* code */
        printf("%d, %d, %d, %d\n", 0, -1, 0, 1);
    }
    else if (xcomp == 0 && ycomp == -1){
        /* code */
        printf("%d, %d, %d, %d\n", -1, -1, 1, 1);
    }
    
}

// Driver:
int main(void) {

    // Variables:
    int get_degree, 
        get_x, 
        get_y;
    double get_radian;

    // Call the functions:
    get_degree = direction();
    get_radian = converter(get_degree);
    get_x = x_components(get_radian);
    get_y = y_component(get_radian);
    motor_control(get_x, get_y);
    
    return 0;

} 