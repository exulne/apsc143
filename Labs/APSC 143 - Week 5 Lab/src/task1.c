#include <stdbool.h>
#include <stdio.h>

/////////////////////////////////////////////////////
// Your Function declarations:

// canGraduate: Returns true if a given selection of
// units can graduate, otherwise returns false.
bool canGraduate(int math, int natSci, int engSci, int engDesign, int compStudies);

/////////////////////////////////////////////////////

int main()
{
    // TODO: Write code to test your function here.

    int math = 195;
    int natSci = 195;
    int engSci = 225;
    int engDesign = 225;
    int compStudies = 225;

    bool isGrad = canGraduate(math, natSci, engSci, engDesign, compStudies);
    
    printf("canGraduate(%d, %d, %d, %d, %d) = ", math, natSci, engSci, engDesign, compStudies);
    if (isGrad)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    
    return 0;
}

/////////////////////////////////////////////////////
// Your function definitions

/*
    Returns true if the given units are sufficient to graduate, otherwise false.
    Arguments
        math - the number of units in mathematics
        natSci - the number of units in natural sciences
        engSci - the number of units in engineering science
        engDesign - the number of units in engineering design
        compStudies - the number of units in complementary studies
    Return
        True if the student can graduate, false otherwise.

    In order to graduate, a student's units must meet all of the following criteria:
        - Mathematics >= 195
        - Natural sciences >= 195
        - Engineering science >= 225
        - Engineering design >= 225
        - Complementary studies >= 225
        - Mathematics + Natural sciences >= 420
        - Engineering science + Engineering design >= 900
        - All combined >= 1850
*/
bool canGraduate(int math, int natSci, int engSci, int engDesign, int compStudies)
{
    // if anyone has to manually read this code I genuinely apologise this is like the worst line of code I've written ytd
    if (math >= 195 && natSci >= 195 && engSci >= 225 && engDesign >= 225 && compStudies >= 225 && math + natSci >= 420 && engSci + engDesign >= 900 && math + natSci + engDesign + engSci + compStudies >= 1850){
        return true;
    }
    else{
        return false;
    }
}

/////////////////////////////////////////////////////
