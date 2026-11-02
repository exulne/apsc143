/***************************************************
TASK 2

Make a function that cuts a string at the first
instance of the given character and flips the two
halves, i.e., "first-last" would become "last-first"
if flipped around the character '-'.
    bool flipCString(char cstring[], char cutChar);

Return true if the flip was completed successfully,
false otherwise.

Your function must be safe for input stings that do
not properly have a null character within the first
LENGTH characters.

Your function must always return a null-terminated string.

Gradescope will test your function only, not your main.
****************************************************/

// C library to perform Input/Output operations
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define LENGTH 20

/////////////////////////////////////////////////////
// Your Function declarations:

// flipCString: Flip a string around the (first instance) of a given character
bool flipCString(char cstring[], char cutChar);

/////////////////////////////////////////////////////



// Main program
int main() {
    // Write whatever you need in this main function to develop and test your code.
    // Gradescope will not use it but instead call and test your function directly.

    return 0;
}



/////////////////////////////////////////////////////
// Your function definitions

/*
    Flip the current string around the given character, e.g.,
    the string "left-right" would become "right-left" when flipped
    around the character '-'.
    Arguments:
        cstring - A string
        cutChar - A character about which to flip the string, if present
    Return:
        True if the flip was completed, false otherwise
*/
bool flipCString(char cstring[], char cutChar) {
    // TODO: Write your code here
    if (cstring == NULL){
        return false;
    }

    int len = 0;
    while (len < LENGTH && cstring[len] != '\0'){
        len++;
    }

    if (len == LENGTH) {
        cstring[LENGTH - 1] = '\0';
        len = LENGTH - 1;
    }

    int cut = -1;
    for (int i = 0; i< len; i++){
        if (cstring[i] == cutChar){
            cut = i;
            break;
        }
    }

    if (cut == -1){
        return false;
    }

    char temp[LENGTH];
    int t = 0;

    for (int i = cut + 1; i < len; i++){
        temp[t++] = cstring[i];
    }
    temp[t++] = cutChar;
    for (int i = 0; i < cut; i++){
        temp[t++] = cstring[i];
    }
    temp[t] = '\0';

    for (int i = 0; i <= len; i++){
        cstring[i] = temp[i];
    }

    return true;
    
}

/////////////////////////////////////////////////////
