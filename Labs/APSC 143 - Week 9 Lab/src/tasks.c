#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/***************************************************
Task 1
Make a function to dynamically allocate an appropriately
sized array of doubles from am given string of numbers:
    double* stringToDoubleArray(char string[], int maxLength, int* arraySizePtr)
The string, string, is an arbitrary number of floating
point numbers each separated by a space that is, at most,
maxLength characters long. It should process this string
and return an array containing the numbers as doubles,
with the size of the array created returned via reference
as arraySizePtr.

Your function must be safe for input strings without a
null character.

It should return a NULL pointer if it cannot successfully
process the string for any reason.

Hints:
 -  A new way to handle strings that aren’t null
terminated is to dynamically create a temporary string
of length maxLength + 1, copy into it the contents of
the poorly-terminated string, and null terminate the
temporary string. If you do this, make sure you free
this temporary string at the end of your function.
 
 - The stdlib.h function
    double strtod(char* string, char** endOfNumber)
converts the first double in a given string and returns
by-reference a pointer to the next number in the string,
e.g.,
  char string[] = "1.1 2 1.34";
  char* nextNumberToRead = string;
  double oneNumber = strtod(nextNumberToRead, &nextNumberToRead);
***************************************************/

/***************************************************
Task 2
Make a function to process a given dynamically allocated
array of doubles as a first-in, first-out (FIFO) queue:
    double* fifoQueueAverage(double arrayIn[], int arrayInSize, int numToProcess, int* arrayOutSizePtr, double* averagePtr)
The array of doubles, arrayIn, will be of size, arrayInSize,
and the function will remove the first numToProcess numbers
from the array and return the resulting shorter array,
along with its new array size via reference as arrayOutSize
and the average of the removed numbers via reference as
averagePtr.

It should return a NULL pointer if it cannot successfully
process the given array for any reason.

The given array, arrayIn, should be assumed to no longer
be valid after calling fifoQueueAverage.

Hints:
 - The size of the array returned by calling fifoQueueAverage
should be *arrayOutSize = arrayInSize - numToProcess
***************************************************/

// TODO: Include your necessary libraries here:

/////////////////////////////////////////////////////
// Your Function declarations:

// stringToDoubleArray: Dynamically allocate an array that contains the numbers in the space-separated string. Return the size of the array by reference via arraySizePtr.
double* stringToDoubleArray(char string[], int maxLength, int* arraySizePtr);

// fifoQueueAverage: Remove the first numToProcess elements from the given array of doubles and return the new, shorter array. The size of the new array is returned by reference via arrayOutSize and the average of the processed numbers via averagePtr.
double* fifoQueueAverage(double arrayIn[], int arrayInSize, int numToProcess, int* arrayOutSizePtr, double* averagePtr);

/////////////////////////////////////////////////////



// Main program
int main() {
    // Write whatever you need in this main function to develop and test your code.
    // Gradescope will not use it but instead call and test your function directly.
    int size = 0;
    char str[] = "1.1 2 1.34";
    double* arr = stringToDoubleArray(str, 100, &size);
    for (int i = 0; i < size; i++) {
        printf("%g ", arr[i]);
    }
    printf("\nsize: %d\n", size);
    printf("\n");


    double* newArr;
    int newSize;
    double avg;
    newArr = fifoQueueAverage(arr, 3, 2, &newSize, &avg);
    for (int i = 0; i < newSize; i++) {
        printf("%g ", newArr[i]);
    }
    printf("\n");
    printf("size: %d\n", newSize);
    printf("%f", avg);
    
    free(newArr);
}





/////////////////////////////////////////////////////
// Your function definitions

/*
    Convert the given space-separated string of floating-
    point numbers into an array of doubles. Return a pointer
    to the dynamically allcoated array and its size by
    reference via arraySizePtr. The string will be no
    longer than maxLength, but may not be null terminated.

    An example string:
    char str[] = "1.1 2 1.34"
*/
double* stringToDoubleArray(char string[], int maxLength, int* arraySizePtr)
{
    // TODO: Write your code here
    if (arraySizePtr == NULL || string == NULL || maxLength < 0){
        return NULL;
    }
    
    char* temp = malloc((size_t)maxLength + 1);
    if (temp == NULL){
        return NULL;
    }

    strncpy(temp, string, maxLength);
    temp[maxLength] = '\0';

    int count = 0;
    char* next = temp;

    while (1){
        while (*next == ' '){
            next++;
        }
        if (*next == '\0'){
            break;
        }

        char* end;
        strtod(next, &end);

        if (end == next || (*end != '\0' && *end != ' ')){
            free(temp);
            return NULL;
        }

        count++;
        next = end;

    }

    if (count == 0){
        free(temp);
        return NULL;
    }

    double* array = malloc(count * sizeof(double));

    if(array == NULL){
        free(temp);
        return NULL;
    }
    
    next = temp;

    for (int i = 0;i < count; i++){
        array[i] = strtod(next, &next);
    }

    free(temp);
    *arraySizePtr = count;
    
    return array;
}

/*
    Process the given dynamically-allocated array, arrayIn,
    of doubles as a FIFO (first in, first out) queue.
    That is, remove the first numToProcess numbers from
    the front of the array of size arrayInSize and return
    the resulting array and its new size by reference via
    arrayOutSizePtr. The numbers removed from the queue
    should be processed into their average and returned
    by reference via averagePtr.

    An example array and the result of calling the function:
    double* arr = malloc(...);
    // Init arr to: 1.1, 2, 1.34
    double* newArr;
    int newSize;
    double avg;
    newArra = fifoQueueAverage(arr, 3, 2, &newSize, &avg)
    //newArr = 1.34
    //newSize = 1
    //avg = 1.03
    
*/
double* fifoQueueAverage(double arrayIn[], int arrayInSize, int numToProcess, int* arrayOutSizePtr, double* averagePtr)
{
    // TODO: Write your code here
    if (arrayOutSizePtr == NULL || averagePtr == NULL || arrayIn == NULL || numToProcess <= 0 || numToProcess > arrayInSize){
        return NULL;
    }

    int arrayOutSize = arrayInSize - numToProcess;
    double* arrayOut;
    if (arrayOutSize > 0){
        arrayOut = malloc(arrayOutSize * sizeof(double));
    }
    else{
        arrayOut = malloc(sizeof(double));
    }
    
    if (arrayOut == NULL){
        return NULL;
    }

    double sum = 0.0;
    for (int i = 0; i < numToProcess; i++){
        sum += arrayIn[i];
    }
    for (int i = 0; i < arrayOutSize; i++){
        arrayOut[i] = arrayIn[numToProcess + i];
    }

    free(arrayIn);

    *arrayOutSizePtr = arrayOutSize;
    *averagePtr = sum/numToProcess;
    
    return arrayOut;
}

/////////////////////////////////////////////////////
