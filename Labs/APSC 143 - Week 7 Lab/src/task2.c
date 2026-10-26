/***************************************************
TASK 2

Make a function to create a square multiplication table for the numbers between startNum to (startNum + LENGTH - 1) and startNum to (startNum + LENGTH - 1) and store it in a given array:
    void createMultiplicationTable(int startNum, int returnArray[LENGTH][LENGTH])

Your function MUST assume that the length of the given array is the value given by the global value "LENGTH"

Hints:
- Arrays are always passed to a function as a pointer, i.e., they are passed by reference, so make sure to
    (1) check them appropriately and
    (2) remember that changes to the array in a function will also change it in main.

Specific examples of calls to createMultiplicationTable with a LENGTH of 10:
    - If startNum = 2, the multiplication table is between the numbers 2 to 11 and 2 to 11 and the array contains:
         4   6   8  10  12  14  16  18  20  22
         6   9  12  15  18  21  24  27  30  33
         8  12  16  20  24  28  32  36  40  44
        10  15  20  25  30  35  40  45  50  55
        12  18  24  30  36  42  48  54  60  66
        14  21  28  35  42  49  56  63  70  77
        16  24  32  40  48  56  64  72  80  88
        18  27  36  45  54  63  72  81  90  99
        20  30  40  50  60  70  80  90 100 110
        22  33  44  55  66  77  88  99 110 121
    - If startNum = -5, the multiplication table is between the numbers -5 to 4 and -5 to 4 and the array contains:
        25  20  15  10   5   0  -5 -10 -15 -20
        20  16  12   8   4   0  -4  -8 -12 -16
        15  12   9   6   3   0  -3  -6  -9 -12
        10   8   6   4   2   0  -2  -4  -6  -8
         5   4   3   2   1   0  -1  -2  -3  -4
         0   0   0   0   0   0   0   0   0   0
        -5  -4  -3  -2  -1   0   1   2   3   4
       -10  -8  -6  -4  -2   0   2   4   6   8
       -15 -12  -9  -6  -3   0   3   6   9  12
       -20 -16 -12  -8  -4   0   4   8  12  16

Gradescope will test your function only, not your main function.
****************************************************/

// C library to perform Input/Output operations
#include <stdio.h>
// C library for boolean
#include <stdbool.h>

// The size of your multiplication table, must be 10 when submitting to Gradescope
#define LENGTH 10

/////////////////////////////////////////////////////
// Your Function declarations:

// createMultiplicationTable: Calculates and return the multiplication table between startNum to (startNum + LENGTH - 1) x startNum to (startNum + LENGTH - 1).
bool createMultiplicationTable(int startNum, int returnArray[LENGTH][LENGTH]);
/////////////////////////////////////////////////////



// Main program
int main() {
    // A starting number to test your multiplication table
    int myTestStart = 2;

    // TODO: Write code here to test your function.
    //    - Declare an empty array of size LENGTHxLENGTH
    //    - Call createMultiplicationTable to fill in your array.
    //    - Print out your array to confirm it looks right.

    int table[LENGTH][LENGTH]; 

    createMultiplicationTable(myTestStart, table);

    for (int i = 0; i < LENGTH; i++){
        for (int j = 0; j < LENGTH; j++){
            printf("%d", table[i][j]);
        }
        printf("\n");
    }

    return 0;
}


/////////////////////////////////////////////////////
// Your function definitions

/*
createMultiplicationTable
    preconditions:
        startNum is an integer
        returnArray is a 2D array of size LENGTH x LENGTH
    postconditions:
        returnArray is populate with the multiplication table for startNum to (startNum + LENGTH - 1) x startNum to (startNum + LENGTH - 1)
*/
bool createMultiplicationTable(int startNum, int returnArray[LENGTH][LENGTH]) {
    // TODO: Write your code here
    if (returnArray == NULL){
        return false;
    } 

    for (int i = 0; i < LENGTH; i++){
        for (int j = 0; j < LENGTH; j++){
            returnArray[i][j] = (startNum + i) * (startNum + j);
        }
    }

    return true;
}
/////////////////////////////////////////////////////
