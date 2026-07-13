#include <iostream>
#include <vector>

// #include "arg_parser.hpp"
// #include "mopwd.hpp"
// #include "help.hpp"
#include "version.hpp"

import arg_parser;
import mopwd;
import help;

void handle_error(mopwd::ParseError error) {
    switch (error) {
        case mopwd::ParseError::TooManyArguments:
            std::cerr << "Too many arguments\n";
            break;
        case mopwd::ParseError::UnknownOption:
            std::cerr << "Unknown option\n";
            break;
    }
}

void handle_command(mopwd::Command command) {
    switch (command) {
        case mopwd::Command::Help:
            std::cout << mopwd::HELP_TEXT << '\n';
            break;
        case mopwd::Command::Version:
            std::cout << mopwd::VERSION << '\n';
            break;
        case mopwd::Command::Logical:
            std::cout << mopwd::get_logical_path() << '\n';
            break;
        case mopwd::Command::Physical:
            std::cout << mopwd::get_physical_path() << '\n';
            break;
    }
}

int main(int argc, char** argv) {
    std::vector<std::string_view> args;
    args.reserve(argc > 0 ? argc - 1 : 0);

    for (int i = 1; i < argc; ++i) {
        args.emplace_back(argv[i]);
    }

    auto result = mopwd::parse_args(args);

    if (!result) {
        handle_error(result.error());
        handle_command(mopwd::Command::Help);
        return 1;
    }

    handle_command(result.value());
}
