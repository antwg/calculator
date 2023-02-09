/**
 * @file RegisterHandler.hpp
 * @author Anton Wegeström (anton.wegestrom@gmail.com)
 * @brief This class acts as the registers of a calculator. It contains methods
 * for modifying values of registers and printing.
 * @version 0.1
 * @date 2023-02-08
 * 
 */

#ifndef REGISTERHANDLER
#define REGISTERHANDLER

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <set>

class RegisterHandler{
    public:
        std::set<std::string> operations = {"add", "subtract", "multiply"};

        /**
         * @brief Adds an operation and a value to a register. The operation
         * and value can later be combined to calculate a result. 
         * 
         * @param reg The register to add the operation and value to.
         * @param operation The operation to add
         * @param value The value to add
         */
        void add_operation(std::string reg, std::string operation, std::string value);

        /**
         * @brief Prints the value of the register specified in the parameter arguments.
         * 
         * @param registerHandler A RegisterHandler
         * @param arguments Contains the print keyword and the register to be printed.
         */
        void print(RegisterHandler& registerHandler, std::vector<std::string>& arguments);
    
    private:
        std::map<std::string, std::vector<std::pair<std::string, std::string>>> registers;

        /**
         * @brief Checks if a string is a number or not
         * 
         * @param number The string to check
         * @return true if it's a number
         * @return false if it's not a number
         */
        bool is_number(const std::string& number);

        /**
         * @brief Performs most of what is needed to print. Checks all the operation-value 
         * pairs and handles them accordingly. If the value is a number it can simply be
         * added/subtracted/multiplied but if value if a register, it recurses until a
         * value is calculated.
         * 
         * @param reg The register to print
         * @return int Returns the total count, used for recursion.
         */
        int print_helper(std::string reg);
};
#endif
