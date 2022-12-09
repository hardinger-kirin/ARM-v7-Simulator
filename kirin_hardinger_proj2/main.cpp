//Kirin Hardinger
//October 2022
//CS 219 Fall 2022 - Project 2

#include <iostream> //console i/o
#include <fstream> //file i/o
#include <string> //string to store command

//color-coded outputs
const std::string red("\033[0;31m"); 
const std::string green("\033[0;32m");
const std::string reset("\033[0m");

//function declarations
void fileReader();
void commandHandler_multiOperand(std::string command, uint32_t operand_1, uint32_t operand_2);
void commandHandler_singleOperand(std::string command, uint32_t operand_1);

int main() {
    fileReader();

    return 0;
}

void fileReader() {
    //initializes variables for each component: the command and both operands
    std::string command = "";
    uint32_t operand_1 = 0;
    uint32_t operand_2 = 0;

    //prompts user for input file and opens a filestream
    std::string filename = "";
    std::cout << "Please enter the name of the input file: ";
    std::cin >> filename;
    std::ifstream inputFile(filename);

    //reads the entire file and runs the ADD function if the command entered is "ADD"
    //prints the resulting sum
    while(inputFile >> command >> std::hex >> operand_1) {
        if(command == "NOT") {
            commandHandler_singleOperand(command, operand_1);
        } else {
            inputFile >> std::hex >> operand_2;
            commandHandler_multiOperand(command, operand_1, operand_2);
        }
    }

    inputFile.close();
}

void commandHandler_multiOperand(std::string command, uint32_t operand_1, uint32_t operand_2) {
    uint32_t result;
    std::string operator_str;
    bool overflow_flag = false;

    if(command == "ADD") {
        result = operand_1 + operand_2;
        operator_str = " + ";

        //accounts for overflow
        if(result < operand_1 || result < operand_2) {
            overflow_flag = true;
        }
    } else if(command == "AND") {
        operator_str = " & ";
        result = operand_1 & operand_2;
    } else if(command == "ORR") {
        operator_str = " | ";
        result = operand_1 | operand_2;
    } else if(command == "SUB") {
        operator_str = " - ";
        result = operand_1 - operand_2;
    } else if(command == "XOR") {
        operator_str = " ^ ";
        result = operand_1 ^ operand_2;
    } else if(command == "ASR") {
       (signed int)result;
        operator_str = " >> ";
        result = operand_1 >> operand_2;
    } else if(command == "LSR") {
        operator_str = " >> ";
        result = operand_1 >> operand_2;
    } else if(command == "LSL") {
        operator_str = " << ";
        result = operand_1 << operand_2;
    } 

    //Displays result
    std::cout << green << "Result of " << reset << "0x" << std::hex << operand_1 << green << operator_str << reset << "0x" << std::hex << operand_2 << " = " << red << "0x" << std::hex << result << reset;

    if(overflow_flag) {
        std::cout << " (OVERFLOW OCCURRED)";
    }

    std::cout << std::endl;
}

void commandHandler_singleOperand(std::string command, uint32_t operand_1) {
    uint32_t result;
    std::string operator_str;

    if(command == "NOT") {
        operator_str = " ~ ";
        result = ~operand_1;
    }

    std::cout << green << "Result of " << reset << "0x" << std::hex << operand_1 << green << operator_str << reset << " = " << red << "0x" << std::hex << result << reset;
    std::cout << std::endl;
}