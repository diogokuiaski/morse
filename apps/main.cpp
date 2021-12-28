#include <morse/morse.hpp>
#include <fmt/format.h>
#include <iostream>

int
main (int argc, char* argv[]) {
    std::string message = "Hello World";
    std::string morse = Morse::to_morse(message);
    std::string parsed_message = Morse::from_morse(morse);
    fmt::print("Message: {} \n", message );
    fmt::print("Morse: {} \n", morse );
    fmt::print("Parsed: {} \n", parsed_message );
    return 0;
}