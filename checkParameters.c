#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define minimumBase 2
#define maximumBase 36

void getHelpMessage() {
    puts("HELP!");
}

int validateParameters(int argc, char *argv[], long *base, long *start, long *finish) {
    // bad usage message
    char *badUsage = "Usage: convert [-b BASE] [-r START FINISH]. \n"
                     "  1 < BASE < 37 \n"
                     "  START and FINISH are long integers";
    // assigns base values for base, start and finish
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

            // base value reading 
            if (argv[i][1] == 'b') {
                // checks to see if the next argument exists, incrementing i by 1
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
            
            // range value reading
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
