module;

#include <expected>
#include <span>
#include <string_view>

export module arg_parser;

export namespace mopwd {
    enum class [[nodiscard("Check error code!")]] ParseError {
        TooManyArguments,
        UnknownOption
    };

    enum class Command {
        Logical,
        Physical,
        Help,
        Version
    };

    [[nodiscard("Check error code!")]]
    std::expected<Command, ParseError> parse_args(std::span<const std::string_view> args);
}
