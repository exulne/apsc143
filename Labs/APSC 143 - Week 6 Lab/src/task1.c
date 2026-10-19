#include <stdbool.h>
#include <stdio.h>

/***************************************************
TASK 1 - Memory Addresses

Write a function that prints out every lowercase
letter on a new line and, if the letter is given as
an input char, also the @ symbol and the address of
the variable storing that letter, e.g.,
a
b @ 0x0001
c
...

Hints:
  - Every variable is stored in computer memory at an
  address and the & operator gets the address of a
  given variable, e.g. an integer variable named var
  is stored at the memory address given by &var
  - A char is always enclosed in single quotes,
  e.g., char var = 'a'.
  - You can increment and decrement and compare a char
  just like an int, e.g., 'a' + 1 == 'b'
****************************************************/

/////////////////////////////////////////////////////
// Your Function declarations:

// addressOfLetters: Iterates through the (lower case)
// alphabet from a--z and prints out the address of the
// input variables next to the letter they store.
void addressOfLetters(char letter1, char letter2, char letter3);

/////////////////////////////////////////////////////

int main ()
{
    addressOfLetters('a', 'd', 'l');
    // TODO Write code to test your function here.
    return 0;
}


/////////////////////////////////////////////////////
// Your function definitions

/*
    Iterate through the alphabet from a to z and print
    out the memory address of the letters stored in the
    variables
    Arguments
        letter1 - A lowercase character from a to z
        letter2 - A lowercase character from a to z
        letter3 - A lowercase character from a to z
    Return
        None
*/

void addressOfLetters(char letter1, char letter2, char letter3)
{
    for (char foo = 'a';foo <= 'z'; foo++){
        printf("%c ", foo);
        if (foo == letter1){
            printf("@ %p", &letter1);
        }
        else if (foo == letter2){
            printf("@ %p", &letter2);
        }
        else if (foo == letter3){
            printf("@ %p", &letter3);
        }
        printf("\n");
        }

    return;
    // TODO Write your function here
}
/////////////////////////////////////////////////////
