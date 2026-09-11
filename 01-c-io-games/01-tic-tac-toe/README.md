# M01 - Exercise 01 - Tic Tac Toe - ⭐⭐

**⚠ This exercise does not comport a check.sh and so it can't be tested and validate. This is not a reason to skip it. The testing is in progress.**

## Description

Implement a C version of the [Tic Tac Toe game](https://en.wikipedia.org/wiki/Tic-tac-toe) for 2 players. The game should be played in the console, and the players should take turns to place their marks (X or O) on a 3x3 grid. The game should check for a win or a draw after each move and display the result accordingly.

## Instructions

Create a program in a file named `tic_tac_toe.c` that implements a 2 players Tic Tac Toe game (meaning that the game is played by 2 human players, so you don't need to implement any AI).
The game should start with player 1 (X) and then player 2 (O) and so on. At each turn, the program should ask the current player his input as such `Player X, your move : ` or `Player O, your move : ` then wait for player input.
The input should be given as follow : `row*10+column` where both *row* and *column* are integers between 1 and 3 (inclusive). If the input is invalid (not in the range or an other character than a digit), the program should display on a new line `Invalid input, try again : ` until the player gives valid inputs.
If the player tries to play on a cell that is already taken, the program should display on a new line `Cell already taken, try again : ` until the player gives valid inputs.
After each valid move, the program should display the current state of the grid as exemples (see below), check if the player has won and display `Player X won !` or `Player O won !` and then terminate if so, and if not, go to the next turn.
```
 |X|O
-+-+-
 |O|X
-+-+-
 | | 
```
If the grid is full and no player has won, the program should display on a new line `Draw !` and then terminate.

Here is example of a game session when finished :
```
Player X, your move : 11
X| | 
-+-+-
 | | 
-+-+-
 | | 
Player O, your move : 12
X|O| 
-+-+-
 | | 
-+-+-
 | | 
Player X, your move : 12
Cell already taken, try again : 22
X|O| 
-+-+-
 |X| 
-+-+-
 | | 
Player O, your move : 1
Invalid input, try again : 52
Invalid input, try again : 131
Invalid input, try again : tic tac
Invalid input, try again : 13
X|O|O
-+-+-
 |X| 
-+-+-
 | | 
Player X, your move : 33
X|O|O
-+-+-
 |X| 
-+-+-
 | |X
Player X won !
```

**Make sure that you have free every allocated memory and close every opened file before the program ends.**

### Solution

The given solution may contain mistakes, please report any issues you find. You can find the solution in the `solution` folder.