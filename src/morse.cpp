#include <morse/morse.hpp>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <sstream>

std::vector<std::string> split (std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

std::map<char, std::string> Morse::char_to_morse = Morse::initialize_map();

std::map<std::string, char> Morse::morse_to_char = Morse::reverse_map();

std::map<char, std::string> Morse::initialize_map() {
    std::map<char, std::string> m;
    m['A'] = ".-";
    m['B'] = "-...";
    m['C'] = "-.-.";
    m['D'] = "-..";
    m['E'] = ".";
    m['F'] = "..-.";
    m['G'] = "--.";
    m['H'] = "....";
    m['I'] = "..";
    m['J'] = ".---";
    m['K'] = "-.-";
    m['L'] = ".-..";
    m['M'] = "--";
    m['N'] = "-.";
    m['O'] = "---";
    m['P'] = ".--.";
    m['Q'] = "--.-";
    m['R'] = ".-.";
    m['S'] = "...";
    m['T'] = "-";
    m['U'] = "..-";
    m['V'] = "...-";
    m['W'] = ".--";
    m['X'] = "-..-";
    m['Y'] = "-.--";
    m['Z'] = "--..";
    m['1'] = "·----";
    m['2'] = "··---";
    m['3'] = "···--";
    m['4'] = "····-";
    m['5'] = "·····";
    m['6'] = "-····";
    m['7'] = "--···";
    m['8'] = "---··";
    m['9'] = "----·";
    m['0'] = "-----";
    m['.'] = "·-·-·-";
    m[','] = "--··--";
    m['?'] = "··--··";
    m['\''] = "·----·";
    m['!'] = "-·-·--";
    m['/'] = "-··-·";
    m['('] = "-·--·";
    m[')'] = "-·--·-";
    m['&'] = "·-···";
    m[':'] = "---···";
    m[';'] = "-·-·-·";
    m['='] = "-···-";
    m['-'] = "-····-";
    m['_'] = "··--·-";
    m['"'] = "·-··-·";
    m['$'] = "···-··-";
    m['@'] = "·--·-·";
    m[' '] = " ";
    return m;
}

std::map<std::string, char> Morse::reverse_map() {
    std::map<std::string, char> m;
    for (auto it = Morse::char_to_morse.begin(); it != Morse::char_to_morse.end(); it++) {
        m[it->second] = it->first;
    }
    return m;
}

std::string Morse::to_upper_case(std::string message) {
    std::for_each(message.begin(), message.end(), [](char & c){
        c = ::toupper(c);
    });
    return message;
}

std::string Morse::greetings_message() {
    return ".... . .-.. .-.. --- --..-- / .-- --- .-. .-.. -.. -.-.--";
}

std::string Morse::to_morse(std::string message) {
    std::string upper_case_message = Morse::to_upper_case(message);

    std::string morse = "";

    for (auto &c : upper_case_message){
        morse += Morse::char_to_morse[c] + " ";
    }
    return morse;
}

std::string Morse::from_morse(std::string morse) {
    std::vector<std::string> v = split (morse, " ");
    std::string parsed = "";
    for (auto i : v) {
        if (i.empty()) {
            parsed += " "; 
        } else {
            parsed += Morse::morse_to_char[i];
        }
    }
    return parsed;
}
