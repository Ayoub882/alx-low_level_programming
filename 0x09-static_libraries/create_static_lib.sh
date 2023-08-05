#!/bin/bash

# Compile all .c files into object files, except test_functions.c
gcc -Wall -pedantic -Werror -Wextra -c $(ls *.c | grep -v "test_functions.c")

# Create the static library liball.a
ar -rc liball.a *.o

# Update the table of contents in the library
ranlib liball.a

# Optionally, you can also remove the test_functions executable if it's present
# rm -f test_functions

