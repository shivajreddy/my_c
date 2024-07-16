#!/bin/bash

# clear

# Compile the code
clang -o output main.c

# Check if compilation was successful
if [ $? -eq 0 ]; then
  # Run the compiled program
  ./output
else
  echo "Compilation failed."
fi
