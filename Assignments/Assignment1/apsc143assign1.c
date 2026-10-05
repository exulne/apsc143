// this code is human written and likely apparent
#include <stdio.h>
#include <math.h>
// sqrt(x), cos() and acos, M_PI

// function definitions
double cubicFunction(double a, double b, double c, double x);
double discriminant(double a, double b, double c);
double cubicRoot1(double a, double b, double c);
double cubicRoot2(double a, double b, double c);
double cubicRoot3(double a, double b, double c);

double calcQ(double a, double b, double c);
double calcR(double a, double b, double c);
double calcTheta(double Q, double R);

// main function
int main(void){
    double a = 3;
    double b = -6;
    double c = -8;

    printf("%f, %f, %f, %f,\n", discriminant(a, b, c), cubicRoot1(a, b, c), cubicRoot2(a, b, c), cubicRoot3(a, b, c));
}

// functions declared specifically because the segments are used across all other functions and are therefore turned into functions for reuse
double calcQ(double a, double b, double c){
    return ((3 * b - pow(a, 2))/9); 
}

double calcR(double a, double b, double c){
    return ((9 * a * b - 27 * c - 2 * pow(a, 3))/54);
}

double calcTheta(double Q, double R){
    return (acos(R/sqrt(-pow(Q, 3))));
}

double cubicFunction(double a, double b, double c, double x){
    return (pow(x, 3) + a * pow(x, 2) + b * x + c);
}

double discriminant(double a, double b, double c){
    double Q = calcQ(a, b, c);
    double R = calcR(a, b, c);

    return (pow(Q, 3) + pow(R, 2));
};
double cubicRoot1(double a, double b, double c){
    double Q = calcQ(a, b, c);
    double R = calcR(a, b, c);

    double theta = calcTheta(Q, R);
    return (2 * sqrt(-Q) * cos(theta/3) - a/3);
};
double cubicRoot2(double a, double b, double c){
    double Q = calcQ(a, b, c);
    double R = calcR(a, b, c);

    double theta = calcTheta(Q, R);
    return (2 * sqrt(-Q) * cos(theta/3 + (2 * M_PI)/3) - a/3);
};

double cubicRoot3(double a, double b, double c)
{
    double Q = calcQ(a, b, c);
    double R = calcR(a, b, c);

    double theta = calcTheta(Q, R);
    return (2 * sqrt(-Q) * cos(theta/3 + (4 * M_PI)/3) - a/3);
};
;
