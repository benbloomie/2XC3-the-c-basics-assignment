#!/bin/bash
#
# A simple framework for regression testing the convert (ctest) script
# Returns the number of failed test cases.
# The test function used in the script was taken the from week06 directory.
#   Sam Scott, McMaster University, 2024.
#
# Format of a test:
#     test 'command' 'input file name' 'expected output file name' 'expected std error file name'
#
# CAUTION: Uses temporary files named test_err.txt and test_out.txt
# 
# Benjamin Bloomfield, McMaster University, November ##, 2024

declare -i tc=0
declare -i fails=0

############################################
# Run a single test. Runs a given command 
# to check the return value, stdout, and stderr
#
# GLOBALS: tc, fails
# PARAMS: $1 = command
#         $2 = input file name
#         $3 = expected std output file name
#         $4 = expected std error file name
#
# Assumes return value should be 0 if the
# std error file is empty. Otherwise it 
# should be 1.
#
# OUTPUTS: An pass/fail report showing the
# difference between expected and actual
# output on a failure (diff command)
############################################
test() {
    tc=tc+1

    local COMMAND=$1
    local INP=$2
    local EX_OUT=$3
    local EX_ERR=$4 

    EX_RET=1
    if [[ $(cat $EX_ERR) = "" ]]; then
        EX_RET=0
    fi
    $COMMAND < $INP > test_out.txt 2> test_err.txt
    RET=$?
    if [[ $RET != $EX_RET ]]; then
        echo "TC $tc Failed"
        echo "Returned $RET"
        echo "-----------"
        fails=$fails+1
        return
    fi
    DIFF=$(diff test_out.txt $EX_OUT)
    if [[ $DIFF != '' ]]; then
        echo "TC $tc Failed Standard Output"
        echo "$DIFF"
        echo "-----------"
        fails=$fails+1
        return
    fi
    DIFF=$(diff test_err.txt $EX_ERR)
    if [[ $DIFF != '' ]]; then
        echo "TC $tc Failed Standard Error"
        echo "$DIFF"
        echo "-----------"
        fails=$fails+1
        return
    fi

    echo "TC $tc Passed"
}

# Test Case 1: Basic Conversion 
test './convert -b 2' 'inp1.txt' 'ex_out1.txt' 'empty.txt'

# Test Case 2: Base 16 Conversion 
test './convert -b 16' 'inp2.txt' 'ex_out2.txt' 'empty.txt'

# Test Case 3: Base 36 Conversion
test './convert -b 36' 'inp3.txt' 'ex_out3.txt' 'empty.txt'

# Test Case 4: Range Conversion 
test './convert -b 2 -r 0 10' 'empty.txt' 'ex_out4.txt' 'empty.txt'

# Test Case 5: Invalid Flag
test './convert -a' 'empty.txt' 'empty.txt' 'usage.txt'

# Test Case 6: Invalid Base
test './convert -b 37' 'empty.txt' 'empty.txt' 'usage.txt'

# Test Case 7: Invalid Base 
test './convert -b 1' 'empty.txt' 'empty.txt' 'usage.txt'

# Test Case 8: Invalid Input (Non-Integer)
test './convert -b 10' 'inp8.txt' 'empty.txt' 'usage2.txt'

# Test Case 9: Conversion for Range with Negative Start
test './convert -b 2 -r -3 3' 'empty.txt' 'ex_out9.txt' 'empty.txt'

# Test Case 10: No Arguments
test './convert' 'inp10.txt' 'ex_out10.txt' 'empty.txt'

# Test Case 11: Larger Start Than End
test './convert -r 10 0' 'empty.txt' 'empty.txt' 'empty.txt'

# Test Case 12: Too Many Range Values
test './convert -r 1 2 3' 'empty.txt' 'empty.txt' 'usage.txt'

# Return code
exit $fails
