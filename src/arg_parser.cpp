#include "arg_parser.hpp"

#include <expected>
#include <span>
#include <string_view>

namespace mopwd {
    std::expected<Command, ParseError>  parse_args(std::span<const std::string_view> args) {
        if (args.empty()) {
            return Command::LOGICAL;
        }

        if (args.size() > 1) {
            return std::unexpected(ParseError::TOO_MANY_ARGUMENTS);
        }

        auto arg = args[0];

        if (arg == "-h" || arg == "--help") {
            return Command::HELP;
        }
        if (arg == "-v" || arg == "--version") {
            return Command::VERSION;
        }
        if (arg == "-L" || arg == "--logical") {
            return Command::LOGICAL;
        }
        if (arg == "-P" || arg == "--physical") {
            return Command::PHYSICAL;
        }

        return std::unexpected(ParseError::UNKNOWN_OPTION);
    }
}
