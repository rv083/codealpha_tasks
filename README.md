# codealpha_tasks
# Number Guessing Game

<hr>

## Introduction

The Number Guessing Game is a console-based game where the player tries to guess a randomly generated number within a specified range. The game provides three levels of difficulty: Easy, Medium, and Hard. The player is given a certain number of attempts based on the selected difficulty level to guess the secret number correctly. If the player guesses the number within the allowed attempts, they win; otherwise, they lose.

<hr>

## Features

- **Three levels of difficulty:**
  - **Easy:** Guess a number between 1 and 20 with 10 attempts.
  <br>
  - **Medium:** Guess a number between 1 and 50 with 8 attempts.
  <br>
  - **Hard:** Guess a number between 1 and 80 with 5 attempts.
  <br>
- Input validation with feedback sounds for invalid inputs.
<br>
- Loading animation before starting the game.
<br>
- Console colors for enhanced user experience.
<br>
- Option to play again after each game.

<hr>

## Requirements

- Windows operating system (due to the usage of `windows.h` for system commands and sound functions).
<br>
- C++ compiler (such as g++ or MSVC).

<hr>

## How to Run

1. Clone the repository:
    ```bash
    git clone https://github.com/rv083/number-guessing-game.git
    ```
  

    <br>
3. Compile the program:
    ```bash
    g++ -o game game.cpp
    ```
    <br>
4. Run the executable:
    ```bash
    game.exe
    ```

<hr>

## Code Overview

### Functions

- `playBeep(const string& sound)`
  <br>
  Plays different system sounds based on the input string.
  <br>
  `"invalid"` plays an error sound.
  <br>
  `"success"` plays an information sound.
  <br><br>
- `game(int num, int chances)`
  <br>
  The main game function that handles the guessing logic.
  <br>
  Takes the maximum number (`num`) and the number of attempts (`chances`) as parameters.
  <br>
  Validates user input and provides feedback based on the guessed number.
  <br>
  Offers the option to play again if the user wins or loses.
  <br><br>
- `printWelcomeMessage()`
  <br>
  Displays a welcome message with ASCII art and console colors.
  <br><br>
- `loadingAnimation()`
  <br>
  Displays a loading animation before the start of the game.
  <br>

### Main Function

- Displays the welcome message and waits for the user to press Enter to start the game.
<br>
- Prompts the user to select a difficulty level and validates the input.
<br>
- Calls the `game()` function with parameters based on the selected difficulty level.
<br>
- Loops indefinitely to allow the user to play multiple times.

