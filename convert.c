#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "checkParameters.h"
#include "convertInput.h"
#define minimumBase 2
#define maximumBase 36

int main(int argc, char *argv[]) {  
    long base, start, finish;

    if (validateParameters(argc, argv, &base, &start, &finish) == 0) {
        analyzeArguments(base, start, finish);
        return 0;
    }
    return 1;
}





