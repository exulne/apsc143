/***************************************************
TASK 1

Make functions to iterate through and/or create integer arrays:
    bool sumArray(int inputArray[], int arrayLength, int* sumPtr);
         Iterates through an array of given length to sum the value of the entries.
         Returns the sum via reference and true if the sum has been calculated, false otherwise.

    bool countZerosInArray(int inputArray[], int arrayLength, int* numZerosPtr);
         Iterates through an array of given length to count the number of zeros in it.
         Returns the number via reference and true if the count has been calculated, false otherwise.

    bool findMinAndMaxInArray(int inputArray[], int arrayLength, int* minValuePtr, int* maxValuePtr);
         Iterates through the array of given length to find the smallest and largest numbers in it.
         Returns the minimum and maximum via reference and true if the numbers have been found, false otherwise.

     bool createPrimeArray(int firstNum, int lastNum, int* numPrimesPtr, int outputArray[], int arrayLength);
        Create an array containing all the prime numbers between firstNum and lastNum (inclusive).
        Returns the list of prime numbers and how many prime numbers were found via reference and true if the numbers have been found, false otherwise.
        Remember to confirm that the given array is appropriately sized for the number of values you are returning.

Your functions MUST assume that the length of the given array is the value given in the variable "arrayLength" and not the global value in "LENGTH".

Hints:
- Arrays are always passed to a function as a pointer, i.e., they are passed by reference, so make sure to
    (1) check them appropriately and
    (2) remember that changes to the array in a function will also change it in main.

Gradescope will test your functions only, not your main function.
****************************************************/

// C library to perform Input/Output operations
#include <stdio.h>
// C library for the boolean variable type
#include <stdbool.h>

/////////////////////////////////////////////////////
// Your Function declarations:

// sumArray: Sum the values stored in an array of specified length.
bool sumArray(int inputArray[], int arrayLength, int* sumPtr);

// countZerosInArray: Count the number of zeros in a given integer array of specified length
bool countZerosInArray(int inputArray[], int arrayLength, int* numZerosPtr);

// findMinAndMaxInArray: Find the smallest and largest numbers in a given integer array of specified length
bool findMinAndMaxInArray(int inputArray[], int arrayLength, int* minValuePtr, int* maxValuePtr);

// createPrimeArray: Create an array of the prime numbers between firstNum and lastNum, inclusive and store in the array of specified length.
bool createPrimeArray(int firstNum, int lastNum, int* numPrimesPtr, int outputArray[], int arrayLength);
/////////////////////////////////////////////////////

// Main program
int main() {
    // TODO: Write your code here to test your functions.
    int a[] = {0, 0, 1, 2, 3};
    int sum = 0;
    int numZeros = 0;
    int numPrimes = 0;
    int LENGTH = 10;
    int outputPrimes[LENGTH];


    sumArray(a, sizeof(a)/sizeof(a[0]), &sum);
    countZerosInArray(a, sizeof(a)/sizeof(a[0]), &numZeros);
    createPrimeArray(1, 5, &numPrimes, outputPrimes, LENGTH);

    // printf("%d", sum);
    // printf("%d", numZeros);

    for (int i = 0; i < numPrimes; i++){
        printf("%d", outputPrimes[i]);
    }
}

/////////////////////////////////////////////////////
// Your function definitions

/*
    Iterate through the given array and sum the values
    of its elements.
    Arguments:
        inputArray - An array of at least size arrayLength
        arrayLength - The size of inputArray
        sum - A pass-by-reference to return the sum of the array. Initial value is unknown.
    Return:
        True if the summation was completed, false otherwise
        The sum of the array via pass-by-reference
*/
bool sumArray(int inputArray[], int arrayLength, int* sumPtr) {
    if (inputArray == NULL || sumPtr == NULL || arrayLength < 0) {
        return false;
    }

    int localSum = 0;
    for (int i = 0; i < arrayLength; i++){
        localSum += inputArray[i];
    }

    *sumPtr = localSum;
    return true;
    // TODO: Write your code here.
}

/*
    Iterate through the given array and count the number of
    zeros in it.
    Arguments:
        inputArray - An array of at least size arrayLength
        arrayLength - The size of inputArray
        numZeros - A pass-by-reference to return the number of zeros in the array. Initial value is unknown.
    Return:
        True if the count was completed, false otherwise
        The number of zeros of the array via pass-by-reference
*/
bool countZerosInArray(int inputArray[], int arrayLength, int* numZerosPtr) {
    if (inputArray == NULL || numZerosPtr == NULL || arrayLength < 0) {
        return false;
    }

    int zeroes = 0;
    for (int i = 0; i < arrayLength; i++){
        if (inputArray[i] == 0){
            zeroes += 1;
        }
    }
    *numZerosPtr = zeroes;

    return true;


    // TODO: Write your code here.
}

/*
    Iterate through the given array and find the smallest
    and largest value in it.
    Arguments:
        inputArray - An array of at least size arrayLength
        arrayLength - The size of inputArray
        minValue - A pass-by-reference to return the smallest number in the array. Initial value is unknown.
        maxValue - A pass-by-reference to return the largest number in the array. Initial value is unknown.
    Return:
        True if the search was completed, false otherwise
        The smallest number in the array via pass-by-reference
        The largest number in the array via pass-by-reference

*/
bool findMinAndMaxInArray(int inputArray[], int arrayLength, int* minValuePtr, int* maxValuePtr) {
    // TODO: Write your code here.
    if (inputArray == NULL || arrayLength < 0 || minValuePtr == NULL || maxValuePtr == NULL){
        return false;
    }

    int smallest = inputArray[0];
    int largest = inputArray[0];

    for (int i = 0; i < arrayLength; i++){
        int current = inputArray[i];

        if (current > largest){
            largest = current;
        }
        else if (current < smallest){
            smallest = current;
        }
    }
    *minValuePtr = smallest;
    *maxValuePtr = largest;

    return true;
}

/*
    Create an array of the prime numbers between firstNum and lastNum, inclusive.
    Arguments:
        firstNum - The first possible prime number
        lastNum - The last possible prime number
        numPrimes - A pass-by-reference to return how many prime numbers were stored in the array. Initial value is unknown.
        outputArray - An array of at least size arrayLength. Initial element values are unknown
        arrayLength - The size of inputArray
    Return:
        True if the count was completed, false otherwise
        The number of primes stored in the array via pass-by-reference
        An array of prime numbers via pass-by-reference

*/
bool createPrimeArray(int firstNum, int lastNum, int* numPrimesPtr, int outputArray[], int arrayLength) {
    // TODO: Write your code here.
    if (numPrimesPtr == NULL || firstNum > lastNum || arrayLength < 0){
        return false;
    }

    *numPrimesPtr = 0;

    for (int num = firstNum; num <= lastNum; num++){
        bool prime = true;

        if (num < 2){
            prime = false;
        }
        else {
            for (int i = 2;i * i <= num;i++){
                if (num % i == 0) {
                    prime = false;
                    break;
                }
            }
        }

        if (prime){
            outputArray[*numPrimesPtr] = num;
            (*numPrimesPtr)++;
        }
    }

    return true;
}
/////////////////////////////////////////////////////
