#!/bin/bash

# Compile all .c files and create individual object files
gcc -c *.c

# Check if any object file is missing (indicating a compilation failure)
if [ $? -eq 0 ]; then
  echo "Compilation successful. All object files created."
else
  echo "Compilation failed. Check the error messages above."
fi

