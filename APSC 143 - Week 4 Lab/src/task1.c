#include <stdio.h>

/***************************************************
TASK 1 - Better code design through functions

Print the song “99 Bottles of Beer” efficiently with
a function that prints just one verse of the song.
The function signature must be:
    int printVerse(int numBottles);
And it takes in the number of bottles at the start of
the verse, and returns the number at the end of the
verse, e.g., for numBottles = 8 it would return 7 and print:

8 bottles of beer on the wall.
8 bottles of beer.
Take one down, pass it around,
7 bottles of beer on the wall.

Make sure the verse ends with a newline.
****************************************************/

/////////////////////////////////////////////////////
// Your Function declarations:

// printVerse: Prints one verse of the song "99 Bottles
// of Beer" and returns the remaining number of bottles.
int printVerse(int numBottles);

/////////////////////////////////////////////////////



int main()
{
    // Write whatever you need in this main function to develop and test your code.
    // Gradescope will not use it but instead call and test your function directly.

    // Print the first 5 verses of the song:
    int num = 99;
    while (num > 94)
    {
        num = printVerse(num);
        printf("---\n");
    }

    return 0;
}



/////////////////////////////////////////////////////
// Your function definitions

/*
    Print out one verse of the song "99 Bottles of Beer"
    Arguments
        numBottles - the number of bottles at the start of the verse.
    Return
        The number of bottles at the end of the verse.
*/
int printVerse(int numBottles)
{
    int sub = numBottles-1;
    printf("%d bottles of beer on the wall.\n%d bottles of beer.\nTake one down, pass it around,\n%d bottles of beer on the wall.\n",numBottles, numBottles, sub, sub);
    return(sub);
}

/////////////////////////////////////////////////////
