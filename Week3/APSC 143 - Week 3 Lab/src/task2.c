// Include standard IO library
#include <stdio.h>
// Include standard math library
#include <math.h>

// Define the mathematical constant pi for build toolchains that do not come with it.
#ifndef M_PI
    #define M_PI 3.1415926535897932384626433
#endif

/*
Write code to calculate properties of a sphere of radius r. Specifically,
    1. Declare appropriately named variables for the radius, circumference, cross-sectional area, surface area, and volume of a sphere.
    2. Initialize the radius to 8 
    3. Calculate and store the circumference of the sphere (i.e., the circumference of the circle).
    3. Calculate and store the cross-sectional area of the sphere (i.e., the area of a circle).
    4. Calculate and store the surface area of the sphere.
    5. Calculate and store the volume of the sphere.
    6. Modify the provided print code to output the value of your variables.

Note:
   - The function pow(x, n) provided by the library math.h calculates the value of x to the power of n, i.e., pow(x, n) is x^n
   - You can access the mathematical constant pi with M_PI
*/
int main()
{


    // Print out the calculated properties of a sphere.
    printf("The properties of a sphere of radius XYZ are:\n");
    printf("    circumference: XYZ\n");
    printf("    cross-sectional area: XYZ\n");
    printf("    surface area: XYZ\n");
    printf("    volume: XYZ\n");

    return 0;
}
