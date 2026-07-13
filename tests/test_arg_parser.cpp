#include <array>
#include <string_view>

#include <catch2/catch_test_macros.hpp>

import arg_parser;

TEST_CASE("No arguments means logical mode")
{
    auto result = mopwd::parse_args(
        std::array<std::string_view, 0>{}
    );

    REQUIRE(result);
    REQUIRE(*result == mopwd::Command::Logical);
}

TEST_CASE("Parse -L like logical mode")
{
    auto result = mopwd::parse_args(
        std::array{
            std::string_view{"-L"}
        }
    );

    REQUIRE(result);
    REQUIRE(*result == mopwd::Command::Logical);
}

TEST_CASE("Parse --logical like logical mode")
{
    auto result = mopwd::parse_args(
        std::array{
            std::string_view{"--logical"}
        }
    );

    REQUIRE(result);
    REQUIRE(*result == mopwd::Command::Logical);
}

TEST_CASE("Parse -P like physical mode")
{
    auto result = mopwd::parse_args(
        std::array{
            std::string_view{"-P"}
        }
    );

    REQUIRE(result);
    REQUIRE(*result == mopwd::Command::Physical);
}

TEST_CASE("Parse --physical like physical mode")
{
    auto result = mopwd::parse_args(
        std::array{
            std::string_view{"--physical"}
        }
    );

    REQUIRE(result);
    REQUIRE(*result == mopwd::Command::Physical);
}

TEST_CASE("Unknown option")
{
    auto result = mopwd::parse_args(
        std::array{
            std::string_view{"--unknown"}
        }
    );

    REQUIRE_FALSE(result);
    REQUIRE(result.error() == mopwd::ParseError::UnknownOption);
}

TEST_CASE("Too many arguments")
{
    auto result = mopwd::parse_args(
        std::array{
            std::string_view{"-P"},
            std::string_view{"-L"}
        }
    );

    REQUIRE_FALSE(result);
    REQUIRE(result.error() == mopwd::ParseError::TooManyArguments);
}
