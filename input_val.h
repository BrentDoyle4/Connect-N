#ifndef INPUT_VAL_H
#define INPUT_VAL_H

    bool isValidFormat(const int numArgsRead, const int numArgsNeed);
    int getValidInt(const char* prompt);
    int getValidIntInRange(int lowerBound, int upperBound, const char* prompt);
    bool inbetween(int val, int lowerBound, int upperBound);

#endif