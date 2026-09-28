#include <stdio.h>
#include <math.h>

/***************************************************
TASK 2 - Using functions to break up complicated problems

The roots to the quadratic equation ax^2 + bx + c = 0 are
given by:
    x1 = (-b + sqrt(delta)))/(2a)
    x2 = (-b - sqrt(delta)))/(2a)
where the discriminant is defined as:
    delta = b^2 - 4ac
Calculate the two roots by breaking up the problem into 3
different functions, which must have the following signatures:
    double quadraticRoot1(double a, double b, double c);
    double quadraticRoot2(double a, double b, double c);
    double discriminant(double a, double b, double, c);

Hints:
  - You only need to handle real roots (i.e., the discriminant
    will never be negative).
  - Write the discriminant first and then the root equations.
  - The library math.h provides sqrt(x), and pow(x, n).
****************************************************/

/////////////////////////////////////////////////////
// Your Function declarations:

// discriminant: Calculate the discriminant of the given quadratic equation.
double discriminant(double a, double b, double c);
// quadraticRoot1: Calculate the first root for the given quadratic equation. Will only work on real roots.
double quadraticRoot1(double a, double b, double c);
// quadraticRoot2: Calculate the second root for the given quadratic equation. Will only work on real roots.
double quadraticRoot2(double a, double b, double c);

/////////////////////////////////////////////////////



int main()
{
    // Write whatever you need in this main function to develop and test your code.
    // Gradescope will not use it but instead call and test your function directly.

    // Define the quadratic equation ax^2 + bx + c = 0
    double a = 1.0;
    double b = -5.0;
    double c = -14.0;

    // Calculate the roots of the given quadratic equation
    double root1 = quadraticRoot1(a,b,c);
    double root2 = quadraticRoot2(a,b,c);

    // Print out the result:
    printf("The roots of %fx^2 + %fx + %f = 0 are %f and %f\n", a, b, c, root1, root2);
    
    return 0;
}



/////////////////////////////////////////////////////
// Your function definitions

/*
    Calculate the discriminant of the quadratic equation of the form ax^2 + bx + c = 0.
    Arguments
        a - the x^2 coefficient.
        b - the x coefficient.
        c - the constant.
    Return
        The discriminant of the given quadratic equation.
*/
double discriminant(double a, double b, double c)
{
    // TODO: Write your code here.
}

/*
    Calculate the first solution to the quadratic equation of the form ax^2 + bx + c = 0.
    Arguments
        a - the x^2 coefficient.
        b - the x coefficient.
        c - the constant.
    Return
        The first root of the given quadratic equation.
*/
double quadraticRoot1(double a, double b, double c)
{
    // TODO: Write your code here.
}

/*
    Calculate the second solution to the quadratic equation of the form ax^2 + bx + c = 0.
    Arguments
        a - the x^2 coefficient.
        b - the x coefficient.
        c - the constant.
    Return
        The second root of the given quadratic equation.
*/
double quadraticRoot2(double a, double b, double c)
{
    // TODO: Write your code here.
}

/////////////////////////////////////////////////////
