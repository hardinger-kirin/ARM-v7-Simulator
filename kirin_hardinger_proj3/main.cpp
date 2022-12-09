//Kirin Hardinger
//November/December 2022
//CS 219 Fall 2022 - Project 3

#include <iostream> //console i/o
#include <iomanip> //formatted i/o
#include <fstream> //file i/o
#include <algorithm> //std::transform for case conversion
#include <string> //commands

//color-coded outputs
const std::string red("\033[0;31m"); 
const std::string green("\033[0;32m");
const std::string reset("\033[0m");

//function declarations
void fileReader(std::string filename);
void commandHandler(std::ifstream &file, std::string command, std::string reg1);
std::string toLower(std::string phrase);
void saveRegister(std::string reg, uint32_t val);
void showRegisters();
uint32_t getVal(std::string reg);

//initialize registers r0-r7 to 0
struct registers {
    uint32_t r0 = 0;
    uint32_t r1 = 0;
    uint32_t r2 = 0;
    uint32_t r3 = 0;
    uint32_t r4 = 0;
    uint32_t r5 = 0;
    uint32_t r6 = 0;
    uint32_t r7 = 0;
};
registers reg_struct;

int main() {
    //prompts user for input file and passes it to fileReader
    std::string filename = "";
    std::cout << "Please enter the name of the input file: ";
    std::cin >> filename;
    fileReader(filename);

    return 0;
}

void fileReader(std::string filename) {
    //initialize command, first register, and filestream
    std::string command = "";
    std::string reg1;
    std::ifstream inputFile(filename);

    //reads the entire file and passes it to commandHandler to process
    while(inputFile >> command >> reg1) {
        //convert command to all lowercase
        command = toLower(command);
        reg1 = toLower(reg1);
        reg1.pop_back(); //remove ","
        commandHandler(inputFile, command, reg1);
    }

    inputFile.close();
}

void commandHandler(std::ifstream &file, std::string command, std::string reg1) {
    //rn, rm, and imm
    std::string rn = "";
    std::string rm = "";
    uint32_t imm = 0;

    char tag; //ignore "#" in input

    //select the command to run
    if(command == "mov") {
        //reads in immediate value
        file >> tag >> std::hex >> imm;

        //saves immediate value to registers struct matching reg1
        saveRegister(reg1, imm);
        std::cout << command << " " << reg1 << ", #0x" << std::hex << imm << std::endl;
    } else if(command == "add") {
        //reads in rn and rm
        file >> rn >> rm;

        //remove ","
        rn.pop_back();

        //converts rn and rm to lowercase
        rn = toLower(rn);
        rm = toLower(rm);

        saveRegister(reg1, getVal(rn) + getVal(rm));
        std::cout << command << " " << reg1 << ", " << rn << ", " << rm << std::endl;
    } else if(command == "sub") {
        //reads in rn and rm
        file >> rn >> rm;

        //remove ","
        rn.pop_back();

        //converts rn and rm to lowercase
        rn = toLower(rn);
        rm = toLower(rm);

        saveRegister(reg1, getVal(rn) - getVal(rm));
        std::cout << command << " " << reg1 << ", " << rn << ", " << rm << std::endl;
    } else if(command == "and") {
        //reads in rn and rm
        file >> rn >> rm;

        //remove ","
        rn.pop_back();

        //converts rn and rm to lowercase
        rn = toLower(rn);
        rm = toLower(rm);

        saveRegister(reg1, getVal(rn) & getVal(rm));
        std::cout << command << " " << reg1 << ", " << rn << ", " << rm << std::endl;
    } else if(command == "orr") {
        //reads in rn and rm
        file >> rn >> rm;

        //remove ","
        rn.pop_back();

        //converts rn and rm to lowercase
        rn = toLower(rn);
        rm = toLower(rm);

        saveRegister(reg1, getVal(rn) | getVal(rm));
        std::cout << command << " " << reg1 << ", " << rn << ", " << rm << std::endl;
    } else if(command == "xor") {
        //reads in rn and rm
        file >> rn >> rm;

        //remove ","
        rn.pop_back();

        //converts rn and rm to lowercase
        rn = toLower(rn);
        rm = toLower(rm);

        saveRegister(reg1, getVal(rn) ^ getVal(rm));
        std::cout << command << " " << reg1 << ", " << rn << ", " << rm << std::endl;
    } else if(command == "asr") {
        //reads in rn and immediate value
        file >> rn >> tag >> std::hex >> imm;
        rn = toLower(rn);
        rn.pop_back(); //remove ","

        //saves immediate value to registers struct matching reg1
        saveRegister(reg1, (signed int)(getVal(rn) >> imm));
        std::cout << command << " " << reg1 << ", #0x" << std::hex << imm << std::endl;
    } else if(command == "lsr") {
        //reads in rn and immediate value
        file >> rn >> tag >> std::hex >> imm;
        rn = toLower(rn);
        rn.pop_back(); //remove ","

        //saves immediate value to registers struct matching reg1
        saveRegister(reg1, getVal(rn) >> imm);
        std::cout << command << " " << reg1 << ", #0x" << std::hex << imm << std::endl;
    } else if(command == "lsl") {
        //reads in rn and immediate value
        file >> rn >> tag >> std::hex >> imm;
        rn = toLower(rn);
        rn.pop_back(); //remove ","

        //saves immediate value to registers struct matching reg1
        saveRegister(reg1, getVal(rn) << imm);
        std::cout << command << " " << reg1 << ", #0x" << std::hex << imm << std::endl;
    }

     //displays output
    showRegisters();
}

