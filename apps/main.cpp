#include <morse/morse.hpp>
#include <fmt/format.h>
#include <iostream>

int
main (int argc, char* argv[]) {
    fmt::print("Hello World {} \n", Morse::greetings_message() );
    return 0;
}