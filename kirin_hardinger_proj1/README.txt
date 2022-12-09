Kirin Hardinger
September 2022
CS 219 Fall 2022 - Project 1

How to Execute
----------------------------------------
Run "make" on a Linux environment to compile the code.
The executable will be named "proj1"
To run the executable, run the command "./proj1"

The program will prompt you for the name of the input file, including the extension, for example "Programming-Project-1.txt"
However, any file formatted as "ADD 0x 0x" will work.

About
----------------------------------------
This is a program in C++ that reads in a file of arithmetic commands and hexadecimal numbers.
As of this build, the program can only read in and calculate files formatted as "ADD 0x 0x".
The program will then output the sum of the numbers in hexadecimal.

Working Process and Result
----------------------------------------
The program prompts the user for the name of the input file, including the extension.
It then parses through the file, reading in the commands and numbers.
If it finds the "ADD" command, it will add the two numbers together and output the sum.
To detect overflow, the program will check if the sum is less than either of the two operands. This is impossible unless overflow has occurred.
When this happens, the program will add "(OVERFLOW OCCURRED)" at the end of the result.