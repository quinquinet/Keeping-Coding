#!/bin/bash

NAME="ASCII Game of Life"
EXO="work/game-of-life.c"
BIN="game-of-life"

printf "Testing $NAME\n\n"
printf "Compiling...\n"
gcc -Wall -Wextra -Werror -o $BIN $EXO

if [ $? -ne 0 ]; then
    printf "Compilation failed.\n"
    exit 1
fi

printf "Compilation succeeded.\n\n"
printf "Testing...\n"

FAIL=0

shopt -s nullglob
mapfile -t tests < <(printf '%s\n' testing/test/* | sort -V)

for i in "${tests[@]}"; do
    if [ $FAIL -eq 1 ]; then
        printf "Skipping remaining tests due to previous failure.\n\n"
        break
    fi

    num=$(basename $i)
    expected="testing/expected/${num}"

    mapfile -t args < "$i"

    actual=$(./"$BIN" "${args[@]}")

    exp=$(cat "$expected")
    
    if [ "$actual" == "$exp" ]; then
        printf "Test $num succeeded.\n"
    else
        printf "Test $num failed.\n\n"
        printf "Expected:\n"
        printf "$exp\n\n"
        printf "Obtained:\n"
        printf "$actual\n\n"
        FAIL=1
    fi
done

rm -f $BIN

if [ $FAIL -eq 1 ]; then
    printf "Tests failed, check your code and try again."
    exit 1
else
    printf "\nExercise $NAME completed."
    exit 0
fi