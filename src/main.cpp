#include "mopwd.hpp"

#include <iostream>

#include "arg_parser.hpp"
#include "command.hpp"
#include "help.hpp"
#include "version.hpp"

int main(int argc, char** argv) {
    auto command = mopwd::parse_args(argc, argv);
    if (argc > 2) {
        std::cerr << "To many argumentgs\n"; // TODO: error handling
        return 1;
    }
    std::string result;
    switch (command) {
        case mopwd::Command::HELP:
            result = mopwd::HELP_TEXT;
            break;
        case mopwd::Command::VERSION:
            result = mopwd::VERSION;
            break;
        case mopwd::Command::LOGICAL:
            result = mopwd::get_logical_path();
            break;
        case mopwd::Command::PHYSICAL:
            result = mopwd::get_physical_path();
            break;
    }
    std::cout << result << "\n";
}
