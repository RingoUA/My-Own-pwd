module;

#include <cstdlib>
#include <expected>
#include <memory>
#include <string>
#include <unistd.h>

module mopwd;

namespace {
    struct FreeDeleter {
        void operator()(char* ptr) const noexcept {
            std::free(ptr);
        }
    };

    using cwd_ptr = std::unique_ptr<char, FreeDeleter>;
}

namespace mopwd {
    std::expected<std::string, Error> get_physical_path() {
        auto path = cwd_ptr(getcwd(nullptr, 0));
        if (!path) {
            return std::unexpected(Error::PathIsNull);
        }
        return path.get();
    }

    std::expected<std::string, Error> get_logical_path() {
        if (const char* path = std::getenv("PWD")) {
            return path;
        }
        return get_physical_path();
    }
}
