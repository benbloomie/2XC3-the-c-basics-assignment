/* Benjamin Bloomfield, bloomfib, November ##, 2024 
 *
 * This code works as a command-line utility, that validates user input for a number base conversion.
 * It takes command-line arguments to initiate the base and range to aid with conversion from a decimal number.
 * The program accurately handles invalid inputs, and allows users to access a help message if they require.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define minimumBase 2
#define maximumBase 36

/* Name of the function: getHelpMessage
 *
 * Function Description:
 *  Outputs a help message that guides the user on how to use the program properly.
 */
void getHelpMessage() {
    puts("HELP!");
}

/* Name of the function: validateParameters
 *
 * Parameters:
 *  long *base --> pointer to a long integer for the base value, with a default of 16
 *  long *start --> pointer to a long integer for the start value, defaulting to 0
 *  long *finish --> pointer to a long integer for the finish value, defaulting to 0
 * Function Description:
 *  Validates the arguments passeed when calling the program
 *  Sets the base value, and if specified, the start, and finish values.
 * Return Value and Output:
 *  Returns 0 for success, 1 for invalid input.
 *  Prints usage guidance for incorrect inputs, or calls getHelpMessage if '--help' is used.
 */
int validateParameters(int argc, char *argv[], long *base, long *start, long *finish) {
    // bad usage message
    char *badUsage = "Usage: convert [-b BASE] [-r START FINISH]. \n"
                     "  1 < BASE < 37 \n"
                     "  START and FINISH are long integers";
    // assigns default values for base, start and finish
    *base = 16;
    *start = 0;
    *finish = 0;

    // if no arguments are passed, do nothing
    if (argc == 1) {
        return 0;
    }

    // checks if user inputs help message
    if (strcmp(argv[1], "--help") == 0) {
        getHelpMessage();
    }

    for (int i = 1; i < argc; i++) {
        // checks if first character is a '-', to determine if its an option flag 
        if (argv[i][0] == '-') {

            // base flag  
            if (argv[i][1] == 'b') {
                // checks to see if the next argument exists, and increments i by 1 to move to the next argument
                if (argc > ++i) {
                    // ensure that the base value is of the valid range before assigning it
                    if (atol(argv[i]) < minimumBase || atol(argv[i]) > maximumBase) {
                        puts(badUsage);
                        return 1;
                    }
                    else {
                        *base = atol(argv[i]);
                    }
                }
                else {
                    puts(badUsage);
                    return 1;
                }
            }
            
            // range flag
            else if (argv[i][1] == 'r') {
                // checks to see if only two arguments follow
                if (argc > i + 2 && argc < i + 4) {
                    // assigns start and finish to the two proceeding vakyes
                    *start = atol(argv[++i]);
                    *finish = atol(argv[++i]);
                }
                else {
                    puts(badUsage);
                        return 1;
                }
            }

            else {
                puts(badUsage);
                return 1;
            }
        }
    }
    return 0;
}
