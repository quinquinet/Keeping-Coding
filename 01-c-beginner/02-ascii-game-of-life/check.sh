#!/bin/bash

EXO="work/game-of-life.c"
BIN="game-of-life"

echo "Compiling..."
gcc -Wall -Wextra -Werror -o $BIN $EXO

if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

echo "Compilation succeeded."
echo "Testing..."

FAIL=0
for i in tests/test*; do
    if [ $FAIL -eq 1 ]; then
        echo "Skipping remaining tests due to previous failure."
        break
    fi

    num=$(basename $i | sed 's/test//')
    expected="tests/expected${num}"

    gen=$(head -n 1 "$i")  # Read first line as generation count
    file=$(head -n 2 "$i" | tail -n 1)  # Read second line as input file path
    
    if [ ! -f "$file" ]; then
        actual=$(./$BIN "$gen")
    else
        actual=$(./$BIN "$gen" "$file")
    fi

    exp=$(cat "$expected")
    
    if [ "$actual" == "$exp" ]; then
        echo "Test $num succeeded."
    else
        echo "Test $num failed."
        echo "Expected:"
        echo "$exp"
        echo "Obtained:"
        echo "$actual"
        FAIL=1
    fi
done

rm -f $BIN

if [ $FAIL -eq 1 ]; then
    echo "Tests failed, check your code and try again."
    exit 1
else
    echo "Exercise ASCII Game of Life completed."
    exit 0
fi