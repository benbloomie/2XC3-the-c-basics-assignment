/* Benjamin Bloomfield, bloomfib, November 8, 2024 
 *
 * This program handles the conversion for the decimal numbers the user specifies for conversion.
 * It supports bases from 2 to 36, allowing output in formats of binary, octal, hexidecimal and hexatridecimal.
 * Users can specify a base and an optional range of numbers to convert, or enter numbers interactively.
 *      For a specified range, it will convert each number in the range.
 *      For an unspecified range, it will convert any number the user inputs.
 */

#include <stdlib.h>
#include <stdio.h>

/* Function Name: convertFromDecimal
 *
 * Parameters:
 *  long input --> the decimal number to convert
 *  long checkInputZero --> the number that the user inputs to be converted
 * Function Description:
 *  Recursively converts a decimal number to a specified base value, and outputs the result number by numbers.
 *  Takes a decimal number as input, and can convert bases up to 36
 */


// NEED TO FIND A WAY TO OUTPUT 0
void convertFromDecimal(long input, long base, long checkInputZero) {

    // base case for when the quotient equals to 0
    if (input == 0) {
        // if the numbered inputted by the user is 0, output that number
        if (checkInputZero == 0) {  
            printf("0");
        }
        return;
    }

    if (input < 0) {
        printf("-");    // if the input into the function is a negative value, print the minus sign
        input = -1 * input;    // converts to a positive value for conversion
    }

    // recursivley calls the function using the quotient of the number divided by the corresponding base
    convertFromDecimal(input / base, base, input);

    int quotient = input % base;    // calculates the quotient, to be printed

    // handles output for digits 0-9: bases 2 and 8
    if (quotient <= 9) {
        printf("%c", '0' + quotient);  // gets the corresponding ASCII value using the base value of 0
    }
    // handles output for digits 0-9 and letters A-F
    else if (base == 16) {
        printf("%c", 'A' + (quotient - 10)); // converts integer to corresponding ASCII character using the base value of A
    }
    // handles output for digits 0-9 and letters A-Z
    else if (base == 36) {
        printf("%c", 'A' + (quotient - 10));
    }
}

/* Function Name: analyzeTextInput
 *
 * Parameters:
 *  long base, start, finish --> values determined from the checkParameters.c program 
 * Function Description:
 *  Analyzes user-provided arguments for base and range, to determine how the number should be converted.
 *  For no specified range, the program will take user input to perform the conversion, and continue until EOF.
 *  For a specified range, the program will convert each number in the range.
 * Returns:
 *  - 0 on successful execution or when the user inputs EOF.
 *  - 1 if an error occurs (e.g., non-integer input).
 */
int analyzeTextInput(long base, long start, long finish) {
    long inputNumber = 0;

    // if start and finish are not specified, read and process user input
    if (start == 0 && finish == 0) {
        if (scanf("%ld", &inputNumber) == 1) {
            convertFromDecimal(inputNumber, base, inputNumber);  // calls the convertFromDecimal function to convert the inputted value
            printf("\n");
            analyzeTextInput(base, start, finish);  // recursively calls the function to read the next input
        }
        // exit function and program when user enters CTRL+D
        else if (scanf("%ld", &inputNumber) == EOF) {
            return 0;
        }
        else {
            fprintf(stderr, "Error: Non-long-int token encountered.\n");    // error output for invalid input.
            exit(1);
        }
    }

    // if a valid range is provided, convert and print numbers in the range from start to finish
    else if (finish > start) {
        for (long i = start; i <= finish; i++) {
            convertFromDecimal(i, base, i);
            printf("\n");
        }   
    }
    return 0;
}


