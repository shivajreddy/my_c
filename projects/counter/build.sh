#!/bin/bash

echo "Compiling..."
gcc ./src/main.c -o ./build/out -Wall -Wextra -std=c99 -I./include -L./lib \ -lraylib -lm -ldl -lpthread -lGL -lX11
gcc ./src/main.c -o ./build/out -Wall -Wextra -std=c99 \
    -I./include -I./lib_linux/include \
    -L./lib_linux -lraylib -lm -ldl -lpthread -lGL -lX11

if [ $? -eq 0 ]; then
    echo "Compilation successful."

    if [ -z "$3" ]; then
        if [ -z "$2" ]; then
            if [ -z "$1" ]; then
                echo "Running with default timer..."
                ./build/out
            else
                echo "Running with seconds: $1"
                ./build/out "$1"
            fi
        else
            echo "Running with minutes: $1, seconds: $2"
            ./build/out "$1" "$2"
        fi
    else
        echo "Running with hours: $1, minutes: $2, seconds: $3"
        ./build/out "$1" "$2" "$3"
    fi
else
    echo "Compilation failed."
fi
