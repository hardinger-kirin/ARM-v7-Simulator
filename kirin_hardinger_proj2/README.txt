Kirin Hardinger
October 2022
CS 219 Fall 2022 - Project 2

How to Execute
----------------------------------------
Run "make" on a Linux environment to compile the code.
The executable will be named "proj2"
To run the executable, run the command "./proj2"

The program will prompt you for the name of the input file, including the extension, for example "Programming-Project-2.txt"
However, any file formatted as "<command> 0x 0x" will work.

About
----------------------------------------
This is a program in C++ that reads in a file of arithmetic commands and hexadecimal numbers.
As of this build, the program can read in and calculate files with commands:
    ADD
    AND
    ASR
    LSR
    LSL
    NOT
    ORR
    SUB
    XOR
The program will then output the result of the numbers in hexadecimal.

Working Process and Result
----------------------------------------
The program prompts the user for the name of the input file, including the extension.
It then parses through the file, reading in the commands and numbers.
If there is only one operand, such as the NOT command, the command is sent to a function to handle single-operand operations.
Otherwise, the command is sent to a function to handle two-operand operations.

These functions perfom the specified command and output the result to the terminal in hexadecimal.
The output is color-coded to improve readability.