#ifndef ARG_PARSER_HPP
#define ARG_PARSER_HPP

#include <expected>
#include <span>
#include <string_view>

namespace mopwd {
    enum class [[nodiscard("Check error code!")]] ParseError {
        TOO_MANY_ARGUMENTS,
        UNKNOWN_OPTION
    };

    enum class Command {
        LOGICAL,
        PHYSICAL,
        HELP,
        VERSION
    };

    [[nodiscard("Check error code!")]]
    std::expected<Command, ParseError> parse_args(std::span<const std::string_view> args);
}

#endif // ARG_PARSER_HPP
