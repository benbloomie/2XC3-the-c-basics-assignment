/* Benjamin Bloomfield, bloomfib, November 8, 2024 
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
    puts("convert - Number Base Conversion Utility");
    puts("Version: v1.0.0");
    puts("");
    puts("Convert is a command line utility that allows users to perform decimal");
    puts("conversion to other bases. The user can specify a certain base from 2 to"); 
    puts("36 to convert to binary, octal, hexidecimal, etc. Users can also include");
    puts("an optional range of numbers to convert, or simply enter numbers as input.");
    puts("");
    puts("The defualt base for conversion is 16.");
    puts("If no range is specified, the program will take user input until EOF.");
    puts("If a range is specified, it will convert each number from START to FINISH.");
    puts("");
    puts("Usage:");
    puts("    convert [-b BASE] [-r START FINISH]");
    puts("    convert [--help]");
    puts("");
    puts("Arguments:");
    puts("    -b BASE            The base for number conversion (between 2 and 36).");
    puts("    -r START FINISH    Specifies a range of numbers to be converted.");
    puts("    --help             Displays this help message.");
    puts("");
    puts("Usage Examples:");
    puts("    convert -b 16           Converts user input to base 16.");
    puts("    convert -b 2 -r -3 3    Converts numbers from -3 to 3 into binary.");
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
    char *badUsage = "Usage: convert [-b BASE] [-r START FINISH]\n"
                     "       1 < BASE < 37\n"
                     "       START and FINISH are long integers";
    // assigns default values for base, start and finish
    *base = 16;

    // if no arguments are passed, do nothing
    if (argc == 1) {
        *start = 0;
        *finish = 0;
        return 0;
    }

    // checks if user inputs help message
    if (strcmp(argv[1], "--help") == 0) {
        getHelpMessage();
        exit(0);
    }

    for (int i = 1; i < argc; i++) {
        // checks if first character is a '-', to determine if its an option flag 
        if (argv[i][0] == '-') {
            // checks for unknown flag before processing data
            if (argv[i][1] != 'b' && argv[i][1] != 'r') {
                fprintf(stderr, "%s\n", badUsage);
                exit(1);
            }

            // base flag  
            if (argv[i][1] == 'b') {
                // checks to see if the next argument exists, and increments i by 1 to move to the next argument
                if (argc > ++i) {
                    // checks if the base value is outside of excepted values
                    if (atol(argv[i]) < minimumBase || atol(argv[i]) > maximumBase) {
                        fprintf(stderr, "%s\n", badUsage);
                        exit(1);
                    }
                    // if the value is accepted, assign all values
                    else {
                        *base = atol(argv[i]);
                        *start = 0;
                        *finish = 0;
                    }
                }
                else {
                    fprintf(stderr, "%s\n", badUsage);
                    exit(1);
                }
            }
            
            // range flag
            else if (argv[i][1] == 'r') {
                // checks to see if only two arguments follow
                if (argc > i + 2 && argc < i + 4) {
                    // assigns start and finish to the two proceeding values
                    *start = atol(argv[++i]);
                    *finish = atol(argv[++i]);
                    // no output if start and finish values are the same
                    if (*start == *finish) {
                        exit(0);
                    }
                }
                else {
                    fprintf(stderr, "%s\n", badUsage);
                    exit(1);
                }
            }
        }
        // checks for extra arguments beyond the expected count
        if ((argc > 3 && argv[1][1] == 'b')) { 
            // checks when the range flag is provided
            if (argc != 6 && argv[3][1] == 'r') {
                fprintf(stderr, "%s\n", badUsage);
                exit(1);  
            }
            // ensures the range flag is not provided for other case
            else if (argv[3][1] != 'r') {
                fprintf(stderr, "%s\n", badUsage);
                exit(1);
            } 
        }

    }
    return 0;
}
