# M01 - Exercise 00 - Guess the Number - ⭐

**⚠ This exercise does not comport a check.sh and so it can't be tested and validate. This is not a reason to skip it. The testing is in progress.**

## Description

This is a simple number guessing game implemented in C. The program generates a random number between 1 and 100, and the player has to guess the number. The program provides feedback on whether the guess is too high, too low, or correct.

## Instructions

Allowed functions: *All functions of the std libraries*

Create a program in a file named `guess_the_number.c` that takes none argument. This program is an implementation of a Guess the Number game, a 1 player game where the player must guess a random number generated between 1 and 100 in the least number of attempt. At each the program ask `Guess the number : `, then the player must in put a number between `1` and `100`, if the input is not valid, the program should display `Please enter a valid integer` and then ask again `Guess the number : ` on a new line.

If the guess is lower or greater than the number the program should display `Number to find is lower/greater than <guess>` and then ask again `Guess the number : ` on a new line.
When the number is found the program should display `Congratulation ! You find the number <number> in <attempt> attempts` and finish.

Here is an exemple of a game :
```
Guess the number : 500
Please enter a valid integer
Guess the number : 50
Number to find is lower than 50
Guess the number : 25
Number to find is lower than 25
Guess the number : 12
Number to find is greater than 12
Guess the number : 19
Number to find is lower than 19
Guess the number : 15
Congratulation ! You find the number 15 in 5 attempts
```

Only valid guess counts as attempts.

File must compile using `gcc -Wall -Wextra -Werror` to pass the validation.

**Make sure that you have free every allocated memory and close every opened file before the program ends.**

## Help

Use 

### Solution

The given solution may contain mistakes, please report any issues you find. You can find the solution in the `solution` folder.