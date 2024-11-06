# makefile to handle compilation of all .c files
convert: convert.c convertInput.c checkParameters.c checkParameters.h convertInput.h
	gcc -o convert convert.c convertInput.c checkParameters.c