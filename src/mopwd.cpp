#include "mopwd.hpp"

#include <cstdlib>
#include <unistd.h>

std::string get_physical_path() {
    if (char* path = getcwd(nullptr, 0)) {
        std::string result(path);
        std::free(path);
        return result;
    }
    return {};
}

std::string get_logical_path() {
    if (const char* path = std::getenv("PWD")) {
        return path;
    }
    return get_physical_path();
}
