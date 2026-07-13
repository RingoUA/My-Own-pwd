module;

#include <expected>
#include <span>
#include <string_view>

module arg_parser;

namespace mopwd {
    std::expected<Command, ParseError>  parse_args(std::span<const std::string_view> args) {
        if (args.empty()) {
            return Command::Logical;
        }

        if (args.size() > 1) {
            return std::unexpected(ParseError::TooManyArguments);
        }

        auto arg = args[0];

        if (arg == "-h" || arg == "--help") {
            return Command::Help;
        }
        if (arg == "-v" || arg == "--version") {
            return Command::Version;
        }
        if (arg == "-L" || arg == "--logical") {
            return Command::Logical;
        }
        if (arg == "-P" || arg == "--physical") {
            return Command::Physical;
        }

        return std::unexpected(ParseError::UnknownOption);
    }
}
