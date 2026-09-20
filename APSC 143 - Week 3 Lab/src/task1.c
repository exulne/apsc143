// Include standard IO library
#include <stdio.h>

/*
    Use operators and variable types to calculate different representation of a fraction.
    
    Note:
        - The result of multiplying or dividing two integers will always be an integer.
        - The process of explicitly converting a datatype to another datatype is known as "casting" , e.g., int a = (int)1.1; double b = (double)1;
        - The modulo operator, %, returns the remainder of division, e.g., 3 % 3 = 0, 4 % 3 = 1, 5 % 3 = 2, etc.
*/
int main()
{
    // Given numerator and denominator
    int numerator = 4;
    int denominator = 3;

    // Calculate the fraction as a real-valued number and the associated whole value and remainder
    double fraction = (double) numerator/denominator;
    int whole_value = numerator / denominator; // the better practice here is to include <math.h> and use floor()
    int remainder = numerator%denominator;

    // Print out the fraction as (1) a common fraction X/Y, (2) a mixed fraction A B/Y, and (3) a real-valued number, A.CDEF
    // For example, if the numerator is 5 and the denominator is 2 this line should print:
    //      5/2 = 2 + 1/2 = 2.500000
    printf("%d/%d = %d + %d/%d = %f.\n", numerator, denominator, whole_value, remainder, denominator, fraction);
    return 0;
}
