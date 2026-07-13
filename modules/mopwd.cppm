module;

#include <string>

export module mopwd;

export namespace mopwd {
    std::string get_physical_path();

    std::string get_logical_path();
}
