#!/bin/bash

NAME="Strcpy"
BIN="ft_strcpy"
EXO="work/ft_strcpy.c"
TEST="testing/main.c"
FORBIDDEN='strcpy|strncpy|strlcpy|memcpy|memmove|string.h'

if grep -Eq "(^|[^[:alnum:]_])($FORBIDDEN)[[:space:]]*\(" "$EXO"; then
    echo "Forbidden function used."
    exit 1
fi

echo "Testing $NAME"
echo "Compiling..."
gcc -Wall -Wextra -Werror -o $BIN $TEST $EXO

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

    mapfile -t args < "$i"
    for ((k = 0; k < ${#args[@]}; k++)); do
        args[k]="${args[k]%$'\r'}"
        args[k]="${args[k]//\"/}"
    done

    ./"$BIN" "${args[@]}"
    actual=$?

    if [ "$actual" -eq 0 ]; then
        echo "Test $num succeeded."
    else
        echo "Test $num failed."
        FAIL=1
    fi
done

rm -f $BIN

if [ $FAIL -eq 1 ]; then
    echo "$NAME failed, check your code and try again."
    exit 1
else
    echo "Exercise $NAME completed."
    exit 0
fi