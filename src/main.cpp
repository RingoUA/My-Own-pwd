#include "mopwd.hpp"

#include <iostream> // TODO: should I use something else?

int main(int argc, char** argv) { // TODO: new arg parser
    if (argc > 2) {
        std::cerr << "To many argumentgs\n"; // TODO: error handling
        return 1;
    }
    if (argc == 1) {
        std::cout << get_logical_path() << "\n";
        return 0;
    }
    std::string_view arg = argv[1];
    if (arg == "-h" || arg == "--help") {
        std::cout << "help\n"; // TODO: help message
        return 0;
    } else if (arg == "-v" || arg == "--version") {
        std::cout << "0.1\n"; // TODO: version handling
        return 0;
    } else if (arg == "-L" || arg == "--logical") {
        std::cout << get_logical_path() << "\n";
        return 0;
    } else if (arg == "-P" || arg == "--physical") {
        std::cout << get_physical_path() << "\n";
        return 0;
    } else {
        std::cerr << "Wrong argument\n"; // TODO: error handling
    }
}
