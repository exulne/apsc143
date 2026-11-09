#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ROWS 5
#define COLUMNS 8
#define LENGTH 100

// function definitions
bool linspace(double firstValue, double lastValue, int numValues, double outputArray[]);
bool minutesToString(double timeInMinutes, char outputString[LENGTH]);
bool numericalPaceTable(double distances[COLUMNS], double paces[ROWS], double outputArray[ROWS][COLUMNS]);
bool stringPaceTable(double distances[COLUMNS], double paces[ROWS], char outputArray[ROWS][COLUMNS][LENGTH]);


int main(void){
    // main was removed at one point during debugging and wasn't added back
    // this is human written code
};

// calculates an array of size numValues going from firstValue to lastValue, with evenly spaced 
bool linspace(double firstValue, double lastValue, int numValues, double outputArray[]){
    // check null pointer, and also that there are at least 2 values
    if (numValues < 2 || outputArray == NULL){
        return false;
    }

    // calculate spacing, and then multiply by current index to find difference between value at i and firstValue    
    for (int i = 0; i < numValues; i++){
        outputArray[i] = firstValue + i * ((lastValue - firstValue) / (numValues - 1));
    }

    // final value always assigned to the given lastValue to avoid errors
    outputArray[numValues - 1] = lastValue;

    return true;
}

// formats timeInMinutes to HH:MM:SS using string formatting 
bool minutesToString(double timeInMinutes, char outputString[LENGTH]){
    // check for null pointer, and if not null check to make sure time given does not exceed the max hours of 99
    if (outputString == NULL){
        return false;
    }
    else if (timeInMinutes >= 6000){
        outputString[0] = '\0';
        return false;
    }
    
    // convert minutes to an integer value in seconds
    int totalSeconds = (int)(timeInMinutes * 60);

    // calculate the hours, minutes and seconds from the total elapsed time
    int hours = totalSeconds/3600;
    int minutes = (totalSeconds % 3600) / 60;
    int seconds = totalSeconds % 60;

    // format using string formatting and store values in outputString
    snprintf(outputString, LENGTH, "%02d:%02d:%02d", hours, minutes, seconds);

    return true;
}


bool numericalPaceTable(double distances[COLUMNS], double paces[ROWS], double outputArray[ROWS][COLUMNS]){
    // validate all arrays
    if (distances == NULL || paces == NULL || outputArray == NULL){
        return false;
    }
    
    // ensure no negative pace and distance values
    for (int i = 0; i < ROWS; i++){
        if (paces[i] < 0) {
            return false;
        }
    }
    for (int j = 0; j < COLUMNS; j++){
        if (distances[j] < 0){
            return false;
        }
    }

    // for every pace and distance, append to that index in outputArray the time found by taking paces * distances
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLUMNS; j++){
            outputArray[i][j] = paces[i] * distances[j];
        }
    }

    return true;
}

bool stringPaceTable(double distances[COLUMNS], double paces[ROWS], char outputArray[ROWS][COLUMNS][LENGTH]){
    // initialise table
    double minTable[ROWS][COLUMNS];

    // ensure numericalPaceTable returns a value, and that no error with arrays
    if (!numericalPaceTable(distances, paces, minTable) || outputArray == NULL || distances == NULL || paces == NULL){
        return false;
    }
 
    // loop through numerical pace table and convert to string. 
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLUMNS; j++){
            // convert to string, if it fails return false
            if (!minutesToString(minTable[i][j], outputArray[i][j])) {
                return false;
            }       
        }
    }

    return true;
}

