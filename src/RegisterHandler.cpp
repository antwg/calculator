#include "RegisterHandler.hpp"

void RegisterHandler::add_operation(std::string reg, std::string operation, std::string value){
    registers[reg].emplace_back(std::make_pair(operation, value));
}

void RegisterHandler::print(RegisterHandler& registerHandler, std::vector<std::string>& arguments){
    std::string reg = arguments[1];
    std::cout << registerHandler.print_helper(reg) << std::endl;
}

int RegisterHandler::print_helper(std::string reg){
    int total_value = 0;
    for (auto [operation, value] : registers[reg]){
        // if value is already a number -> add it, 
        // else recurse until number calculated.
        int new_value = is_number(value) ? stoi(value) : print_helper(value);
        if (operation == "add"){
            total_value += new_value;
        }
        else if (operation == "subtract"){
            total_value -= new_value;
        }
        else if (operation == "multiply"){
            total_value *= new_value;
        }
    }
    return total_value;
}

bool RegisterHandler::is_number(const std::string& number){
    for (char digit : number){
        if (!isdigit(digit)){
            return false;
        }
    }
    return true;
}
