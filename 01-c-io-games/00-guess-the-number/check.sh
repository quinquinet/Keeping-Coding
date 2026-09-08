#!/bin/bash

EXO="work/guess_the_number.c"
BIN="guess_the_number"

echo "Compiling..."
gcc -Wall -Wextra -Werror -o $BIN $EXO

if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi
echo "Compilation succeeded."

rm -f $BIN

exit 0