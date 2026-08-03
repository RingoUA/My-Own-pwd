module;

#include <expected>
#include <span>
#include <string_view>

export module arg_parser;

export namespace mopwd {
    enum class [[nodiscard]] ParseError {
        TooManyArguments,
        UnknownOption
    };

    enum class Command {
        Logical,
        Physical,
        Help,
        Version
    };

    [[nodiscard]]
    std::expected<Command, ParseError> parse_args(std::span<const std::string_view> args);
}
