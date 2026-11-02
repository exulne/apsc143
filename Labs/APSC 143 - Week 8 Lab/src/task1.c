/***************************************************
TASK 1

Make a function to count how many times each letter in the alphabet occurs in a given string:
    bool countLetters(char cstring[], int maxLength, int numAZ[]);
        Counts how often the letters A, B, C, ..., Z occur in a given string, regardless of case.
        Returns the number of each letter via the numAZ array and true if the string was successfully processed, false otherwise.

The first element of numAZ (i.e., numAZ[0]) should be how often A occurs in the given string, the second element how often B occurs, etc.

Your function must be safe for input stings that do
not properly have a null character within the first maxLength
characters.

Gradescope will test your function only, not your main.
****************************************************/

// C library to perform Input/Output operations
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/////////////////////////////////////////////////////
// Your Function declarations:

// countLetters: Count and return how many times each letter in the alphabet occurs in a given string.
bool countLetters(char cstring[], int maxLength, int numAZ[]);

/////////////////////////////////////////////////////



// Main program
int main() {
    // Write whatever you need in this main function to develop and test your code.
    // Gradescope will not use it but instead call and test your function directly.
    char s1[20] = "HelloWorld";
    int numAZ[50];
    countLetters(s1, 50, numAZ);
    return 0;
}



/////////////////////////////////////////////////////
// Your function definitions

/*
    Iterate through a given string of a maximum length
    and count how many times each letter appears in it.
    Arguments:
        cstring - A string
        maxLength - The maximum size (i.e., the array size) of the string
        numAZ - An array of 26 elements to return the number of each letter.
    Return:
        True if the search was completed, false otherwise
        An array of letter counts via pass-by-reference
*/
bool countLetters(char cstring[], int maxLength, int numAZ[]) {
    // TODO: Write your code here
    if (cstring == NULL | numAZ == NULL | maxLength < 0){
        return false;
    }

    for (int i = 0; i < 26; i++){
        numAZ[i] = 0;
    }

    for (int i = 0; i< maxLength && cstring[i] != '\0'; i++){
        char c = cstring[i];

        if (c >= 'a' && c <= 'z'){
            numAZ[c - 'a']++;
        }
        else if (c >= 'A' && c <= 'Z'){
            numAZ[c- 'A']++;
        }
    }

    return true;
}

/////////////////////////////////////////////////////
