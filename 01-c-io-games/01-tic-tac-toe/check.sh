#!/bin/bash

NAME="Tic Tac Toe"
EXO="work/tic_tac_toe.c"
BIN="tic_tac_toe"

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

shopt -s nullglob
mapfile -t tests < <(printf '%s\n' testing/test/* | sort -V)

for i in "${tests[@]}"; do
    if [ $FAIL -eq 1 ]; then
        echo "Skipping remaining tests due to previous failure."
        break
    fi

    num=$(basename $i)
    expected="testing/expected/${num}"

    mapfile -t args < "$i"
    for ((k = 0; k < ${#args[@]}; k++)); do
        args[k]="${args[k]%$'\r'}"
        args[k]="${args[k]//\"/}"
    done

    actual=$(./"$BIN" "${args[@]}")
    exp=$(cat "$expected")
    
    if [ "$actual" == "$exp" ]; then
        echo "Test $num succeeded."
    else
        echo "Test $num failed."
        echo "Expected:"
        echo "$exp" | cat -e
        echo "Obtained:"
        echo "$actual" | cat -e
        FAIL=1
    fi
done

rm -f $BIN

if [ $FAIL -eq 1 ]; then
    echo "Tests failed, check your code and try again."
    exit 1
else
    echo "Exercise $NAME completed."
    exit 0
fi