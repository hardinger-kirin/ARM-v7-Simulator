//Kirin Hardinger
//September 2022
//CS 219 Fall 2022 - Project 1

#include <iostream> //console i/o
#include <fstream> //file i/o
#include <string> //string to store command

//function declarations
void fileReader();
uint32_t add(const uint32_t operand_1, const uint32_t operand_2);

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
    while(inputFile >> command >> std::hex >> operand_1 >> std::hex >> operand_2) {
        if(command == "ADD") {
            uint32_t result = add(operand_1, operand_2);

            std::cout << "Result of " << "0x" << std::hex << operand_1 << " + " << "0x" << std::hex << operand_2 << " = " << "0x" << std::hex << result;

            //accounts for overflow
            if(result < operand_1 || result < operand_2) {
                std::cout << " (OVERFLOW OCCURRED)";
            }

            std::cout << std::endl;
        }
    }

    inputFile.close();
}

uint32_t add(const uint32_t operand_1, const uint32_t operand_2) {
    return operand_1 + operand_2;
}