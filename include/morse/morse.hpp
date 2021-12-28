#pragma once

#include <string>
#include <map>

class Morse {
public:
    static std::map<char, std::string> char_to_morse;
    static std::map<std::string, char> morse_to_char;
    static std::string greetings_message();
    static std::string to_morse(std::string message);
    static std::string from_morse(std::string morse);
private:
    static std::map<char, std::string> initialize_map();
    static std::map<std::string, char> reverse_map();
    static std::string to_upper_case(std::string message);
};