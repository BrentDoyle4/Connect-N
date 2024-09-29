#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "input_val.h"

/*
Gets the number of arguments needed and the number of arguments read to check if the format is valid.
@numArgsNeeded: the number of format placeholders that needed to have been read in the last scanf
@numArgsRead: the actual number of placeholders that were read from scanf, ie its return value
@returns: true if the input is correctly formatted and false otherwise
*/
bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
    bool formatIsGood = numArgsRead == numArgsNeed;
    char character;
    do{
        scanf("%c", &character); 
		if(!isspace(character)){ 
			formatIsGood = false;
		}
	}while(character != '\n');
    return formatIsGood;
}

/*
Get an integer from the user, and ask again if one is not entered
@prompt: enter statement to ask for an integer
@returns: a valid integer
*/
int getValidInt(const char* prompt){
    int num;
    const int numArgsNeeded = 1;
    int numArgsRead;
    do{
        printf("%s", prompt);
        numArgsRead = scanf(" %d", &num);
    }while(!isValidFormat(numArgsRead, numArgsNeeded));
    return num;
}

/*
Get an integer in an inclusive range from the user, and ask again if one is not entered
@lowerBound: an inclusive lower bound 
@upperBound: an inclusive upper bound
@prompt: enter statement to ask for an integer
@returns: a valid integer in an inclusive range
*/
int getValidIntInRange(int lowerBound, int upperBound, const char* prompt){
    int num;
    do{
        num = getValidInt(prompt);
    }while(!(inbetween(num, lowerBound, upperBound)));
    return num;
}

/*
Gets the integer value to check, an inclusive lower bound, and an inclusive upper bound, 
to check if the integer value is inclusively in between the lower and upper bound.
@val: the integer value to check
@lowerBound: an inclusive lower bound 
@upperBound: an inclusive upper bound
@returns: true if the integer is inclusively in between both the lower and upper bounds
*/
bool inbetween(int val, int lowerBound, int upperBound){
    return val >= lowerBound && val <= upperBound;
}