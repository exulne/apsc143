#include <stdbool.h>
#include <stdio.h>

/***************************************************
TASK 2 - Dereferencing and Pass-by-reference

Write a function that takes in:
  - 3 numbers as pointers (num1Ptr, num2Ptr, num3Ptr), and
  - 3 pointers to a pointer (smallPtrPtr, middlePtrPtr, largePtrPtr) 

This function will need to "sort" the three input numbers by setting the three pointers-to-a-pointer to respectively point to the smallest, middle, and largest variable.
Note, this is not the smallest, middle, and largest number but the addresses of the variables holding those numbers. These addresses are the input pointers themselves.
If the sort cannot proceed, then the function should return false, otherwise it should return true.

Hints:
  - A pointer stores a memory address and the * operator reads the value stored at that memory address based on the pointer type, e.g.,
    - a pointer of type int* contains the memory address of an int
    - num1Ptr contains the address of a variable of type int and we access the value of that variable via *num1Ptr
****************************************************/

/////////////////////////////////////////////////////
// Your Function declarations:

// sortNumbers: Outputs the sorting of num1Ptr, num2Ptr, num3Ptr
// via smallPtrPtr, middlePtrPtr, and largePtrPtr
bool sortedNumbers(int* num1Ptr, int* num2Ptr, int* num3Ptr, int** smallPtrPtr, int** middlePtrPtr, int** largePtrPtr);

/////////////////////////////////////////////////////

int main()
{
    int num1 = 40;
    int num2 = 10;
    int num3 = 20;

    int *small = NULL;
    int *middle = NULL;
    int *large = NULL;

    bool result = sortedNumbers(&num1, &num2, &num3, &small, &middle, &large);
    
    if (result){
        printf("%d\n%d\n%d\n", *small, *middle, *large);
    }
    else{
        printf("failed");
    }
                            


    // TODO Write code here to test your function. The TA will ask to see how you tested it before uploading to Gradescope.
    return 0;
}


/////////////////////////////////////////////////////
// Your function definitions

/*
    Point to the smallest, middle, and largest variables
    Arguments
        num1Ptr - A pointer to a number
        num2Ptr - A pointer to a number
        num3Ptr - A pointer to a number
        smallPtrPtr - A pointer that will be set to the smallest of the three variables
        middlePtrPtr - A pointer that will be set to the middle of the three variables
        largePtrPtr - A pointer that will be set to the largest of the three variables
    Return
        True if the sorting succeeds. False otherwise.
*/

bool sortedNumbers(int* num1Ptr, int* num2Ptr, int* num3Ptr, int** smallPtrPtr, int** middlePtrPtr, int** largePtrPtr)
{
    if (num1Ptr == NULL || num2Ptr == NULL || num3Ptr == NULL || smallPtrPtr == NULL || middlePtrPtr == NULL || largePtrPtr == NULL){
        return false;
    }
    if (*num1Ptr <= *num2Ptr && *num1Ptr <= *num3Ptr){
        *smallPtrPtr = num1Ptr;
        if (*num2Ptr <= *num3Ptr){
            *middlePtrPtr = num2Ptr;
            *largePtrPtr = num3Ptr;
        }
        else{
            *middlePtrPtr = num3Ptr;
            *largePtrPtr = num2Ptr;
        }
    }
    else if (*num2Ptr <= *num1Ptr && *num2Ptr <= *num3Ptr)
    {
        *smallPtrPtr = num2Ptr;

        if (*num1Ptr <= *num3Ptr){
            *middlePtrPtr = num1Ptr;
            *largePtrPtr = num3Ptr;
        }
        else{
            *middlePtrPtr = num3Ptr;
            *largePtrPtr = num1Ptr;
        }
    }
    else{
        *smallPtrPtr = num3Ptr;

        if (*num1Ptr <= *num2Ptr){
            *middlePtrPtr = num1Ptr;
            *largePtrPtr = num2Ptr;
        }
        else{
            *middlePtrPtr = num2Ptr;
            *largePtrPtr = num1Ptr;
        }
    }
    return true;
    }
    // TODO Write your code here.

/////////////////////////////////////////////////////
