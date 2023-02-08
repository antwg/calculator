#include <vector>
#include <string>
#include <map>
#include <iostream>

std::vector<std::string> separate_words(const std::string& words);

bool is_number(const std::string& number);

int get_value(std::map<std::string, std::string>& registers, std::string& value);