# PlayFusion-GPT

A set of C++ solutions to the PlayFusion Graduate Programming Test.

## Part A

Part A consists of an implemented Point2D class that has implementations for each question.

## Part B

Part B consists of a class of static methods. The main for this demonstrates the implemented tournament allocation algorithm.

The output of the file is a csv, with each row representing a matchup between to players (each player has an integer ID). For tournaments with odd numbers of players, the player could be pitted against a player with an ID of `-1`. This represents a bye round for that player.


## Building the Project

A seperate makefile exists for part A and part B. For part a, navigate to the `part_a` directory and for part B navigate to the `part_b` directory.

When you have navigated in the terminal to the desired directory, run `make` to build the project.

Part A will be built into an executable called `graphics` and part B, `lightseekers`. Running either of these will result in console logs demonstrating each aspect of the respective implementation.

### Note
The version of `make` used for this project is:
```
GNU Make 4.1
Built for x86_64-pc-linux-gnu
```
The project uses `c++11`, as flagged in the makefile.


