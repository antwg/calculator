// Anton Wegeström

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

#include "help_functions.hpp"

#define DEBUG false

void print_handler(std::map<std::string, std::string>& registers, std::vector<std::string>& arguments){
    int value = get_value(registers, arguments[1]);
    if (value != -1){
        std::cout << value << "\n";
    }
}

void operation_handler(std::map<std::string, std::string>& registers, std::vector<std::string>& arguments){
    std::string reg = arguments[0];
    std::string operation = arguments[1];
    int value = get_value(registers, arguments[2]);
    if (operation == "add"){
        //registers[reg] += value;
    }
    else if (operation == "subtract") {
        //registers[reg] -= value;
    }
    else if (operation == "multiply"){
        //registers[reg] *= value;
    }
}

int main(int argc, char *argv[]){
    std::map<std::string, std::string> registers;
    std::set<std::string> operations = {"add", "subtract", "multiply"};
    if (argc == 2){ // Read from file
        #if DEBUG
        std::cout << "Read file: " << argv[1] << "\n";
        #endif
    }
    else {
        while(true){
            // Get user input
            std::string user_input;
            std::cout << "Enter a line: "; 
            std::getline(std::cin, user_input);

            std::vector<std::string> arguments = separate_words(user_input);

            switch(arguments.size()){
                case 1:
                    if (arguments[0] == "quit"){
                        return 0;
                    }
                    else {
                        std::cout << "Invalid argument: " << arguments[0] << "\n";
                    }
                    break;
                case 2:
                    if (arguments[0] == "print"){
                        print_handler(registers, arguments);
                    }
                    else {
                        std::cout << "Invalid argument: " << arguments[0] << "\n";
                    }
                    break;
                case 3:
                    std::string operation = arguments[1];
                    if (operations.find(operation) != operations.end()){
                        operation_handler(registers, arguments);
                    }
                    else {
                        std::cout << "Invalid argument: " << arguments[0] << "\n";
                    }
                    break;
            }

        }
    }
    return 0;
}