std::string toLower(std::string phrase) {
    std::transform(phrase.begin(), phrase.end(), phrase.begin(), ::tolower);
    return phrase;
}

void saveRegister(std::string reg, uint32_t val) {
    if(reg == "r0") {
        reg_struct.r0 = val;
    } else if(reg == "r1") {
        reg_struct.r1 = val;
    } else if(reg == "r2") {
        reg_struct.r2 = val;
    } else if(reg == "r3") {
        reg_struct.r3 = val;
    } else if(reg == "r4") {
        reg_struct.r4 = val;
    } else if(reg == "r5") {
        reg_struct.r5 = val;
    } else if(reg == "r6") {
        reg_struct.r6 = val;
    } else if(reg == "r7") {
        reg_struct.r7 = val;
    }
}

void showRegisters() {
    std::cout.setf(std::ios::left);
    std::cout << green << "  > r0: 0x" << std::setw(8) << std::hex << reg_struct.r0;
    std::cout << "     r1: 0x" << std::setw(8) << std::hex << reg_struct.r1;
    std::cout << "     r2: 0x" << std::setw(8) << std::hex << reg_struct.r2;
    std::cout << "     r3: 0x" << std::setw(8) << std::hex << reg_struct.r3 << reset << std::endl;

    std::cout.setf(std::ios::left);
    std::cout << green << "  > r4: 0x" << std::setw(8) << std::hex << reg_struct.r4;
    std::cout << "     r5: 0x" << std::setw(8) << std::hex << reg_struct.r5;
    std::cout << "     r6: 0x" << std::setw(8) << std::hex << reg_struct.r6;
    std::cout << "     r7: 0x" << std::setw(8) << std::hex << reg_struct.r7 << reset << std::endl;
}

uint32_t getVal(std::string reg) {
    //returns value stored in register struct at reg
    if(reg == "r0") {
        return reg_struct.r0;
    } else if(reg == "r1") {
        return reg_struct.r1;
    } else if(reg == "r2") {
        return reg_struct.r2;
    } else if(reg == "r3") {
        return reg_struct.r3;
    } else if(reg == "r4") {
        return reg_struct.r4;
    } else if(reg == "r5") {
        return reg_struct.r5;
    } else if(reg == "r6") {
        return reg_struct.r6;
    } else if(reg == "r7") {
        return reg_struct.r7;
    } else {
        return 0;
    }
}