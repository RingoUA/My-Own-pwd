#pragma once

#include <expected>
#include <span>
#include <string_view>

#include "command.hpp"
#include "parse_error.hpp"


namespace mopwd {
    std::expected<Command, ParseError> parse_args(std::span<const std::string_view> args);
}
