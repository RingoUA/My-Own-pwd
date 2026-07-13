module;

#include <memory>
#include <string>
#include <cstdlib>
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
    std::string get_physical_path() {
        auto path = cwd_ptr(getcwd(nullptr, 0));
        if (!path) {
            return {}; // TODO: return error details
        }
        return path.get();
    }

    std::string get_logical_path() {
        if (const char* path = std::getenv("PWD")) {
            return path;
        }
        return get_physical_path();
    }
}
