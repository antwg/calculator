/**
 * @file RegisterHandler.hpp
 * @author Anton Wegeström (anton.wegestrom@gmail.com)
 * @brief This is the main file of the program. It runs the main function
 * and has functions for interpreting user inputs.
 * @version 0.1
 * @date 2023-02-08
 * 
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include "RegisterHandler.hpp"

/**
 * @brief Interprets the command/arguments given and call the appropriate
 * function for each call.
 * 
 * @param registerHandler A RegisterHandler
 * @param arguments The command that is to be handled
 */
void handle_command(RegisterHandler& registerHandler, std::vector<std::string>& arguments){
    switch(arguments.size()){
        case 1:
            if (arguments[0] == "quit"){
                exit(0);
            }
            else {
                std::cout << "Invalid argument: " << arguments[0] << "\n";
            }
            break;
        case 2:
            if (arguments[0] == "print"){
                registerHandler.print(registerHandler, arguments);
            }
            else {
                std::cout << "Invalid argument: " << arguments[0] << "\n";
            }
            break;
        case 3:
            std::set<std::string> operations = {"add", "subtract", "multiply"};
            std::string operation = arguments[1];
            if (operations.find(operation) != operations.end()){
                std::string reg = arguments[0];
                std::string value = arguments[2];
                registerHandler.add_operation(reg, operation, value);
            }
            else {
                std::cout << "Invalid argument: " << arguments[1] << "\n";
            }
            break;
    }
}

/**
 * @brief Separates a line into words and places them
 * in a vector
 * 
 * @param words The line to be separated
 * @return std::vector<std::string> A vector of the words
 */
std::vector<std::string> separate_words(const std::string& words){
    std::vector<std::string> wordVect;
    std::string word = "";
    for (char letter : words){
        if (letter == ' '){
            wordVect.emplace_back(word);
            word = "";
        }
        else {
            word += std::tolower(letter);
        }
    }
    wordVect.emplace_back(word);
    return wordVect;
}

/**
 * @brief A simple calculator can take commands either from
 * a file or from the standard input.
 * 
 * Follows the form <register> <operation> <value>, 
 * print <register> or quit.
 */
int main(int argc, char *argv[]){
    RegisterHandler registerHandler;
    std::string user_input;
    if (argc == 2){ // Read from file
        std::fstream file;
        std::string fileName = argv[1];
        file.open(fileName);
        if (file.is_open()){
            while (std::getline(file, user_input)){
                std::vector<std::string> arguments = separate_words(user_input);
                handle_command(registerHandler, arguments);
            }
        }
        else{
            std::cout << "File not found\n";
        }
        file.close();
        //std::cout << "Read file: " << argv[1] << "\n";
    }
    else { // Read from standard input
        while(true){ // Ask for commands until told to quit
            std::cout << "Enter a line: "; 
            std::getline(std::cin, user_input);
            std::vector<std::string> arguments = separate_words(user_input);
            handle_command(registerHandler, arguments);
        }
    }
    return 0;
}

