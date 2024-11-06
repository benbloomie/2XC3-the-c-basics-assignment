// ADD COMMENTS TO FUNCTIONS
#include <stdlib.h>
#include <stdio.h>

// NEED TO FIND A WAY TO OUTPUT 0
void convertFromDecimal(long input, long base) {
    // base case for when the quotient equals to 0
    if (input == 0) {
        return;
    }

    if (input < 0) {
        printf("-");    // if the input into the function is a negative value, print the minus sign
        input = -1 * input;    // makes the input positive for negative values
    }

    // recursivley calls the function using the quotient of the number divided by the corresponding base
    convertFromDecimal(input / base, base);

    int quotient = input % base;    // calculates the quotient, to be printed

    // handles output for digits 0-9: bases 2 and 8
    if (quotient <= 9) {
        printf("%c", '0' + quotient);  // gets the corresponding ASCII value using the base value of 0
    }
    // handles output for digits 0-9 and letters A-F
    else if (base == 16) {
        printf("%c", 'A' + (quotient - 10)); // gets the corresponding ASCII value using the base value of A
    }
    // handles output for digits 0-9 and letters A-Z
    else if (base == 36) {
        printf("%c", 'A' + (quotient - 10));
    }
}


int analyzeArguments(long base, long start, long finish) {
    long inputNumber = 0;

    if (start == 0 && finish == 0) {
        if (scanf("%ld", &inputNumber) == 1) {
            convertFromDecimal(inputNumber, base);
            puts("");
            analyzeArguments(base, start, finish);
        }
        else if (scanf("%ld", &inputNumber) == EOF) {
            return 0;
        }
        else {
            printf("Error: Non-long-int token encountered. \n");
            return 1;
        }
    }

    else if (finish > start) {
        for (long i = start; i <= finish; i++) {
            convertFromDecimal(i, base);
            puts("");
        }   
    }

    return 0;
}


