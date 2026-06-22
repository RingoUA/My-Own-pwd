#include "mopwd.hpp"

#include <memory>
#include <string>
#include <cstdlib>
#include <unistd.h>

#include "free_deleter.hpp"

namespace mopwd {
    std::string get_physical_path() {
        using cwd_ptr = std::unique_ptr<char, FreeDeleter>;
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
