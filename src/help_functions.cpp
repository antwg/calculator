#include "help_functions.hpp"

std::vector<std::string> separate_words(const std::string& words){
    std::vector<std::string> word_vect;
    std::string word = "";
    for (char letter : words){
        if (letter == ' '){
            word_vect.emplace_back(word);
            word = "";
        }
        else {
            word += std::tolower(letter);
        }
    }
    word_vect.emplace_back(word);
    return word_vect;
}

bool is_number(const std::string& number){
    for (char digit : number){
        if (!isdigit(digit)){
            return false;
        }
    }
    return true;
}

int get_value(std::map<std::string, std::string>& registers, std::string& value){
    if (is_number(value)){
        return std::stoi(value);
    }
    else if (registers.count(value) > 0){
        if (is_number(value)){
            return stoi(registers.find(value)->second);
        }
    }
    return -1;
}

