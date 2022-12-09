Kirin Hardinger
November/December 2022
CS 219 Fall 2022 - Project 3

How to Execute
----------------------------------------
Run "make" on a Linux environment to compile the code.
The executable will be named "proj3"
To run the executable, run the command "./proj3"

The program will prompt you for the name of the input file, including the extension, for example "Programming-Project-3.txt"
However, any file formatted with commands, registers, and immediate values will work.

About
----------------------------------------
This is a program in C++ that reads in a file of commands, registers r0-r7, and hexadecimal numbers.
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
The program will then output all values stored in the registers in hexadecimal.

Working Process and Result
----------------------------------------
The program prompts the user for the name of the input file, including the extension.
It then parses through the file, reading in the commands, registers, and immediate values.
Values are sent through a function to save into the appropriate register.

These functions perfom the specified command and output the result to the terminal in hexadecimal.
The output is color-coded to improve readability.