#!/bin/bash

echo "Compiling..."
gcc ./src/main.c -o ./build/out -Wall -Wextra -std=c99 -I./include -L./lib \
    -lraylib -lm -ldl -lpthread -lGL -lX11

if [ $? -eq 0 ]; then
    echo "Compilation successful."
    echo "Running the program with argument 20..."
    ./build/out 20
else
    echo "Compilation failed."
fi
