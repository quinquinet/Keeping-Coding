#!/bin/bash
set -e

echo "Compiling..."
gcc -Wall -Wextra -Werror -o guess-the-number work/guess-the-number.c

if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

echo "Compilation succeeded."

rm -f guess-the-number1

exit 0