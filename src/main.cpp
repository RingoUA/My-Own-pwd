#include "mopwd.hpp"

#include <iostream>
#include <vector>

#include "arg_parser.hpp"
#include "command.hpp"
#include "help.hpp"
#include "parse_error.hpp"
#include "version.hpp"

void handle_error(mopwd::ParseError error) {
    switch (error) {
        case mopwd::ParseError::TOO_MANY_ARGUMENTS:
            std::cerr << "Too many arguments\n";
            break;
        case mopwd::ParseError::UNKNOWN_OPTION:
            std::cerr << "Unknown option\n";
            break;
    }
}

void handle_command(mopwd::Command command) {
    switch (command) {
        case mopwd::Command::HELP:
            std::cout << mopwd::HELP_TEXT << '\n';
            break;
        case mopwd::Command::VERSION:
            std::cout << mopwd::VERSION << '\n';
            break;
        case mopwd::Command::LOGICAL:
            std::cout << mopwd::get_logical_path() << '\n';
            break;
        case mopwd::Command::PHYSICAL:
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
        return 1;
    }

    handle_command(*result);
}
