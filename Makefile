# Benjamin Bloomfield, bloomfib, November 9, 2024 

# makefile to handle compilation of all .c files; default
convert: convert.c convertInput.c checkParameters.c checkParameters.h convertInput.h
	gcc -o convert convert.c convertInput.c checkParameters.c

# if the argument 'coverage' is entered, excecute these lines of code
ctest: convert.c convertInput.c checkParameters.c checkParameters.h convertInput.h
	gcc -o convert --coverage convert.c convertInput.c checkParameters.c