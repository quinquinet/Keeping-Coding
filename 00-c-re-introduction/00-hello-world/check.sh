#!/bin/bash

NAME="Hello World"
EXO="work/hello-world.c"
BIN="hello-world"

echo "Testing $NAME"
echo "Compiling..."
gcc -Wall -Wextra -Werror -o $BIN $EXO

if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

echo "Compilation succeeded."
echo "Testing..."

FAIL=0

expected="Hello World !"
actual=$(./$BIN)

if [ "$actual" == "$expected" ]; then
    echo "Test succeeded."
else
    echo "Test failed."
    echo "Expected:"
    echo "$expected"
    echo "Obtained:"
    echo "$actual"
    FAIL=1
fi

rm -f $BIN

if [ $FAIL -eq 1 ]; then
    echo "$NAME failed, check your code and try again."
    exit 1
else
    echo "Exercise $NAME completed."
    exit 0
fi