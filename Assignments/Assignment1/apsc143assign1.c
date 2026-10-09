// this code is human written and likely apparent
#include <stdio.h>
#include <math.h>

// function definitions
double cubicFunction(double a, double b, double c, double x);
double discriminant(double a, double b, double c);
double cubicRoot1(double a, double b, double c);
double cubicRoot2(double a, double b, double c);
double cubicRoot3(double a, double b, double c);

// helper functions for repeated calculations
double calcQ(double a, double b, double c);
double calcR(double a, double b, double c);
double calcTheta(double Q, double R);

// main function
int main(void){
    // tester function, not accessed by gradescope. Initialises some predefined a, b and c and prints function outputs seperated by commas 
    double a = -1.5;
    double b = -1.5;
    double c = 1;

    printf("%f, %f, %f, %f,\n", discriminant(a, b, c), cubicRoot1(a, b, c), cubicRoot2(a, b, c), cubicRoot3(a, b, c));
}

// below are functions declared specifically because the segments are used across all other functions and are therefore turned into functions for reuse


// Helper function to calculate term Q given by Q = (3b - a^2)/9
double calcQ(double a, double b, double c){
    return ((3 * b - pow(a, 2))/9); 
}

// Helper function to calculate term R given by R = (9ab - 27c - 3a^3)/54
double calcR(double a, double b, double c){
    return ((9 * a * b - 27 * c - 2 * pow(a, 3))/54);
}

// Helper function to calculate theta given by theta = arccos(R/sqrt(-Q^3))
double calcTheta(double Q, double R){
    return (acos(R/sqrt(-pow(Q, 3))));
}

// below are the required assignment functions

// calculate the value of the cubic function defined by x^3 + ax^2 + bx + c = 0
double cubicFunction(double a, double b, double c, double x){
    return (pow(x, 3) + a * pow(x, 2) + b * x + c);
}

// calculate the discriminant given by D = Q^3 + R^3 
double discriminant(double a, double b, double c){
    // call previously defined helper functions to assign a value to initialised values Q and R defined only in this scope
    double Q = calcQ(a, b, c);
    double R = calcR(a, b, c);

    return (pow(Q, 3) + pow(R, 2));
}

// calculate the first root of the cubic equation defined by the equation x_1 = 2sqrt(-Q) * cos(theta/3) - a/3
double cubicRoot1(double a, double b, double c){
    // call previously defined helper functions to assign a value to initialised values Q, R and Theta defined only in this scope
    double Q = calcQ(a, b, c);
    double R = calcR(a, b, c);

    // using Q and R call helper function to calculate theta
    double theta = calcTheta(Q, R);

    // 
    return (2 * sqrt(-Q) * cos(theta/3) - a/3);
}

// calculate the second root of the cubic equation defined by the equation x_2 = 2sqrt(-Q) * cos(theta + 2pi/3) - a/3
double cubicRoot2(double a, double b, double c){
    // as defined above
    double Q = calcQ(a, b, c);
    double R = calcR(a, b, c);

    // as defined above
    double theta = calcTheta(Q, R);

    return (2 * sqrt(-Q) * cos((theta + 2 * M_PI)/3) - a/3);
}

// calculate the third root of the cubic equation as defined by the equation x_3 = 2sqrt(-Q) * cos(theta + 4pi/3) - a/3
double cubicRoot3(double a, double b, double c){
    // as defined above
    double Q = calcQ(a, b, c);
    double R = calcR(a, b, c);

    // as defined above
    double theta = calcTheta(Q, R);
    
    return (2 * sqrt(-Q) * cos((theta +4 * M_PI)/3) - a/3);
}
