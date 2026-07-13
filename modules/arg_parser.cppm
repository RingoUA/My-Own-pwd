module;

#include <expected>
#include <span>
#include <string_view>

export module arg_parser;

export namespace mopwd {
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
