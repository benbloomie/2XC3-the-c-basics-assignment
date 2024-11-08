/* Benjamin Bloomfield, bloomfib, November 8, 2024 
 *
 * Main program to handle the number conversion.
 * Calls upon methods from other c files to process arguments, inputs, and the conversion itself.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "checkParameters.h"
#include "convertInput.h"

/* Function Name: main
 *
 * Parameters:
 *  int argc --> number of command-line argument
 *  char *argv[] --> an array that holds all the command-line arguments
 * Function Description:
 *  This function initializes base, start, and finish values, by calling the validateParameters function.
 *  It then validates the command-line arguments, and performs number conversions based on the specified user input.
 */

int main(int argc, char *argv[]) {  
    long base, start, finish;

    // if parameters are valid, process and convert numbers
    if (validateParameters(argc, argv, &base, &start, &finish) == 0) {
        analyzeTextInput(base, start, finish);
    }
}





