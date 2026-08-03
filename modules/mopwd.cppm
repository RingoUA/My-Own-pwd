module;

#include <expected>
#include <string>

export module mopwd;

export namespace mopwd {
    enum class [[nodiscard]] Error {
        PathIsNull,
    };

    [[nodiscard]]
    std::expected<std::string, Error> get_physical_path();

    [[nodiscard]]
    std::expected<std::string, Error> get_logical_path();
}
