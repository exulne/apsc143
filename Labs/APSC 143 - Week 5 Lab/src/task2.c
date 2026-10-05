#include <stdio.h>

/////////////////////////////////////////////////////
// Your Function declarations:

// sequence: Calculate the next number in the sequence
int sequence(int n);

// sequenceLength: Calculate the length of the sequence to 1
int sequenceLength(int n);

// maxSequenceLength: Calculate the longest sequence
// length in the given range.
int maxSequenceLength(int first, int last);

/////////////////////////////////////////////////////

int main()
{
    // TODO: Write code to test your functions here.

    return 0;
}

/////////////////////////////////////////////////////
// Your function definitions

/*
    Returns the next number in the sequence, given the current number n..
    If the number is divisible by 2, then the next number is n / 2 
    If not, then the next number is 3 * n + 1
    Arguments
        n - the current number in the sequence
    Return
        The next number in the sequence
*/
int sequence(int n)
{
    // TODO: Write your code here.
    if (n % 2 == 0){
        return (n/2);
    }
    else{
        return (3 * n + 1);
    }
}

/*
    Calculates the length of the sequence from the given number to 1.
    Arguments
        n - the starting number in the sequence
    Return
        The length (number of numbers) in the sequence between n and 1.
*/
int sequenceLength(int n)
{
    // TODO: Write your code here.

    int length = 0;

    while (n != 1){
        n = sequence(n);
        length++;
    };
    return ++length;

}

/*
    Calculates the length of the longest sequence within the range [first, last]
    Arguments
        first - the first number to calculate the sequence length of
        last - the last number to calculate the sequence length of
    Return
        The length of the longest sequence starting from a number between the numbers first and last.
*/
int maxSequenceLength(int first, int last)
{
    int longest = 0;

    for (int i = first; i <= last; i++){
        if (sequenceLength(i) > longest){
            longest = sequenceLength(i);
        }
    }

    return longest;
    // TODO: Write your code here.
}

/////////////////////////////////////////////////////
